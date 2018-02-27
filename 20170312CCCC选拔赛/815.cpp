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
	int a[105],b[105];
	for(int i=0;i<n;i++)
	{
		scanf("%d/%d",&a[i],&b[i]);
		//printf("%d %d ",a[i],b[i]);
		fenmu *= b[i];
	}
	
	
	for(int i=0;i<n;i++)
	{
		fenzi += fenmu / b[i] * a[i] ;	
	}
	
   //cout<<fenzi<<fenmu<<endl;
	
	
	fenmu = fenmu * n;
	ll gy = gcd(fenzi,fenmu); 
	fenzi = fenzi / gy;
	fenmu = fenmu / gy;
	if(fenmu==1)
	cout<<fenzi;
	else cout<<fenzi<<'/'<<fenmu;	

}
