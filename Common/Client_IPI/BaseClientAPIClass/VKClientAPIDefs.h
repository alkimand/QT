#ifndef VKCLIENTAPIDEFS
#define VKCLIENTAPIDEFS

        #define VKAPIVERSION 			"5.34"
        #define VKDEFAULTLANG 			"en"
        #define VKMETHOD_URL	        "https://api.vk.com/method/"
        #define VKMETHOD_USERSGET       "users.get"
        #define VKGOUPSCOPE             "offline,groups,messages,friends,audio,docs,notify,photos,audio,video,stories,pages,status,"
        #define VKAUTHURL               "https://oauth.vk.com/token?"
		#define VKAUTHURL_2             "https://oauth.vk.com/authorize?"
		#define VKDEFAULTRDEDIRECTURL   "https://oauth.vk.com/blank.html"




namespace VKClientAPIDefs {

        using callback_func_cap = std::string(*)(const std::string &);
        using callback_func_fa2 = std::string(*)();
//5.101"
//https://oauth.vk.com/authorize?client_id=3140623&display=page&redirect_uri=https%3a%2f%2foauth%2evk%2ecom%2fblank%2ehtml&response_type=code&scope=offline%2cgroups%2cmessages%2cfriends%2caudio%2cdocs%2cnotify%2cphotos%2caudio%2cvideo%2cstories%2cpages%2cstatus%2c&state=test&v=5%2e101&
//https://vk.com/dev/authcode_flow_user
//https://vk.com/dev/implicit_flow_user

	

		
}
#endif // VKCLIENTAPIDEFS