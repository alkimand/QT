﻿
#include <iostream>
#include <curl/curl.h>
#include <BaseClientAPIClass/BaseClientAPIClass.h>

using json = ::nlohmann::json;
using namespace std;


string fa2_callback() {
    string res;
    cout << "Enter 2fa code: ";
    cin >> res;
    return res;
}

string captcha_callback(const string &captcha_sid) {
    string res;
    cout << "Open image https://api.vk.com/captcha.php?sid=" << captcha_sid;
    cout << " and enter text: " << endl;
    cin >> res;
    return res;
}

void print_man() {
    cout << "Usage: [access_token] login pass" << endl;
}

string upload_file(const string &url, const string &parameter_name, const string &path) {

    struct curl_httppost *formpost = nullptr;
    struct curl_httppost *lastptr = nullptr;


    CURL *curl = curl_easy_init();
    if (!curl)
        return "";

    static char errorBuffer[CURL_ERROR_SIZE];
    string curl_buffer;

    curl_formadd(&formpost,
        &lastptr,
        CURLFORM_COPYNAME, parameter_name.c_str(),
        CURLFORM_FILE, path.c_str(),
        CURLFORM_END);
    curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "VK API Client");
    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_HTTPPOST, formpost);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, BaseClientAPI::Utils::CURL_WRITER);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curl_buffer);

    CURLcode result = curl_easy_perform(curl);
    curl_easy_cleanup(curl);
    curl_formfree(formpost);
    if (result == CURLE_OK) {

        json jres = result;

        return curl_buffer;
    }
    else {
        return errorBuffer;
    }
}

int main(int argc, char *argv[]) {

    const string peer_id = "100";
    const string graffiti_file_path = "Add_cont.png";
    string access_token, login, pass;
    access_token = "8a4d39180b6bc56188e4a9711caf33fffc68952feaba06071243f7013fa9fe66d43c0c97575a6aa306569";
    login = "+79081674177";
    pass = "qwertyop1";
    BaseClientAPI::BaseClientAPIClass api;
    api.set_fa2_callback(fa2_callback);
    api.set_cap_callback(captcha_callback);
    if (api.auth(login, pass, access_token)) {
        cout << "Auth ok" << endl;
        cout << "Access token: " << api.access_token() << endl;

        BaseClientAPI::params_map params = {
            {"peer_id", peer_id},
            {"type", "graffiti"}
        };
        cout << "API response: " << endl;
        json jres = api.call("docs.getMessagesUploadServer", params);

        cout << jres << endl;

        if (jres.find("error") != jres.end()) {
            return -1;
        }

        string upload_result;

        try {
            json response = jres.at("response").get<json>();
            string upload_url = response.at("upload_url").get<string>();
            if (upload_url.empty())
                return -2;

            cout << upload_url << endl;

            upload_result = upload_file(upload_url, "file", graffiti_file_path);

            if (upload_result.empty()) {
                return -3;
            }

            cout << upload_result << endl;
        }
        catch (...) {
            return -4;
        }
        try {
            jres = json::parse(upload_result);

            if (jres.find("error") != jres.end()) {
                return -5;
            }
            params = {
                {"file", jres.at("file").get<string>()},
                {"title", "graffiti"}
            };

            jres = api.call("docs.save", params);

            cout << jres << endl;

            if (jres.find("error") != jres.end()) {
                return -6;
            }

            jres = jres.at("response").get<json>();
            jres = jres.begin().value();
            string attachment = "doc" + to_string(jres.at("owner_id").get<int>())
                + "_" +
                to_string(jres.at("id").get<int>());
            params = {
                {"peer_id", peer_id},
                {"attachment", attachment}
            };

            jres = api.call("messages.send", params);

            cout << jres << endl;
        }
        catch (...) {
            return -7;
        }
    }
    else {
        cout << "Auth fail: " << api.last_error() << endl;
        return -1;
    }

    return 0;
}

