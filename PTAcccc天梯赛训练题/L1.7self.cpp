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
	int n; cin >> n;
	getchar();
	string s;
	
	getline( cin , s );
	//gets(s);
	int l = s.size();
	int L = l;
	
	cout << s;
	
	for (int i = L-1 ; i>= 0 ;i--)
	{
		if( s[i] == ' ')
			l--;
		else break;
	}
	
	cout<< L<<"  "<<l;
	
	L = l;
	
	while( l % n) //添加长度 使为空格 
		l++;
		
	cout<<' '<< l<<endl ;
	
	for(int i = L; i <= l ;i++)
		s.push_back(' ');
	
	
	for(int j = 0; j < n ;j++)
	{
		for( int i = l-1 ;i >= 0;i--)
			if( i%n == j)
				cout << s[i];
	
	cout<<endl;
	}
}
 

