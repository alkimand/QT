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

    

    class BaseClientAPIClass
    {

    //private:

    protected:
        //fields
        CoomonClientAPIDefs::string app_id;
        CoomonClientAPIDefs::string app_secret;
        CoomonClientAPIDefs::string scope;
        CoomonClientAPIDefs::string auth_url;
        CoomonClientAPIDefs::string api_url;

        CoomonClientAPIDefs::string a_t;
        CoomonClientAPIDefs::string captcha_sid;
        CoomonClientAPIDefs::string captcha_key;
        CoomonClientAPIDefs::string fa2_code;
        CoomonClientAPIDefs::string l_error;

        BaseClientAPIClass *BaseClassHref;
        BaseClientAPIClass *ÑurrentClassHref = nullptr;

        CoomonClientAPIDefs::string version;
        CoomonClientAPIDefs::string lang;
        Attachment::User user; //toDo VK_user
        CoomonClientAPIDefs::string curl_buffer;

        CoomonClientAPIDefs::callback_func_cap captcha_callback = nullptr;
        CoomonClientAPIDefs::callback_func_fa2 fa2_callback = nullptr;

    protected:
         //method
        virtual CoomonClientAPIDefs::string get_captcha_key(const CoomonClientAPIDefs::string &captcha_sid);
        virtual CoomonClientAPIDefs::string get_fa2_code();
        virtual bool check_access();
        virtual CoomonClientAPIDefs::string request(const CoomonClientAPIDefs::string &url, const CoomonClientAPIDefs::string &data);

    public:
        //method
        BaseClientAPIClass(const CoomonClientAPIDefs::string _version = DEFAULTAPIVERSION,
            const CoomonClientAPIDefs::string _lang = DEFAULTAPILANG,
            const CoomonClientAPIDefs::callback_func_cap cap_callback = nullptr,
            const CoomonClientAPIDefs::callback_func_fa2 _fa2_callback = nullptr);

        virtual bool auth(const CoomonClientAPIDefs::string &login, const CoomonClientAPIDefs::string &pass,
            const CoomonClientAPIDefs::string &access_token = "");

        virtual bool oauth(const CoomonClientAPIDefs::callback_func_cap handler);

        virtual CoomonClientAPIDefs::json call(const CoomonClientAPIDefs::string &method, const CoomonClientAPIDefs::params_map &params);
        virtual CoomonClientAPIDefs::json call(const CoomonClientAPIDefs::string &method, const CoomonClientAPIDefs::string &params = "");

        virtual void clear();

        virtual CoomonClientAPIDefs::string first_name() const;//--> ïåðåìåñòèòü
        virtual CoomonClientAPIDefs::string last_name() const;

        virtual size_t user_id() const;

        virtual CoomonClientAPIDefs::string access_token() const;
        virtual CoomonClientAPIDefs::string last_error() const;

        virtual void set_fa2_callback(const CoomonClientAPIDefs::callback_func_fa2 _fa2_callback = nullptr);
        virtual void set_cap_callback(const CoomonClientAPIDefs::callback_func_cap cap_callback = nullptr);

        virtual ~BaseClientAPIClass() {}
    };

    class Utils {
    public:
        static CoomonClientAPIDefs::string data2str(const CoomonClientAPIDefs::params_map &data);
        static CoomonClientAPIDefs::string urlencode(const CoomonClientAPIDefs::string &url);
        static CoomonClientAPIDefs::string char2hex(const char dec);
        static int CURL_WRITER(char *data, size_t size, size_t nmemb, CoomonClientAPIDefs::string *buffer);
    };


}
#endif // BASECLIENTAPI
