//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<string.h>
#include<cstdlib>
#include<vector>
#include<queue>
#include<cmath>
#include<list>
#include<map>
#include<set>
#include<sstream>
#include<cstdio>
#include<cmath>
#define pf printf
#define rt return
#define sf scanf
#define fv while(1)
#define max(x,y) ((x)>(y)?(x):(y))
#define min(x,y) ((x)>(y)?(y):(x))
#define fj(x) for(ll j=0;j<(x);j++)
#define fi(x) for(ll i=0;i<(x);i++)
#define mst(x,y) memset((x),(y),sizeof(x))
#define foi(x,y) for(ll i=x;i<y;i++)
#define foj(x,y) for(ll j=x;j<y;j++)
#define fni(x,y)	for(ll i=x;i>y;i--)
#define fnj(x,y)	for(ll j=x;j>y;j--)
#define bug
#define file
#define IO       ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
const ll INF  = 0x3f3f3f3f;
const ll DINF = 0x80808080;
const ll Mod  = 1e9+7;
const ll maxn = 10000+10;
const ll maxm = 100000+10;

struct st{
  int v,nex;
}edge[maxm];

int hed[maxn],vis[maxn];
int low[maxn],dfn[maxn],belon[maxn],stack[maxn];
int in[maxn],out[maxn];
int n,m,e,top,cnt,num,sum1,sum2;

void init(){
    memset(hed,-1,sizeof(hed));
    memset(vis,0,sizeof(vis));
    memset(dfn,0,sizeof(dfn));
    memset(in,0,sizeof(in));
    memset(out,0,sizeof(out));
    e=1;
    top=num=cnt=0;
}

void add(int u,int v){
    edge[e].v=v,edge[e].nex=hed[u],hed[u]=e++;
}

void targan(int u){     //Ëõµã
    dfn[u]=low[u]=++num;
    stack[top++]=u;
    vis[u]=1;
    for(int i=hed[u];~i;i=edge[i].nex){
        int v = edge[i].v;
        if(!dfn[v]){
            targan(v);
            low[u]=min(low[u],low[v]);
        }else if(vis[v]){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        cnt++;
        int x;
        do{
            x=stack[--top];
            vis[x]=0;
            belon[x]=cnt;
        }while(x!=u);
    }
}

int main()
{
    int t;sf("%d",&t);
    while(t--){
        init();
        sf("%d%d",&n,&m);

        if(n==1) {
        	puts("0");
        	continue;
        }
		if(m==0){
			pf("%d\n",n);
			continue;
		}

        int mm = m;
        while(m--){
            int u,v;sf("%d%d",&u,&v);
            add(u,v);
        }
        for(int i=1;i<=n;i++){
            if(!dfn[i])targan(i);
        }
        if(cnt==1){
            pf("0\n");
            continue;
        }
        for(int i=1;i<=n;i++){
            for(int j = hed[i];~j;j=edge[j].nex){
                int v = edge[j].v;
                if(belon[i]!=belon[v]){
                    out[belon[i]]=1;
                    in[belon[v]]=1;
                }
            }
        }
        sum1=sum2=0;
        for(int i=1;i<=cnt;i++){
            if(in[i]==0)sum1++;
            if(out[i]==0)sum2++;
        }
        if(sum1<sum2)sum1=sum2;
        pf("%d\n",sum1);
    }

    return 0;
}





