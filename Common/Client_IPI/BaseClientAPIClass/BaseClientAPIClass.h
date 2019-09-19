#ifndef BASECLIENTAPI
#define BASECLIENTAPI
#include <JSON/json.hpp>
#include <Attachment/BaseAttachment.h>
#include <BaseClientAPIClass/CommonClientAPIDefs.h>
#include <curl/curl.h>

#include <string>
#include <unordered_map>
#include <vector>


namespace BaseClientAPI {

    using params_map = std::map<std::string, std::string>; //unordered_map

    class BaseClientAPIClass
    {
    private:

        /* http params */
        static const std::string app_id;
        static const std::string app_secret;
        static const std::string scope;
        static const std::string auth_url;
        static const std::string api_url;

        //using CoomonClientAPIDefs::callback_func_cap = std::string(*)(const std::string &);
        //using callback_func_fa2 = std::string(*)();
        using json = nlohmann::json;
        

        std::string a_t;
        std::string captcha_sid;
        std::string captcha_key;
        std::string fa2_code;
        std::string l_error;

        CoomonClientAPIDefs::callback_func_cap captcha_callback = nullptr;
        CoomonClientAPIDefs::callback_func_fa2 fa2_callback = nullptr;

        inline std::string get_captcha_key(const std::string &captcha_sid);
        inline std::string get_fa2_code();

        std::string curl_buffer;

    protected:
        std::string version;
        std::string lang;
        Attachment::User user;
        virtual bool check_access();
        virtual std::string request(const std::string &url, const std::string &data);

    public:

        BaseClientAPIClass(const std::string _version = "5.65",
            const std::string _lang = "en",
            const CoomonClientAPIDefs::callback_func_cap cap_callback = nullptr,
            const CoomonClientAPIDefs::callback_func_fa2 _fa2_callback = nullptr);

        virtual bool auth(const std::string &login, const std::string &pass,
            const std::string &access_token = "");

        virtual bool oauth(const CoomonClientAPIDefs::callback_func_cap handler);

        virtual json call(const std::string &method, const params_map &params);

        virtual json call(const std::string &method, const std::string &params = "");

        virtual void clear();

        virtual std::string first_name() const;
        virtual std::string last_name() const;
        virtual size_t user_id() const;

        virtual std::string access_token() const;
        virtual std::string last_error() const;

        virtual void set_fa2_callback(const CoomonClientAPIDefs::callback_func_fa2 _fa2_callback = nullptr);
        virtual void set_cap_callback(const CoomonClientAPIDefs::callback_func_cap cap_callback = nullptr);

        virtual ~BaseClientAPIClass() {}
    };

    class Utils {
    public:
        static std::string data2str(const params_map &data);
        static std::string urlencode(const std::string &url);
        static std::string char2hex(const char dec);
        static int CURL_WRITER(char *data, size_t size, size_t nmemb, std::string *buffer);
    };


}
#endif // BASEBaseClientAPIClassAPICLASS
