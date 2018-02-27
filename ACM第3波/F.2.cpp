#include<cstdio>
#include<iostream>
#include<algorithm>
#define N 200000+5
#define INF 0x3f3f3f3f
#define INFF 0x3f3f3f3f3f3f3f
#define rep(i,a,b) for(i=a;i<=b;i++)
using namespace std;

typedef long long ll;
ll i,n,k,s,t;
ll c[N],v[N],g[N];

bool can(ll youliang)
{
	ll time=0;
	rep(i,1,k+1)
	{
		ll road =g[i]-g[i-1];
		if(youliang<road) return false;
		else if(youliang>=road&&youliang<2*road)
		time+=road *2-(youliang - road);
		else time+=road;
	}
	return time<=t;
}

int main()
{
cin>>n>>k>>s>>t;
rep(i,1,n) cin>>c[i]>>v[i];
rep(i,1,k) cin>>g[i];
g[k+1]=s;
g[0]=0;
sort(g+1,g+k+1);

ll low=0,high=INFF;
ll mid,oil=INF;

while(low<=high)
{
	mid=(low+high)/2;
	if(can(mid))//if(can(mid))
//		{
//		oil=mid;
		high=mid-1;
//		}
	else low=mid+1;
}
//cout<<oil<<' '<<mid<<endl;

/*ll min = INFF;
rep(i,1,n)
{
	if(v[i]<=mid&&c[i]<=min)
	min=c[i];
}
cout<<min;
*/
ll ans = INFF;
		
		rep(i,1,n)
		{
			if(v[i] >= mid)
				ans = min(ans,c[i]);
		}
		cout << (ans == INFF ? -1 : ans);

return 0;
}

