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
#define maxn 200005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	ll a[105];
	ll c[105];
	int vit[105] = {0};
	int n ,k;
	cin>>n>>k;
	
	for(int i = 1 ; i <=k ; i++ )
		cin>>c[i];
		
	int flag = 1 ;
	int zhi = 1;
	int jie = 0;
	for(int j = 1 ; j <=k ; j++ )
	{
		int i;
		
		if(j == 1)
			i = 2 ;
		else if(flag  == n - 1 ) //flag == 2    n == 3
			i = 1 ;
		else if( flag == n) // flag == 3
			i = 2 ;
		else i = flag + 2; //flag = 1  n = 3  i = 3
		
		
		while( c[j]-- ) 	//*******//
		{
			if(i % n == 0 )
				++jie;
			
			
			if( vit[i-n*jie] == 0 )
			{	
				if( i >= n+1 )
				{
					if( i < 2*n)
					zhi =  i-n*jie;
					else zhi =  i-n*jie + 1;
					//cout<<i<<' '<<flag<<' '<<zhi<<endl; 
				}
				else
					zhi = i ;	
				cout<<i<<' '<<zhi<<endl;
			}
			else ++c[j];
			
			++i;
		}
		
		if(j == 1)
			cout<<zhi;
		else 
			cout<<' '<<zhi;
			
			vit[zhi] = 1;
			flag = zhi ;			
			jie = 0;				
	}
	
			
}
