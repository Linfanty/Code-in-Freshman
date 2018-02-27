#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)

ll n,T,i,j,_count[10005],maxn;
char ch[10005];

int main(){
	cin >> T;
	while(T--)
    {
		cin >> n;
		maxn = 0;
		memset(_count,0,sizeof(_count));
		memset(ch,0,sizeof(ch));
		for(i = 0; i < 3 ; i++)
        {
			scanf("%s",ch); getchar();
			for(j = 0; j < 3 * n; j++)
			{
				if(ch[j] == '*') _count[j / 3]++;
				maxn = max(maxn,_count[j / 3]);
			}
		}
	    cout << maxn * 4 <<endl;
	}
	return 0;
}
