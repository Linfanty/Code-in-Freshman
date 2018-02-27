#include<cstdio>
#include<cstring>
#include<cmath>
#include<iomanip>
#include<cstdlib>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 110
#define INF 0x3f3f3f3f
int set[MAXN];
bool e[MAXN][MAXN];//是否敌对
int set_find(int p)
{
    if(set[p]==0)					//重点
        return p;					//重点
    return set[p]=set_find(set[p]); //重点 
}
void join(int p,int q)
{
    int p1,q1;
    p1=set_find(p);
    q1=set_find(q);
    if(p1!=q1)
        set[p1]=q1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    memset(&set,0,sizeof(set));
    memset(&e,0,sizeof(e));
    int n,m,q;
    cin>>n>>m>>q;
    for(int i=0; i<m; ++i)//关系
    {
        int a,b,r;
        cin>>a>>b>>r;
        if(r==1) join(a,b);//朋友
        else if(r==-1) e[a][b]=e[b][a]=true;//敌对
    }
    for(int i=0; i<q; ++i)//查询
    {
        int a,b;
        cin>>a>>b;
        if(set_find(a)==set_find(b)&&!e[a][b]&&!e[b][a]) cout<<"No problem"<<endl;//如果两位宾客之间是朋友，且没有敌对关系
        else if(!e[a][b]&&!e[b][a]) cout<<"OK"<<endl;//如果他们之间并不是朋友，但也不敌对
        else if(set_find(a)==set_find(b)&&e[a][b]&&e[b][a]) cout<<"OK but..."<<endl;//如果他们之间有敌对，然而也有共同的朋友
        else cout<<"No way"<<endl;//如果他们之间只有敌对关系
    }
    return 0;
}

