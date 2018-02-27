#include<cstdio>
#include<cmath>
#include<algorithm>
#include<sstream> 
#include<iostream>
#include<string>
typedef long long ll;
using namespace std;

int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	
	string line;
	char s[15][15];
	char num[15][15];
	int j=0;
	int i=0;
	while(getline(cin,line))
	{
		string str;
		stringstream ss(line);
		ss>>s[j];
		cout<<s[j];
		
		while(ss>>num[j])
		{
			
			cout<<num[j]<<endl;
			i++;
			
		}
		
	}
}
