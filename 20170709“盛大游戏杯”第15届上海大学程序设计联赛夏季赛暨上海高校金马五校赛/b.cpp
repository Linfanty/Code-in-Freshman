#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 100005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;
typedef long long int ll;

int main()
{
    int n, a, b, flag = 0;
    while( cin >> n)
    {
        int duanwei = 0;
        int ans = 0;
        flag = 0;
        rep(i, 1, n)
        {
            cin >> a;
            if( flag == 1)
            {
                flag = 0;
                if( i+2 > n)
                    break;
                cin >> a >> b;
                i++; i++;
                if( a == 0 && b == 0)
                {
                    duanwei--;
                    ans = 60;
                    continue;
                }
                else if( a == 1 && b == 1)
                {
                    duanwei++;
                    ans = 0;
                    continue;
                }
                else
                {
                    if( i+1 > n)
                        break;
                    cin >> a;
                    i++;
                    if( a == 1)
                    {
                        duanwei++;
                        ans = 0;
                        continue;
                    }
                    else if( a == 0)
                    {
                        duanwei--;
                        ans = 60;
                        continue;
                    }
                }
            }
            if( a == 1 )
                ans += 10;
            else if( a == 0)
                ans -= 5;

            if( ans >= 100)
            {
                ans = 0;
                flag = 1;
            }

        }
        if( duanwei == 0)
            cout << 'D' <<endl;
        else  if( duanwei == 1)
            cout << 'C' <<endl;
        else  if( duanwei == 2)
            cout << 'B' <<endl;
        else  if( duanwei == 3)
            cout << 'A' <<endl;
        else  if( duanwei >= 4)
            cout << 'S' <<endl;


    }
}

