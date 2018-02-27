#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag = 0;
int count = 0;
int main(void)
{
    int n, m=3, a[100001];
    int j, i;
   // system("COLOR 1f");
    printf("Enter n:");
    scanf("%d", &n);
   // printf("Enter m:");
  //  scanf("%d", &m);
    memset(a,0,sizeof(a));
    while (flag<n)
    {
        for (i = 1; i <= n; i++)
        {
 
            if (a[i] == 0)
            {
 
                count++;
                printf("%d\n",count);
                if (count%m == 0)
                {
                    a[i] = 1;
                    flag++;
                    printf("第%d次，第%d个出列\n", flag, i);
                }
            }
        }
    }
    return 0;
}
