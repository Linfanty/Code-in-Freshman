#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
#define maxn 12
int n,num[maxn][maxn];
char m[maxn][maxn],mm[maxn][maxn];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                num[i][j]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",m[i]+1);
            for(int j=1;j<=n;j++)
                if(m[i][j]=='*')
                {
                    for(int dx=-1;dx<=1;dx++)
                        for(int dy=-1;dy<=1;dy++)
                            num[i+dx][j+dy]++;
                    num[i][j]=-1;
                }
        }
        int flag=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%s",mm[i]+1);
            for(int j=1;j<=n;j++)
                if(mm[i][j]=='x'&&m[i][j]=='*')
                    flag=1;
        }
        if(flag)
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    if(mm[i][j]=='x'&&m[i][j]!='*')printf("%d",num[i][j]);
                    else printf("%c",m[i][j]);
                printf("\n");
            }
        else
            for(int i=1;i<=n;i++)
            {
                for(int j=1;j<=n;j++)
                    if(mm[i][j]=='x')printf("%d",num[i][j]);
                    else printf(".");
                printf("\n");
            }
    }
    return 0;
}
