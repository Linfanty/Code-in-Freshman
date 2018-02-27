#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 2005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);

//const int N = 2e5 + 5;
using namespace std;

int main()
{
    //fin;
    //fout;

    long long int l;
    int n ,m;
    string s;

    while( cin >> s)
    {
        if ( s[0]-'0' == 0 && !s[1] )
            break;
        int flag = 0;
        int len = s.size();
        int mid =  s[0] -'0';

        for(int i = 0; i < len; i++)
        {
            if( i+1 == len)
                break;

            mid =  mid   * 10 + (s[i+1] - '0');
            //cout << mid << ' ';

            mid = mid % 11;
            if( mid % 11 == 0)
            {
                if( i+2 >= len )
                {
                    flag = 1;
                    break;
                }
            }

           // cout << mid << endl;
        }
        //cout << mid << endl;

        if( flag == 1)
            cout << s << " is a multiple of 11."<<endl;
        else cout << s << " is not a multiple of 11." << endl;

        s.clear();
    }
}
