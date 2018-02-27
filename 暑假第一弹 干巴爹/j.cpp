#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 100005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define rep(i,a,b) for(int i=a;i<b;i++)
//const int N = 2e5 + 5;
using namespace std;
typedef long long int ll;

ll n, m, a;
int b[maxn],p[maxn];
//用财产最多的人租最贵的车,然后二分逼近

//选k个钱多的人，和k个租费少的车，然后一一对应，
//并用上共同资金。现在就有一个问题，确定k的值

//如果k不行，那么k之后的都不可以
//求可以购买的最大车子数量 &金钱
bool check(int mm)
{
    ll sum = 0;
    rep(i,0,mm)
        if(p[mm-1-i] > b[n-1-i])
            {sum += p[mm-1-i] - b[n-1-i];
             //cout << mm <<' ' <<  p[mm-1-i] << ' ' << b[n-1-i] << endl;
            }
            //cout << endl;
        //mm:3 p[2-i] b[3-i]
        // 2 3 5 6 7
        // 1 1 2 8

        //      p[2] b[3]  可以买了的话 就不加入sum
        //      p[1] b[2]  加入sum
        //      p[0] b[1]  加入sum

        // 2 3
        //   1 2
    if(sum > a)
        return false;
    return true; // 总的花费小于等于可补偿的a
}

void erfen()
{
    ll low = 0, high = min(n,m);
    while( low <= high){
        ll mid = (low+high)/2;
        //cout << mid << ' ' << check(mid) << endl;
        if( check(mid) )
        {
            ll ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    ll sum = 0;
    //cout << low << ' ' << high << endl; //4 3

    rep(i,0,low)//从花费最少的车依次选择
        {sum += p[high-1-i];
         //cout << high-1-i << ' '<<p[high-1-i]<<endl;
        }
        //p[2]: 5
        //p[1]: 3
        //p[0]: 2
        //p[-1]: 0

    sum = max(0ll, sum-a);//减去总可以补偿的金额
    cout << high << ' ' << sum << endl;
}

int main()
{
    cin >> n >> m >> a;
    rep(i,0,n) cin >> b[i];
    rep(i,0,m) cin >> p[i];
    sort(b,b+n); sort(p,p+m);
    erfen();
}
