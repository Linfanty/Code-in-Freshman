#include<cstdio>
#include<cstring>
using namespace std;
int f[10005][10];
int main()
{
    //freopen("int.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    memset(f,0,sizeof(f));
    for(int i = 1;i < 10005;i++)
    {
        for(int j = 0;j < 10;j++)
            f[i][j] = f[i - 1][j];
        int left = i;
        while(left)
        {
            f[i][left % 10]++;
            left /= 10;
        }
    }
    int T,N;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&N);
        for(int i = 0;i < 9;i++)
            printf("%d ",f[N][i]);
        printf("%d\n",f[N][9]);
    }
    return 0;
}
