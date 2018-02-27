#include<iostream>  
#include<cstdio>//���鼯  
using namespace std;  
int p[101];    
int q[101][101]; //�ڽӾ���洢���ߵ�ֱ�ӹ�ϵ��1���� -1�ж�  
int find(int x)//Ѱ��
{    
    int r = x;  
    while(p[r]!=r)
	{  
        r = p[r];  
    }     
    int i=x,j;           
    while(p[i]!=r)
	{ //·��ѹ��   
        j = p[i];  
        p[i] = r;  
        i = j;  
    }  
    return r;  
}  
void join(int x,int y)
{ //���������Ϻϲ�   
    int fx = find(x);  
    int fy = find(y);  
    if(fx!=fy){  
       p[fx] = fy;  
    }  
}  
bool same(int x,int y)
{ //�ж�����Ԫ���Ƿ���ͬһ��������   
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

