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
	int n;
	char s[maxn];
	int hour ,pass;
 cin>>hour>>pass;
	{
		int min1 =  hour %100 ;
		int hour1 = hour / 100;
		int passhour = pass / 60 ; 
		int passmin = pass % 60;
		if(min1 + passmin >= 60 )
		{
			++passhour;	
			int pa=passmin+min1-60;
			cout<<hour1+passhour<<pa<<endl;
		}
		else
		cout<<hour1+passhour<<passmin+min1<<endl;		
		 
	}
	
	return 0;
}



