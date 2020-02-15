#include "pch.h"
#include <iostream>
#pragma warning(disable:4996)

#pragma comment(lib,"libcurl.lib")
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
namespace ui{
//#include <curl/curl.h>
}
#include <curl/curl.h>

size_t write_data(char *ptr, size_t size, size_t nmemb, FILE* data)
{
    return fwrite(ptr, size, nmemb, data);
}
//---------------------------------------------------------------------------
int main()
{
    // Открываем файлы для заголовка и тела
    std::string body_filename = "body.html";
    FILE *body_file = fopen(body_filename.c_str(), "w");
    if (body_file == NULL) return -1;
    //std::string url = "https://www.it52.info";
    std::string twitterLoginUrl = "https://twitter.com/login";
    std::string twitterEntryUrl = "https://twitter.com/sessions";
    std::string cookiefilename = "test";
    CURL *curl_handle = curl_easy_init();
    if (curl_handle)
    {
        curl_easy_setopt(curl_handle, CURLOPT_VERBOSE, 1L);

        // сохранение в файл html-страницу
        curl_easy_setopt(curl_handle, CURLOPT_WRITEDATA, body_file);
        curl_easy_setopt(curl_handle, CURLOPT_WRITEFUNCTION, write_data);
        // заголовки ответа выводим в консоль
        curl_easy_setopt(curl_handle, CURLOPT_WRITEHEADER, stdout);
        /* HTTPs Запрос */
        //curl_easy_setopt(curl_handle, CURLOPT_URL, twitterLoginUrl.c_str());
        curl_easy_setopt(curl_handle, CURLOPT_URL, "http://www.cyberforum.ru/");
        // не проверять SSL сертификат
        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYPEER, 0);
        // не проверять Host SSL сертификата
        curl_easy_setopt(curl_handle, CURLOPT_SSL_VERIFYHOST, false);
        curl_easy_setopt(curl_handle, CURLOPT_FOLLOWLOCATION, 1);
        curl_easy_setopt(curl_handle, CURLOPT_USERAGENT,"Mozilla/5.0 (Windows NT 6.1;rv:16.0) Gecko / 20100101 Firefox / 16.0");

        //
        curl_easy_setopt(curl_handle, CURLOPT_COOKIEJAR, cookiefilename.c_str());//
       // curl_easy_setopt(curl_handle, CURLOPT_COOKIEFILE, cookiefilename.c_str());
        //curl_easy_setopt(curl_handle, CURLOPT_REFERER, "https://twitter.com/login");
        CURLcode res = curl_easy_perform(curl_handle);
        if (res != CURLE_OK)
            std::cout << "Error #" << res << " " << curl_easy_strerror(res) << std::endl;
        
        
        
        curl_easy_cleanup(curl_handle);
    }

    std::cout << std::endl << "Done!";
    getchar();
    return 0;
}
//--------------------------------------------------------------------------