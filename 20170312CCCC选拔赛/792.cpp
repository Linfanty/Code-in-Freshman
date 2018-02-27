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
	ll a,b;
	char ch;
	char c;
	scanf("%lld%c%c%c%lld",&a,&c,&ch,&c,&b);
	//printf("%d%c%c%c%d",a,c,ch,c,b);
	if(ch=='+')
	cout<<a+b;
	else if(ch=='-')
	cout<<a-b;
	else if(ch=='*')
	cout<<a*b;
	else if(ch=='/')
	cout<<a/b;
	else if(ch=='%')
	cout<<a%b;
	else cout<<"ERROR";

}
