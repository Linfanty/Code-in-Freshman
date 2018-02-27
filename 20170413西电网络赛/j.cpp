//ถþฮฌสýื้ 
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int MAXN=10005;
const int INF=100000;
int n = 10005, m, dis[MAXN][MAXN];

void floyd()
{
    for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
}

int main()
{
	int t;
	scanf("%d",&t);
	
    while( t-- )
    {
    	scanf("%d",&m);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
              dis[i][j]=INF;
        
    	//printf("sssssss\n");
        
        for(int i=0;i<m;i++)
        {
            int from,to,val;
            scanf("%d%d%d",&from,&to,&val);
            
            if(dis[from][to] > val)
                dis[to][from] = dis[from][to] = val;        
        }
        
        int s,t;
        scanf("%d%d",&s,&t);
        
        floyd();
        
		if(s==t)
		{
			printf("0\n");
			continue;
		}
        else
            printf("%d\n",dis[s][t] * 2);
            
    }
    return 0;

}
