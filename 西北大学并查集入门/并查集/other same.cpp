#include<iostream>  
#include<cstdio>//并查集  
using namespace std;  
int p[101];    
int q[101][101]; //邻接矩阵存储两者的直接关系，1朋友 -1敌对  
int find(int x)//寻找
{    
    int r = x;  
    while(p[r]!=r)
	{  
        r = p[r];  
    }     
    int i=x,j;           
    while(p[i]!=r)
	{ //路径压缩   
        j = p[i];  
        p[i] = r;  
        i = j;  
    }  
    return r;  
}  
void join(int x,int y)
{ //将两个集合合并   
    int fx = find(x);  
    int fy = find(y);  
    if(fx!=fy){  
       p[fx] = fy;  
    }  
}  
bool same(int x,int y)
{ //判断两个元素是否在同一个集合中   
    if(find(x)==find(y))
	{  
        return true;  
    }
	else
	{  
        return false;  
    }  
}     
int main()
{
	int n,m,k,a,b,c;
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		p[i]=i;
	}
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b>>c;
		q[a][b]=c;
		q[b][a]=c;
		if(c==1)
		{
			join(a,b);
		}
	}
	for(int i=1;i<=k;i++)
	{
		cin>>a>>b;
		if(q[a][b]==1)
		cout<<"No problem"<<endl;
		else if(q[a][b]==-1&&find(a)==find(b))
        cout<<"OK but..."<<endl;
        else if(q[a][b]==-1&&find(a)!=find(b))
        cout<<"No way"<<endl;
        else if(q[a][b]==0&&find(a)!=find(b))
        cout<<"OK"<<endl;
	} 
    return 0;  
}   

