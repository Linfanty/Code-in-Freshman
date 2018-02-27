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
	ll t;
	cin>>t;
	ll tu=0 , wu=0;
	int flag = 0;
	int flag1 = 0;
	ll min10 = t / 10 ;
	ll min1 = t%10;
	
	int i;
	for(i = 1 ; i <= min10 ;i++ )
	{
		if( tu>wu && flag==0)
		{
			wu +=  3 * 10; 
			//cout<<"    i: "<<i<<"   min10 :  "<<min10<<endl;
			if(i == min10)
			{
				//cout<<"88888888";
				flag1=1;
				break;
			}
			++i;
			
			wu +=  3 * 10;
		
			if(i == min10)
			{
				//cout<<"88888888";
				flag1=2;
				break;
			} 
				++i;
			wu +=  3 * 10; 
			flag=1;
		//	cout<<"i: "<<i<<' '<<tu<<' '<<wu<<endl;
			continue; 
		}
	
		tu +=  9 * 10 ;
		
		wu +=  3 * 10; 
		flag=0;
		//cout<<"i: "<<i<<' '<<tu<<' '<<wu<<endl;

	}
	
	
	if(flag1==0)
	{
		tu += min1 * 9;
		wu += min1 * 3;
		if(tu>wu)
		cout<<"^_^"<<' '<<tu<<endl;
		else if(tu==wu)
		cout<<"-_-"<<' '<<tu<<endl;
		else if(wu>tu)
		cout<<"@_@"<<' '<<wu<<endl;
	}	
	else 
	{
		wu += min1 * 3;
		if(tu>wu)
		cout<<"^_^"<<' '<<tu<<endl;
		else if(tu==wu)
		cout<<"-_-"<<' '<<tu<<endl;
		else if(wu>tu)
		cout<<"@_@"<<' '<<wu<<endl;
	}
	
}
