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

ll b1,q,l,m;
ll exm;
map<ll,int>mp;
ll ans=0;
int main()
{
    scanf("%I64d %I64d %I64d %I64d",&b1,&q,&l,&m);
    
    for(ll i=1;i<=m;i++)
    {
        scanf("%I64d",&exm);
        mp[exm]=1;
    }
    
    for(int i=1;i<=1000;i++)
        ans=0;
        
    for(int i=0;i<501;i++)
    {
        if(abs(b1)>l) break;
        if(mp[b1]!=1) ans++;
        b1*=q;
    }
    
    if(ans>100)
        printf("inf\n");
    else
        printf("%I64d\n",ans);
    return 0;
}

