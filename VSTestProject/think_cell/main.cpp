#include <iostream>
#include <interval_map.h>
using namespace std;

int main()
{
    int rt = 2;

    interval_map<int, char> mp(rt);
    mp.m_map = { {4,'B'}, {10,'A'} , {12,'T'}};
    mp.m_valBegin = 'D';

    char ansver10 = mp[10];
    mp.assign(30,8,'C');

    char ansver0_2 = mp[-2];
    char ansver0_1 = mp[-1];
    char ansver0 = mp[0];
    char ansver1 = mp[1];
    char ansver2 = mp[2];
    char ansver3 = mp[3];
    char ansver4 = mp[4];
    char ansver5 = mp[5];
    char ansver6 = mp[6];

    cout << "Hello World!" << endl;














    return 0;




}
