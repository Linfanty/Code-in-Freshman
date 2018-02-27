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


int n, a, s, t;
int ou = 0,  ji = 0, num;
int main()
{
    cin >> t;

    while(t--)
    {
        cin >> n;
        cin >> s;
        num = s;
        ou = ji = 0;

        if( s&1 )
            ji = s;
        else ou = s;

        cout<<"a:"<<a<< " ou:"<<ou<<" ji:"<<ji<<" num:"<<num<<endl;
        //维护前面连续一段的和为偶数 和为奇数两个值
        rep(i, 2, n)
        {
            cin >> a;
            //if( ou < 0 || ji < 0)
            //{
                if( a&1 )
                {
                    int temp = ou;
                    ou = max(ou, a + ji);
                    ji = max(ji, a + temp);
                }
                else
                {
                    ji = max(ji, a + ji);
                    ou = max(ou, ou + a);
                }
            //}
            /*
            else if( a&1 )
            {
                int temp = ji;
                ji = a + ou;
                ou = a + temp;
            }
            else
            {
                ji = a + ji;
                ou = a + ou;
            }
            */
            if( num < ji ) num = ji;
            cout<<"a:"<<a<< " ou:"<<ou<<" ji:"<<ji<<" num:"<<num<<endl;
        }
        cout << num << endl;
    }

}
