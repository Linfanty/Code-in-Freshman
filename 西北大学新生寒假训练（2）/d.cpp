#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int main()
{
    double a[55][6];
    double n,m;
    while(scanf("%lf %lf",&n,&m)!=EOF)
    {
        double sum1[55];
        double sum2[6];
        int sum=0;
        memset(a,0,sizeof(a));
        memset(sum1,0,sizeof(sum1));
        memset(sum2,0,sizeof(sum2));
            for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            {
                scanf("%lf",&a[i][j]);
                sum1[i]+=(double)a[i][j];
                sum2[j]+=(double)a[i][j];
            }
            
            for(int i=0;i<n;i++)
            {
                if(!i)
                printf("%.2lf",sum1[i]/m);
                else
                printf(" %.2lf",sum1[i]/m);
            }
            printf("\n");
            
                for(int i=0;i<m;i++)
            {
                if(!i)
                printf("%.2lf",sum2[i]/n);
                else
                printf(" %.2lf",sum2[i]/n);
            }
            printf("\n");
            int count =0;
                for(int i=0;i<n;i++)
                {
                for(int j=0;j<m;j++)
                {
                    if(a[i][j]>=(double)sum2[j]/n)
                    count++;
                    if(count==m)
                    sum++;
                    
                
                    
                }
                count=0;
                }
                printf("%d\n\n",sum);
    }
return 0;
}
