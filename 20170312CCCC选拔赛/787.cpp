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
	int a,b;
	scanf("%d:%d",&a,&b);
	if(a>=13)
	cout<<a-12<<':'<<b<<' '<<"PM";
	else if(a==12)
	cout<<a<<':'<<b<<' '<<"PM";
	else cout<<a<<':'<<b<<' '<<"AM";
}
