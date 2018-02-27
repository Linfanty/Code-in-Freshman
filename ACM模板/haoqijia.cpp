//油量 路程 时间 二分法 
//sprintf(s,"%d",a);//sprintf()函数：将格式化的数据写入字符串
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int (i) = (a);(i) <= (b);++ (i))
#define per(i,a,b) for(int (i) = (a);(i) >= (b);-- (i))
#define mem(a,b) memset((a),(b),sizeof((a)))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define ls (id<<1)
#define rs ((id<<1)|1)
//#define mid ((l+r)>>1)
#define INF 0x3f3f3f3f
#define INFF 0x3f3f3f3f3f3f3f
#define N 200000+5
typedef long long ll;
const ll mod = 1e8+7;
const ll eps = 1e-12;
using namespace std;

ll n,k,s,t,c[N],v[N],g[N];
bool can(ll md){
	ll time = 0;
	rep(i,1,k)
	{
		ll road = g[i]-g[i-1];
		if(road > md)	return false;
		ll x = min(road,md-road);
		time += x+(road-x)*2;
	}
	
	return time <= t;
	
}
int main()
{IO;

	while(cin >> n >> k >> s >> t){
		rep(i,1,n)	cin >> c[i] >> v[i];
		rep(i,1,k)	cin >> g[i];
		sort(g+1,g+k+1);
		g[++k] = s;

		ll low = 0,high = INFF,oil = INF;
		ll md;
		while(low <= high)
		{
			 md = (low+high)/2;
			if(can(md)){
				oil = md;        //oil 为中间 二分 选中的最小油量 
				high = md-1;     //   high = md-1
			}
			else
				low = md+1;      //   low  = md+1
		}
		cout<<md<<' '<<oil;
		ll ans = INFF;
		
		rep(i,1,n)
		{
			if(v[i] >= oil)
				ans = min(ans,c[i]);
		}
		cout << (ans == INFF ? -1 : ans) << endl;
	}
}
