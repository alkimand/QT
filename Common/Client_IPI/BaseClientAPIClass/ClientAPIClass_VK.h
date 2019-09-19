#ifndef CLIENTAPI_VK
#define CLIENTAPI_VK

#include <BaseClientAPIClass/BaseClientAPIClass.h>
#include <BaseClientAPIClass/VKClientAPIDefs.h>

namespace BaseClientAPI {

    class ClientAPIClass_VK: public BaseClientAPIClass
    {
    private:


    protected:
        bool check_access();
        CoomonClientAPIDefs::string get_captcha_key(const CoomonClientAPIDefs::string &captcha_sid);
        CoomonClientAPIDefs::string get_fa2_code();
        CoomonClientAPIDefs::string request(const CoomonClientAPIDefs::string &url, const CoomonClientAPIDefs::string &data);

    public:

        //ClientAPIClass_VK(const CoomonClientAPIDefs::string _version = "5.65",
        //    const CoomonClientAPIDefs::string _lang = "en",
        //    const callback_func_cap cap_callback = nullptr,
        //    const callback_func_fa2 _fa2_callback = nullptr);

        ClientAPIClass_VK(const CoomonClientAPIDefs::string _version = VKAPIVERSION,
            const CoomonClientAPIDefs::string _lang = VKDEFAULTLANG,
            const CoomonClientAPIDefs::callback_func_cap cap_callback = nullptr,
            const CoomonClientAPIDefs::callback_func_fa2 _fa2_callback = nullptr
        ); 



        bool auth(const CoomonClientAPIDefs::string &login, const CoomonClientAPIDefs::string &pass,
            const CoomonClientAPIDefs::string &access_token = "");

        bool oauth(const CoomonClientAPIDefs::callback_func_cap handler);

        		using json = nlohmann::json;json call(const CoomonClientAPIDefs::string &method, const CoomonClientAPIDefs::params_map &params);

        json call(const CoomonClientAPIDefs::string &method, const CoomonClientAPIDefs::string &params = "");

        void clear();

        CoomonClientAPIDefs::string first_name() const;
        CoomonClientAPIDefs::string last_name() const;
        size_t user_id() const;

        CoomonClientAPIDefs::string access_token() const;
        CoomonClientAPIDefs::string last_error() const;


        ~ClientAPIClass_VK() {}
    };
}
#endif // CLIENTAPI_VK
