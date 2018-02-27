#include<cstdio>  
#include<cstring>  
#include<algorithm>  
#define maxn 510  
using namespace std;  
int map[maxn][maxn];//·��  
int in_degree[maxn];//���  
int ans[maxn];  
int n,m,x,y;  
void topo()  
{  
    for(int i=1; i<=n; i++)  
        for(int j=1; j<=n; j++)  
            if(map[i][j])  
                in_degree[j]++;//��¼�������  
    for(int i=1; i<=n; i++)  
    {  
        int k=1;  
        while(in_degree[k]!=0)  
            k++;  
        ans[i]=k;  
        in_degree[k]=-1;  
        /*����Ϊ-1����߼��ʱ����Ӱ�졢 
        �൱��ɾ���ڵ�*/ 
        for(int j=1; j<=n; j++)  
            if(map[k][j])  
                in_degree[j]--;//���������ȼ�1  
    }  
}  
int main()  
{  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        memset(in_degree,0,sizeof(in_degree));  
        memset(ans,0,sizeof(ans));  
        memset(map,0,sizeof(map));  
        for(int i=0; i<m; i++)  
        {  
            scanf("%d%d",&x,&y);  
            map[x][y]=1;  
        }  
        topo();  
        for(int i=1; i<n; i++)  
            printf("%d ",ans[i]);  
        printf("%d\n",ans[n]);  
    }  
    return 0;  
}  
