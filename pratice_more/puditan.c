# include<stdio.h>
# include<string.h>

struct node
{
    int a,b,g,k;
}map[100001];

int main()
{
    int i,n,x,y,ii,ans;
    while(scanf("%d",&n)!=EOF)
    {
        ans = -1;
        for(ii=1;ii<=n;ii++)
            scanf("%d%d%d%d",&map[ii].a,&map[ii].b,&map[ii].g,&map[ii].k);
        scanf("%d%d",&x,&y);
        for(ii=1;ii<=n;ii++)
        {
            if(map[ii].a<=x&&map[ii].a+map[ii].g>=x && map[ii].b<=y && map[ii].b+map[ii].k>=y)
            {
                ans = ii;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
