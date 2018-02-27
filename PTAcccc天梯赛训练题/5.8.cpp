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


int main()
{
	int a[]= {7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
	int b[]= {1,0,-1000,9,8,7,6,5,4,3,2};
	int n;
	cin>>n;
	char s[20];
	ll m=0;
	getchar();
	for(int i = 0 ;i<n;i++)
	{
		memset(s,0,sizeof(s));
		ll sum = 0 ;
		int flag = 0 ;
		cin>>s;
		for(int j = 0 ;j<=16;j++)
		{
			if( !isdigit(s[j]) )
			{
				flag = 1 ;
				break ;
			}
			sum += (s[j]-'0')*a[j];	
		} 
		if(flag == 1)
		{
			cout<<s<<endl;
			continue;
		}
		sum = sum%11 ;
		//cout<<sum<<' '<<s[17]<<' '<<b[sum]<<' ';
		if( (s[17]-'0') != b[sum] )
		{
			cout<<s<<endl;
			continue;
		}
		else if((s[17]=='X'&& b[sum] != -1000))
		{
			cout<<s<<endl;
			continue;
		}

		m++;
	}
	if(m==n)
	cout<<"All passed"; 
	
}
