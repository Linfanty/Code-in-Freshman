/*
ID: wty20031
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string>
#define fin freopen("ride.in","r",stdin);
#define fout freopen("ride.out","w",stdout);
using namespace std;

int main() {
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    fin;
    fout;
    string s1, s2;
    while (cin >> s1 >> s2)
    {
        unsigned i;
        int a = 1, b = 1;
        for (i = 0; i < s1.length(); ++i)//————string下标必须大于0而小于s.size()
        a *= s1[i] - 64;//彗星的名字。
        for (i = 0; i < s2.length(); ++i)
        b *= s2[i] - 64;//队伍的名字。
        if (a % 47 == b % 47)
        cout << "GO" << endl;
        else
        cout << "STAY" << endl;
    }

    return 0;
}
