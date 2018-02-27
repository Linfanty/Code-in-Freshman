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
	ll q,w,e;
	cin>>q>>w>>e;
	if(w<q)
	swap(w,q);
	if(e<w)
	swap(e,w);
	if(w<q)
	swap(w,q);
	cout<<q<<"->"<<w<<"->"<<e;
}
