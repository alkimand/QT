#include <BaseClientAPIClass/BaseClientAPIClass.h>

bool BaseClientAPI::BaseClientAPIClass::oauth(const CoomonClientAPIDefs::callback_func_cap handler) {
        return false;
}

BaseClientAPI::BaseClientAPIClass::BaseClientAPIClass(const std::string _version,
    const CoomonClientAPIDefs::string _lang,
    const CoomonClientAPIDefs::callback_func_cap cap_callback,
    const CoomonClientAPIDefs::callback_func_fa2 _fa2_callback) :
    captcha_callback(cap_callback),
    fa2_callback(_fa2_callback),
    version(_version), lang(_lang) {
    this->BaseClassHref = this;
}


CoomonClientAPIDefs::string BaseClientAPI::BaseClientAPIClass::access_token() const {
    return a_t;
}

CoomonClientAPIDefs::string BaseClientAPI::BaseClientAPIClass::last_error() const {
    return l_error;
}


CoomonClientAPIDefs::string BaseClientAPI::BaseClientAPIClass::get_captcha_key(const CoomonClientAPIDefs::string &captcha_sid) {
    return (captcha_callback != nullptr) ? captcha_callback(captcha_sid) : "";
}

CoomonClientAPIDefs::string BaseClientAPI::BaseClientAPIClass::get_fa2_code() {
    return (fa2_callback != nullptr) ? fa2_callback() : "";
}

bool BaseClientAPI::BaseClientAPIClass::check_access() {
    bool result = false;
    return result;
}

bool BaseClientAPI::BaseClientAPIClass::auth(const CoomonClientAPIDefs::string &login, const CoomonClientAPIDefs::string &pass,
    const CoomonClientAPIDefs::string &access_token) {

    return false;
}

CoomonClientAPIDefs::json BaseClientAPI::BaseClientAPIClass::call(const CoomonClientAPIDefs::string &method, const CoomonClientAPIDefs::string &params) {
    return nullptr;
}

void BaseClientAPI::BaseClientAPIClass::clear() {
}

CoomonClientAPIDefs::string BaseClientAPI::BaseClientAPIClass::first_name() const {
    return  user.first_name;
}

CoomonClientAPIDefs::string BaseClientAPI::BaseClientAPIClass::last_name() const {
    return  user.last_name;
}

size_t BaseClientAPI::BaseClientAPIClass::user_id() const {
    return user.user_id;
}

void BaseClientAPI::BaseClientAPIClass::set_fa2_callback(const CoomonClientAPIDefs::callback_func_fa2 _fa2_callback) {
    fa2_callback = _fa2_callback;
}

void BaseClientAPI::BaseClientAPIClass::set_cap_callback(const CoomonClientAPIDefs::callback_func_cap cap_callback) {
    captcha_callback = cap_callback;
}

CoomonClientAPIDefs::json BaseClientAPI::BaseClientAPIClass::call(const CoomonClientAPIDefs::string &method, const CoomonClientAPIDefs::params_map &params) {
    if (method.empty()) {
        return nullptr;
    }

    CoomonClientAPIDefs::string data;
    if (params.size()) {
        data = BaseClientAPI::Utils::data2str(params);
    }

    return this->call(method, data);
}

CoomonClientAPIDefs::string BaseClientAPI::Utils::char2hex(const char dec) {
    char dig1 = (dec & 0xF0) >> 4;
    char dig2 = (dec & 0x0F);

    if (0 <= dig1 && dig1 <= 9) dig1 += 48;
    if (10 <= dig1 && dig1 <= 15) dig1 += 87;
    if (0 <= dig2 && dig2 <= 9) dig2 += 48;
    if (10 <= dig2 && dig2 <= 15) dig2 += 87;

    CoomonClientAPIDefs::string r;
    r.append(&dig1, 1);
    r.append(&dig2, 1);
    return r;
}

CoomonClientAPIDefs::string BaseClientAPI::Utils::urlencode(const CoomonClientAPIDefs::string &url) {

    CoomonClientAPIDefs::string escaped;
    for (const char& c : url) {
        if ((48 <= c && c <= 57) ||
            (65 <= c && c <= 90) ||
            (97 <= c && c <= 122) ||
            (c == '~' || c == '!' || c == '*' || c == '(' || c == ')' || c == '\'')
            ) {
            escaped.append(&c, 1);
        }
        else {
            escaped.append("%");
            escaped.append(char2hex(c));
        }
    }

    return escaped;
}

CoomonClientAPIDefs::string BaseClientAPI::Utils::data2str(const CoomonClientAPIDefs::params_map &data) {
    CoomonClientAPIDefs::string result;
    for (auto &kv : data) {
        result += kv.first + "=" + urlencode(kv.second) + "&";
    }

    return result;
}


int BaseClientAPI::Utils::CURL_WRITER(char *data, size_t size, size_t nmemb, CoomonClientAPIDefs::string *buffer) {
    int result = 0;
    if (buffer != NULL) {
        buffer->append(data, size * nmemb);
        result = size * nmemb;
    }

    return result;
}

CoomonClientAPIDefs::string BaseClientAPI::BaseClientAPIClass::request(const CoomonClientAPIDefs::string &url, const CoomonClientAPIDefs::string &data) {
    return DEFAULTAPIDATA;
}