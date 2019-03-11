#include <iostream>
#include "function.h"


int main()
{
    //printf("Hello World!\n");
    std::string ip="127.0.0.1";
    if (checkIP(ip))
        std::cout << "yes" << std::endl;
    else
    std::cout << "no" << std::endl;

    return 0;
}
