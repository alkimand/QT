#include <string>
#include "messages.h"

using std::string;

bool BaseClientAPI::DialogInfo::parse(const json &data) {
    if(data == nullptr) {
        return false;
    }

    try {

        this->title = data.at("title").get<string>();
        if(this->title == " ... " || this->title.empty()) {
            this->title = "";
        }
        this->body = data.at("body").get<string>();
        if(data.find("chat_id") != data.end()) {
            this->chat_id = data.at("chat_id").get<int>() + chat_offset;
            this->is_chat = true;
        } else {
            this->chat_id = data.at("user_id").get<int>();
            this->is_chat = false;
        }
        if(body.empty()) {
            body = "...";
        }
        return true;
    }
    catch(...) {

    }

    return false;
}

BaseClientAPI::vector_dialogs BaseClientAPI::Messages::get_dialogs(const size_t count, const size_t offset) {
    BaseClientAPI::vector_dialogs res;

    if(count == 0 || count > 200) {
        return std::move(res);
    }

    BaseClientAPI::params_map params = {
        {"count", std::to_string(count)},
        {"offset", std::to_string(offset)},
        {"preview_length", "1"},

    };

    json jres = call("messages.getDialogs", params);
    if(jres == nullptr) {
        return std::move(res);
    }

    if(jres.find("error") == jres.end()) {

        json items = jres.at("response").get<json>().at("items").get<json>();

        for (json::iterator it = items.begin(); it != items.end(); ++it) {
            json item = it.value();
            if(item.find("message") == item.end())
                continue;
            item = item.at("message").get<json>();
            BaseClientAPI::DialogInfo dialog;
            if(dialog.parse(item)) {

                if(dialog.title.empty()) {
                    dialog.title = (dialog.is_chat) ?
                                get_chat_title(dialog.chat_id) : get_username(dialog.chat_id);
                }

                res.push_back(std::move(dialog));
            }
        }
    }

    return std::move(res);
}

BaseClientAPI::vector_dialogs BaseClientAPI::Messages::get_all_dialogs(const size_t max_count) {
    const size_t count = (max_count > 200 || max_count < 1) ? 200 : max_count;
    BaseClientAPI::vector_dialogs all_res, tmp_res;
    size_t offset = 0;
    for(;;) {
        tmp_res = this->get_dialogs(count, offset);
        if(tmp_res.size() < 1) {
            break;
        }
        std::move(tmp_res.begin(), tmp_res.end(), std::back_inserter(all_res));
        offset += count;
        if(max_count > 0 && max_count <= all_res.size()) {
            break;
        }
    }

    return std::move(all_res);
}

std::string BaseClientAPI::Messages::get_chat_title(const int chat_id) {


    if(chat_id < chat_offset) {
        return "";
    }
    BaseClientAPI::params_map params = {
        {"chat_ids", std::to_string(chat_id - chat_offset)},
    };

    json jres = call("messages.getChat", params);
    if(jres == nullptr || jres.find("error") != jres.end()) {
        return "";
    }
    json info = jres.at("response").get<json>();
    info = info.begin().value();
    string tmp = info.at("title").get<string>();
    return tmp;
}

std::string BaseClientAPI::Messages::get_username(const int user_id) {
    BaseClientAPI::params_map params = {
        {"user_ids", std::to_string(user_id)},
    };

    json jres = call("users.get", params);
    if(jres == nullptr || jres.find("error") != jres.end()) {
        return "";
    }
    BaseClientAPI::Attachment::User user;
    json info = jres.at("response").get<json>();
    if(info.begin() == info.end()) {
        return "";
    }
    info = info.begin().value();
    user.parse(info);
    return user.first_name + " " + user.last_name;
}

template<typename T>
std::vector<T> BaseClientAPI::Messages::get_attachments(const int chat_id, const size_t count) {
    std::vector<T> res;
    size_t real_count = (count > 200 || count < 1) ? 200 : count;
    string next;
    BaseClientAPI::params_map params = {
        {"peer_id", std::to_string(chat_id)},
        {"media_type", T::type},
        {"start_from", next},
        {"count", std::to_string(real_count)}
    };

    try {
        for(;;) {
            json jres = call("messages.getHistoryAttachments", params);
            if(jres == nullptr) {
                return std::move(res);
            }

            size_t parsed = 0;
            if(jres.find("error") == jres.end()) {

                next = jres.at("response").get<json>().at("next_from").get<string>();

                json items = jres.at("response").get<json>().at("items").get<json>();

                for (json::iterator it = items.begin(); it != items.end(); ++it) {
                    json item = it.value();
                    if(item.find("attachment") == item.end())
                        continue;
                    item = item.at("attachment").get<json>();
                    T att;
                    if(att.parse(item)) {
                        res.push_back(std::move(att));
                        parsed++;
                    }
                }
            }

            if((count == 0 && next.empty())
                    || (count > 0 && res.size() >= count)
                    || (parsed < 1)) {
                break;
            }

            params["start_from"] = next;

        }
    }
    catch(...) {

    }

    return std::move(res);
}


template std::vector<BaseClientAPI::Attachment::Audio>
BaseClientAPI::Messages::get_attachments<BaseClientAPI::Attachment::Audio>(const int , const size_t);

template std::vector<BaseClientAPI::Attachment::Photo>
BaseClientAPI::Messages::get_attachments<BaseClientAPI::Attachment::Photo>(const int , const size_t);

template std::vector<BaseClientAPI::Attachment::Document>
BaseClientAPI::Messages::get_attachments<BaseClientAPI::Attachment::Document>(const int , const size_t);

