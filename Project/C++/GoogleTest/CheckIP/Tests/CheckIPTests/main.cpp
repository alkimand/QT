#include <iostream>
#include <gtest/gtest.h>

#include "function.h"
#include <string>

//https://www.youtube.com/watch?v=6pp8S56sS2Y

TEST (TEST001,test)
{
  std::string ip = "127.0.0.1";
  bool actual = checkIP(ip);
  bool expected = true;
  freopen("file.txt", "w+", stdout);
  ASSERT_EQ(expected,actual );

}


TEST (TEST002,test)
{
  std::string ip = "127.0.0.1";
  bool actual = checkIP(ip);
  bool expected = false;
  freopen("file.txt", "w+", stdout);
  ASSERT_EQ(expected,actual );

}
//using namespace std;

int main(int argc, char *argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

//    cout << "Hello World!" << endl;
    return RUN_ALL_TESTS();
}
