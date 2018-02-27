#include <bits/stdc++.h>
#include <climits>
typedef long long ll;
using namespace std;

ll a[200005];
ll n, m;

int main()
{
	//while( cin >> n >> m )
	cin >> n >> m;
{

    for(ll i = 0 ; i < n ; i++)
        cin >> a[i] ;

    sort(a, a+n);
    ll min1 = a[0];


    for(ll i = 1 ; i < n ; i++)
    {
        if(a[i] - a[i-1] == 0)
            continue;
        min1 = min(a[i]-a[i-1], min1);
    }



    ll ans = 0;
    //cout << ans <<m <<min1<<endl;
    ans = (m % min1) ;

   // cout << ans << ' '<< min1 <<endl;

    if( ans == 0 || ans == 1)
        printf("YES\n");
    else printf("NO\n");

}
	return 0;
}
