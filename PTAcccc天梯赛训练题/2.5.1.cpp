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
#include<iomanip>
#include <set>
#define maxn 10005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main() {
	char s[60];
	cin>>s;
	int n = strlen(s);
	int m = 0 ;
	double mul = 1.0;
	if(s[0]=='-') {
		mul += mul*0.5;
		++m ;
	}
	if(!((s[n-1])&1)) // 是偶数的话   ！s【n-1】& 1
		mul += mul ;
		
	int sum=0;
	for(int i = 0 + m ; i < n; i++) {
		if(s[i]=='2')
			sum++;
	}
	//cout<<mul<<endl<<sum<<endl<<(double)sum/(n-m)<<endl;
	double  solve = (double)sum/(n-m) *mul *100;

	//cout<<solve<<endl;
	cout<<setiosflags(ios::fixed)<<setprecision(2)<<(double)solve <<'%';
}
