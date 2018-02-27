#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int flag = 0;
int count = 0;
int main(void)
{
	char s[65][16];
    int n, a[100001];
    int j, i;
    scanf("%d", &n);  
    
    memset(a,0,sizeof(a));
	memset(s,0,sizeof(s));
	
    for(int i=1;i<=n;i++)
    scanf("%s",s[i]);
    
    int w, m;
    scanf("%d,%d",&w,&m);
    strcpy(s[n+1],s[1]);
    while (flag<n)
    {
        for (i = w; i <= n+w-1; i++)
        {
 
            if (a[i] == 0)
            {
 
                count++;
                //printf("%d\n",count);
                if (count%m == 0)
                {
                    a[i] = 1;
                    flag++;
                    printf("%s\n",s[i]);
                }
            }
        }
    }
    return 0;
}
