#include <BaseClientAPIClass/ClientAPIClass_VK.h>
#include <BaseClientAPIClass/VKClientAPIDefs.h>

BaseClientAPI::ClientAPIClass_VK::ClientAPIClass_VK(const CoomonClientAPIDefs::string _version,
    const CoomonClientAPIDefs::string _lang,
    const CoomonClientAPIDefs::callback_func_cap cap_callback,
    const CoomonClientAPIDefs::callback_func_fa2 _fa2_callback) 
    :BaseClientAPIClass(_version, _lang, cap_callback, _fa2_callback) {

    this->api_url = CoomonClientAPIDefs::string(VKMETHOD_URL);
    this->app_id = "3140623";//"3140623";// android=2274003 //"7131946";
    this->app_secret = "VeWdmVclDCtn6ihuP1nt";// android=hHbZxrka2uZ6jB1inYsH
    this->scope = CoomonClientAPIDefs::string(VKGOUPSCOPE);//"offline,groups,messages,friends,audio,docs";
    this->auth_url = CoomonClientAPIDefs::string(VKAUTHURL);//"https://oauth.vk.com/token?";
}


CoomonClientAPIDefs::string BaseClientAPI::ClientAPIClass_VK::access_token() const {
    return a_t;
}

CoomonClientAPIDefs::string BaseClientAPI::ClientAPIClass_VK::last_error() const {
    return l_error;
}


CoomonClientAPIDefs::string BaseClientAPI::ClientAPIClass_VK::get_captcha_key(const CoomonClientAPIDefs::string &captcha_sid) {
    return (captcha_callback != nullptr) ? captcha_callback(captcha_sid) : "";
}

CoomonClientAPIDefs::string BaseClientAPI::ClientAPIClass_VK::get_fa2_code() {
    return (fa2_callback != nullptr) ? fa2_callback() : "";
}

bool BaseClientAPI::ClientAPIClass_VK::check_access() {
    CoomonClientAPIDefs::json jres = call(CoomonClientAPIDefs::string(VKMETHOD_USERSGET), "");
    if (jres.find("error") != jres.end()) {
        this->clear();
        return false;
    }
    try {
        CoomonClientAPIDefs::json info = jres.at("response").get<json>();
        info = info.begin().value();
         user.parse(info);
    }
    catch (...) {
        this->clear();
        return false;
    }

    return true;
}

//bool BaseClientAPI::ClientAPIClass_VK::oauth(const CoomonClientAPIDefs::callback_func_cap handler) {
    bool BaseClientAPI::ClientAPIClass_VK::oauth(const CoomonClientAPIDefs::string &login, const CoomonClientAPIDefs::string &pass ) {
    //if (handler == nullptr) {
    //    return false;
    //}

    this->clear();

    CoomonClientAPIDefs::string oauth_url = VKAUTHURL_2;
   
    CoomonClientAPIDefs::params_map params = {
        {"client_id", this->app_id},
        {"display", "mobile"},//mobile page
        {"redirect_uri", VKDEFAULTRDEDIRECTURL},
        {"scope", this->scope},
        {"response_type", "code"},//code//token
        {"v", this->version},
        {"state", "test"},
    };

    //oauth_url += Utils::data2str(params);
    CoomonClientAPIDefs::string data = BaseClientAPI::Utils::data2str(params);
    CoomonClientAPIDefs::string blank = request(oauth_url, data);

    //CoomonClientAPIDefs::string res = request(auth_url, data);
    if (blank.empty()) {
        return false;
    }

    auto it = blank.find("=");
    if (it == CoomonClientAPIDefs::string::npos) {
        return false;
    }
    it++;
    this->a_t = blank.substr(it);

    it = this->a_t.find("&expires_in");
    if (it == CoomonClientAPIDefs::string::npos) {
        this->clear();
        return false;
    }
    this->a_t = a_t.substr(0, it);

    return !this->a_t.empty();

}

bool BaseClientAPI::ClientAPIClass_VK::auth(const CoomonClientAPIDefs::string &login, const CoomonClientAPIDefs::string &pass,
    const CoomonClientAPIDefs::string &access_token) {
    if (!access_token.empty()) {
        this->a_t = access_token;
        if (check_access()) {
            return true;
        }
    }
    this->a_t.clear();

    if (login.empty() || pass.empty()) {
        return false;
    }

    CoomonClientAPIDefs::params_map params = {
        {"client_id", app_id},
        {"grant_type", "password"},
        {"client_secret", app_secret},
        {"scope", scope},
        {"username", login},
        {"password", pass},
    };

    if (!captcha_sid.empty()) {
        params.insert({ "captcha_sid", captcha_sid });
        params.insert({ "captcha_key", captcha_key });
    }

    if (fa2_callback != nullptr) {
        params.insert({ "2fa_supported", "1" });
    }

    if (!fa2_code.empty()) {
        params.insert({ "code", fa2_code });
    }

    CoomonClientAPIDefs::string data = BaseClientAPI::Utils::data2str(params);
    captcha_sid.clear();
    captcha_key.clear();
    fa2_code.clear();

    CoomonClientAPIDefs::string res = request(auth_url, data);
    if (res.empty()) {
        return false;
    }

    try {
        json jres = json::parse(res);
        if (jres.find("error") == jres.end() ||
            jres.find("access_token") != jres.end()) {

           this->a_t = jres.at("access_token").get<CoomonClientAPIDefs::string>();
           this->user.user_id = jres.at("user_id").get<size_t>();

            return check_access();
        }

        this->l_error = jres.at("error").get<CoomonClientAPIDefs::string>();

        if (this->l_error == "invalid_BaseClientAPIClass" || this->l_error == "invalid_request") {
            return false;
        }
        else if (this->l_error == "need_validation") {

            fa2_code = get_fa2_code();
            if (!fa2_code.empty()) {
                return this->auth(login, pass);
            }

        }
        else if (this->l_error == "need_captcha") {

            captcha_sid = jres.at("captcha_sid").get<CoomonClientAPIDefs::string>();
            captcha_key = get_captcha_key(captcha_sid);
            if (!captcha_key.empty()) {
                return this->auth(login, pass);
            }

        }

    }
    catch (...) {

    }

    return false;
}

CoomonClientAPIDefs::json BaseClientAPI::ClientAPIClass_VK::call(const CoomonClientAPIDefs::string &method, const CoomonClientAPIDefs::string &params) {
    if (method.empty()) {
        return nullptr;
    }
    CoomonClientAPIDefs::string url = api_url + method;
    CoomonClientAPIDefs::string data = params + ((params.empty()) ? "" : "&");

    CoomonClientAPIDefs::params_map tmp_params;
    if (!captcha_sid.empty()) {
        tmp_params.insert({ "captcha_sid", captcha_sid });
        tmp_params.insert({ "captcha_key", captcha_key });
    }
    tmp_params.insert({ "v", version });
    tmp_params.insert({ "lang", lang });
    if (!a_t.empty()) {
        tmp_params.insert({ "access_token", a_t });
    }

    data += BaseClientAPI::Utils::data2str(tmp_params);
    captcha_sid.clear();
    captcha_key.clear();

    CoomonClientAPIDefs::string res = request(url, data);
    if (res.empty()) {
        return nullptr;
    }

    try {
        CoomonClientAPIDefs::json jres = json::parse(res);

        if (jres.find("error") == jres.end()) {
            return jres;
        }

        CoomonClientAPIDefs::json item = jres.at("error").get<json>();
        this->l_error = item.at("error_msg").get<CoomonClientAPIDefs::string>();

        if (this->l_error == "need_captcha") {
            captcha_sid = item.at("captcha_sid").get<CoomonClientAPIDefs::string>();
            captcha_key = get_captcha_key(captcha_sid);
            if (!captcha_key.empty()) {
                return this->call(method, params);
            }
        }

        return jres;
    }
    catch (...) {

    }

    return nullptr;
}

void BaseClientAPI::ClientAPIClass_VK::clear() {
    a_t.clear();
    user.first_name.clear();
    user.last_name.clear();
    user.user_id = 0;

    captcha_sid.clear();
    captcha_key.clear();
    fa2_code.clear();
}

CoomonClientAPIDefs::string BaseClientAPI::ClientAPIClass_VK::first_name() const {
    return "";user.first_name;
}

CoomonClientAPIDefs::string BaseClientAPI::ClientAPIClass_VK::last_name() const {
    return "";user.last_name;
}

size_t BaseClientAPI::ClientAPIClass_VK::user_id() const {
    return 100;user.user_id;
}

CoomonClientAPIDefs::json BaseClientAPI::ClientAPIClass_VK::call(const CoomonClientAPIDefs::string &method, const CoomonClientAPIDefs::params_map &params) {
    if (method.empty()) {
        return nullptr;
    }

    CoomonClientAPIDefs::string data;
    if (params.size()) {
        data = BaseClientAPI::Utils::data2str(params);
    }

    return this->call(method, data);
}


CoomonClientAPIDefs::string BaseClientAPI::ClientAPIClass_VK::request(const CoomonClientAPIDefs::string &url, const CoomonClientAPIDefs::string &data) {
    static char errorBuffer[CURL_ERROR_SIZE];
    curl_buffer.clear();

    CURL *curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, errorBuffer);
        //header('Content-Type: text/html; charset=utf-8');
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "VK API BaseClientAPIClass");
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        //curl_easy_setopt(curl, CURLOPT_RETURNTRANSFER, true);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, data.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, BaseClientAPI::Utils::CURL_WRITER);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &curl_buffer);

        CURLcode result = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        if (result == CURLE_OK) {
            //json test = result;
            return curl_buffer;

        }
        else {
            return errorBuffer;
        }
    }
    curl_easy_cleanup(curl);

    return "";
}