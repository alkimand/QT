// test_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#pragma warning(disable:4996)
//int main()
//{
//    std::cout << "Hello World!\n"; 
//}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.

#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <curl/curl.h>

#ifdef WIN32
#  include <io.h>
#  define READ_3RD_ARG unsigned int
#else
#  include <unistd.h>
#  define READ_3RD_ARG size_t
#endif

#if LIBCURL_VERSION_NUM < 0x070c03
#error "upgrade your libcurl to no less than 7.12.3"
#endif

    /*
     * This example shows a HTTP PUT operation with authentiction using "any"
     * type. It PUTs a file given as a command line argument to the URL also given
     * on the command line.
     *
     * Since libcurl 7.12.3, using "any" auth and POST/PUT requires a set ioctl
     * function.
     *
     * This example also uses its own read callback.
     */

     /* ioctl callback function */
    static curlioerr my_ioctl(CURL *handle, curliocmd cmd, void *userp)
{
    int *fdp = (int *)userp;
    int fd = *fdp;

    (void)handle; /* not used in here */

    switch (cmd) {
    case CURLIOCMD_RESTARTREAD:
        /* mr libcurl kindly asks as to rewind the read data stream to start */
        if (-1 == _lseek(fd, 0, SEEK_SET))
            /* couldn't rewind */
            return CURLIOE_FAILRESTART;

        break;

    default: /* ignore unknown commands */
        return CURLIOE_UNKNOWNCMD;
    }
    return CURLIOE_OK; /* success! */
}

/* read callback function, fread() look alike */
static size_t read_callback(void *ptr, size_t size, size_t nmemb, void *stream)
{
    size_t retcode;
    curl_off_t nread;

    int *fdp = (int *)stream;
    int fd = *fdp;

    retcode = _read(fd, ptr, (READ_3RD_ARG)(size * nmemb));

    nread = (curl_off_t)retcode;

    fprintf(stderr, "*** We read %" CURL_FORMAT_CURL_OFF_T
        " bytes from file\n", nread);

    return retcode;
}

int main(int argc, char **argv)
{
    argc = 3;
    const  char * str = "D:/test.txt";
    char  str2 []= "D:/test.txt";
    char muUrl[] = "http://www.cyberforum.ru/log-in.php"; //"https://mail.ru/";
    //argv[1] = str;
    CURL *curl;
    CURLcode res;
    int hd;
    struct stat file_info;
    char *file = str2;
   // char *file = "D:/test.txt";
    char *url = muUrl;

    if (argc < 3)
        return 1;
    //file = "C: / c / test.txt";

   // file = argv[1];
   // url = argv[2];

    /* get the file size of the local file */
    hd = open(file, O_RDONLY);
    fstat(hd, &file_info);

    /* In windows, this will init the winsock stuff */
    curl_global_init(CURL_GLOBAL_ALL);

    /* get a curl handle */
    curl = curl_easy_init();
    if (curl) {
        /* we want to use our own read function */
        curl_easy_setopt(curl, CURLOPT_READFUNCTION, read_callback);

        /* which file to upload */
        curl_easy_setopt(curl, CURLOPT_READDATA, (void *)&hd);

        /* set the ioctl function */
        curl_easy_setopt(curl, CURLOPT_IOCTLFUNCTION, my_ioctl);

        /* pass the file descriptor to the ioctl callback as well */
        curl_easy_setopt(curl, CURLOPT_IOCTLDATA, (void *)&hd);

        /* enable "uploading" (which means PUT when doing HTTP) */
        curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);

        /* specify target URL, and note that this URL should also include a file
           name, not only a directory (as you can do with GTP uploads) */
        curl_easy_setopt(curl, CURLOPT_URL, url);

        /* and give the size of the upload, this supports large file sizes
           on systems that have general support for it */
        curl_easy_setopt(curl, CURLOPT_INFILESIZE_LARGE,
            (curl_off_t)file_info.st_size);

        /* tell libcurl we can use "any" auth, which lets the lib pick one, but it
           also costs one extra round-trip and possibly sending of all the PUT
           data twice!!! */
        curl_easy_setopt(curl, CURLOPT_HTTPAUTH, (long)CURLAUTH_ANY);

        /* set user name and password for the authentication */
        curl_easy_setopt(curl, CURLOPT_USERPWD, "alkimand:qwertyop");

        /* Now run off and do what you've been told! */
        res = curl_easy_perform(curl);
        /* Check for errors */
        if (res != CURLE_OK)
            fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));

        /* always cleanup */
        curl_easy_cleanup(curl);
    }
    _close(hd); /* close the local file */

    curl_global_cleanup();
    return 0;
}
