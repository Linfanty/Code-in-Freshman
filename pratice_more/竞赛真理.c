#include <stdio.h>
#define max(a,b) a>b?a:b
int main()
{
  // int f[1080001]={0};
    int f[100];
    int N,T,W1,P1,W2,P2,j;
    scanf("%d%d",&N,&T);
    for (;N>0;N--)
    {
        scanf("%d%d%d%d",&W1,&P1,&W2,&P2);
        for (j=T;j>=0;j--)
        {
            if (j>=P1) f[j]=max(f[j],f[j-P1]+W1);
            if (j>=P2) f[j]=max(f[j],f[j-P2]+W2);
        }
    }
    printf("%d",f[T]);
        system("pause");
    return 0;
}
