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
bool e[MAXN][MAXN];//�Ƿ�ж�
int set_find(int p)
{
    if(set[p]==0)					//�ص�
        return p;					//�ص�
    return set[p]=set_find(set[p]); //�ص� 
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
    for(int i=0; i<m; ++i)//��ϵ
    {
        int a,b,r;
        cin>>a>>b>>r;
        if(r==1) join(a,b);//����
        else if(r==-1) e[a][b]=e[b][a]=true;//�ж�
    }
    for(int i=0; i<q; ++i)//��ѯ
    {
        int a,b;
        cin>>a>>b;
        if(set_find(a)==set_find(b)&&!e[a][b]&&!e[b][a]) cout<<"No problem"<<endl;//�����λ����֮�������ѣ���û�ежԹ�ϵ
        else if(!e[a][b]&&!e[b][a]) cout<<"OK"<<endl;//�������֮�䲢�������ѣ���Ҳ���ж�
        else if(set_find(a)==set_find(b)&&e[a][b]&&e[b][a]) cout<<"OK but..."<<endl;//�������֮���ежԣ�Ȼ��Ҳ�й�ͬ������
        else cout<<"No way"<<endl;//�������֮��ֻ�ежԹ�ϵ
    }
    return 0;
}

