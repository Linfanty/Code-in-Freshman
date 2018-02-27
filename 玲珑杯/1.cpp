#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#define rep(i,a,b) for(int (i) = (a);(i) <= (b);++ (i))
#define per(i,a,b) for(int (i) = (a);(i) >= (b);-- (i))
#define mem(a,b) memset((a),(b),sizeof((a)))
#define maxn 100005
typedef long long ll;
using namespace std;

	char s[maxn];
	ll i,n,N,M;
	ll left1[maxn],right1[maxn]; 
int main()
{
	cin>>N;
	M=N;
	while(N--)
	{
		cout<<"Case #"<<M-N<<':'<<endl;
		cin>>s;
		cin>>n;
		rep(i,1,n)	cin>>left1[i]>>right1[i];
		
	}
	return 0;
}
