#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <climits>
#include <queue>
#include <map>
#include <set>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define max1 100005
#define maxn 50005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

set <ll> s1;

int main()
{
    ll n;
    string s;   int t;
    int  a[200]; ll len;
    cin >>t;
    while(t--)
    {
        rep(i, 0, 199)
            a[i] = 0;
        cin >> len;
        cin >> s;
        int flag = 0;

        rep(i,0,len-1)
        {
            a[s[i]]++;
            //cout << a[s[i]] << ' ';
            if(a[s[i]] == 2 )
            {
                flag = 1;
                break;
            }
        }

        if( flag == 1)
            cout << "No" <<endl;
        else cout <<"Yes" << endl;
    }

}
