#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin >>n;
	char s[10005][5];
	memset(s,0,sizeof(s));
	
	
	for( int i = 0 ; i<n ; i++)
		cin>>s[i];
	
	cout<<endl;
		cout<<s[0][4]<<endl;
	
	for( int i = 0 ; i<n ; i++)
		cout<<s[i]<<' ';
}
