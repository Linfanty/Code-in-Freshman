#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 2005
#define ll long long
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);

//const int N = 2e5 + 5;
using namespace std;
ll n, s;

bool judge(ll m)
{
    ll ans = 0;
    ll m1 = m;
    while( m1 > 0)
    {
        ans += m1%10;
        m1 /=  10;
    }
    if( m - ans >= s )
        return true;
    else return false;
}

void erfen()
{
    ll low = 10;
    ll high = n;
    ll ans1 = 0;
    int flag = 0;
    while(low <= high)
    {
        ll mid = (low + high) / 2;

        //cout << mid << "sss" << endl;
        if(  (judge(mid) ) )
        {
            //cout << mid << endl;
            //low = mid + 1;
            high = mid - 1;
            ans1 = mid ;
            flag = 1;
        }
        else low = mid + 1;//high =  mid - 1;
    }
    //cout << ans1 << endl;
    if( flag == 1)
    cout <<  n - ans1 + 1 << endl;
    else cout << 0 << endl;
}

int main(){

    cin >> n >> s;
    erfen();
}

