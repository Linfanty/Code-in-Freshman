#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int pre[1000];
int total;
bool t[1000];

int find (int x)		//���Ҹ��ڵ� 
{
	int r = x;
	while( pre[r] != r)
		r = pre[r];		//���ظ��ڵ� 
		
		int i = x, j;
		
	while( i!=j)   		//·��ѹ�� 
	{
		j = pre[i];		//�ϼ�j 
		pre[i] = r;		//��i�ϼ���Ϊ���ڵ� 
		i = j;			//�ݹ���� 
	}
	return r;
}

void join( int x, int y) //�ж���ͨ  �ϲ�
{
	int fx = find(x);
	int fy = find(y);
	//����ǲ���ͨ�ģ���ô����������֧������
    //��֧�������ͼ�����1�����轨��·Ҳ�ͼ���1
	if( fx != fy)	
		pre[fx] = fy;
}

int main()  
{  
    int N,M,a,b,i,j,ans;  
    while(scanf("%d%d",&N,&M)&&N)  
    {  
        for(i=1;i<=N;i++)          //��ʼ��   
            pre[i]=i;  
          
        for(i=1;i<=M;i++)          //���ղ���������   
        {  
            scanf("%d%d",&a,&b);  
            join(a,b);  
        }  
          
          
        memset(t,0,sizeof(t));  
        for(i=1;i<=N;i++)          //��Ǹ����  
        {  
            t[find(i)]=1;  
        }  
        for(ans=0,i=1;i<=N;i++)  
            if(t[i])  
                ans++;  
                  
        printf("%d\n",ans-1);     
    }  
    return 0;  
}




