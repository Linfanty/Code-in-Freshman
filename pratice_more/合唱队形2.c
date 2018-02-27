//合唱队形 最长上升序列
#include <stdio.h>
#define max(a,b) a>b?a:b
const int maxn=105;
int n;
int T[105],i,j;
int f1[105],f2[105];
int main()
{

    scanf("%d",&n);
    for(i=1;i<=n;i++) scanf("%d",&T[i]);
    for(i=1;i<=n;i++) {f1[i]=1;f2[i]=1;}
    for(i=1;i<=n;i++)
        for(j=i;j>=1;j--)
           if(T[j]<T[i])
              f1[i] = max(f1[i],f1[j]+1);
    for(i=n;i>=1;i--)
        for(j=i;j<=n;j++)
            if(T[j]<T[i])
              f1[i] = max(f1[i],f1[j]+1);
    int num=0;
    for(i=1;i<=n;i++) num = max(num,f1[i]+f2[i]-1);
    printf("%d\n",n-num);
    system("pause");
    return 0;
} 
