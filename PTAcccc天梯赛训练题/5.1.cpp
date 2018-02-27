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
#define maxn 10005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll gcd(ll a1,ll b1)
{
	return b1?gcd(b1,a1%b1):a1;
}

int main()
{
	int n;
	cin>>n;
	ll sum = 0 , fenmu = 1 , fenzi = 0;
	ll a[105],b[105];
	ll gy ;
	for(int i=0;i<n;i++)
	{
		scanf("%lld/%lld",&a[i],&b[i]);
		
		if(a[i] == 0 || b[i] == 0)
		continue;
		
		if(a[i] == 1 || b[i] == 1)
		gy = 1;
		else gy = gcd (a[i] , b[i] );
		
		//cout << gy<<endl;
			a[i] = a[i] / gy ;
			b[i] = b[i] / gy ;	
		//printf("%d %d \n",a[i],b[i]);
		
		fenmu *= b[i];
	}
	//cout<<fenzi<<' '<<fenmu<<endl;
	for(int i=0;i<n;i++)
		{
			if( a[i] != 0 && b[i] !=0 )
			fenzi += fenmu / b[i] * a[i] ;	
   			//cout<<fenzi<<endl;	
		}
	//cout<<fenzi<<' '<<fenmu<<endl;		

	gy = gcd(fenzi,fenmu); 
	fenzi = fenzi / gy;
	fenmu = fenmu / gy;
	
	if(fenzi == 0)
	cout << 0 <<endl;
	else if( abs(fenzi) < abs(fenmu)  )
	cout<<fenzi<<'/'<<fenmu<<endl;
	else if(fenzi % fenmu == 0)
	cout<< fenzi/fenmu <<endl;	
	else cout<< fenzi/fenmu << ' ' << fenzi%fenmu <<'/' <<fenmu<<endl ;
}
