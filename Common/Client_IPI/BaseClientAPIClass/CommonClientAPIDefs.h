#ifndef COMMONBASEAPIDEFS
#define COMMONBASEAPIDEFS

#define DEFAULTAPIDATA ""
#define DEFAULTAPIVERSION ""
#define DEFAULTAPILANG "en"


namespace CoomonClientAPIDefs {
        using callback_func_cap = std::string(*)(const std::string &);
        using callback_func_fa2 = std::string(*)();
		  using params_map = std::map<std::string, std::string>; //unordered_map
		  using json = nlohmann::json;
	     using ::std::string;
}
#endif // COMMONBASEAPIDEFS
