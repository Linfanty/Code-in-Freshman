#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 2005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout);

//const int N = 2e5 + 5;
using namespace std;

int mmap[10005];
char p9[10005];

int main()
{
    //fin;
    //fout;
    int t;
    cin >> t;

    for(int p = 1; p <= t ; p++)
    {
        cout << "Case #" << p << ":" << endl;
        memset(p9,0,sizeof(p9));

        string s;
        cin >> s;
        int len = s.size();
        int cnt = 0;
        int max1 = -10;
        int min1 = 10;

        for(int i = 0; i < len; i++)
        {
            if(s[i] == 'R')
                p9[i] = '/';
            else if(s[i] == 'F')
                p9[i] = '\\';
            else //(s[i] == 'C')
                p9[i] = '_';
        }

        cnt = 1;

        for(int i = 0; i < len; i++)
        {
            max1 = max( max1, cnt);
            min1 = min( min1, cnt);

            mmap[i] = cnt;

            if(s[i] == 'R' && s[i+1] == 'R')
                ++cnt;
            else if(s[i] == 'R' && s[i+1] == 'C')
                ++cnt;
            else if(s[i] == 'R' && s[i+1] == 'F')
                continue;
            else if(s[i] == 'F' && s[i+1] == 'F')
                --cnt;
            else if(s[i] == 'F' && s[i+1] == 'R')
                continue;
            else if(s[i] == 'F' && s[i+1] == 'C')
                continue;
            else if(s[i] == 'C' && s[i+1] == 'F')
                --cnt;
        }

        //cout << endl;
        max1 = max( max1, cnt);//3
        min1 = min( min1, cnt);//-3

        int cha;
        //cout << max1 << ' ' << min1 << endl;
        cha = max1 - min1 + 1;  //6
        //if() cha = max1 - min1;
        //cout << max1 <<' ' << min1 <<' ' << cha << endl;

        //for(int i = 0; i < len; i++)
        //    cout << s[i] <<mmap[i] << p9[i] << endl;

        int finally[1000];

        for(int j = cha; j > 0 ; j--)
        {
            for(int i = 0; i < len; i++)
            {
                if( mmap[i] == j - cha + max1 )
                    finally[j] = i;
            }
        }

        //for(int j = cha; j > 0 ; j--)
         //   cout << finally[j];



        for(int j = cha; j > 0 ; j--) //6
        {
            cout << "|";
            cout << ' ';

            for(int i = 0; i < len; i++)
            {
                if( mmap[i] == j - cha + max1 ) //6-6
                    cout << p9[i];
                else cout << ' ';

                if(i >= finally[j]  )
                break;
            }
            cout << endl;
        }

2
        cout << "+";
        for(int i = 0; i <len+2; i++)
           cout << '-';
        cout << endl << endl;
    }
}
/*

Case #1:
+-------/\-----
| \    /  \
|  \  /    \
|   \/      \
|            \
*/
