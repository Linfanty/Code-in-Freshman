#include<stdio.h>
/*
void energy1(long int s[],long int i,long int j,long int n)
{long int i1=i,j1=j;
long int sum,sum1,sum2;
long int b[1000][1000];
if(i==j)
b[i][j]=0;
if((i+1)%n==j)
b[i][j]=s[i]*s[(i+1)%n]*s[(i+2)%n];
long int k=i1;
for(k=i1;k<j;k++)
{  energy1(s,i,k,n);
   energy1(s,k+1,j,n);
   sum=s[i]*s[k]*s[(j+1)%n];
}
     
     }
*/
main()
{   int a[1000],energy[100][100],f[100][100];
    int i,j,k;
    int sum=0,ans=0;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {scanf("%d",&a[i]);
    a[i+n]=a[i];}
    
    //memset(f,0,sizeof(f));
    
    for(i=1;i<2*n-1;i++)
    for(j=i-1;j>=1&&i-j<n;j--)
    {
                              for(k=j;k<i;k++)
                              {sum=f[j][k]+f[k+1][i]+a[j]*a[k+1]*a[i+1];
                              if(sum>f[j][i])
                              f[j][i]=sum;
                                              
                              } 
    if(f[j][i]>ans)
    ans=f[j][i];
    }
    
    
    
    
    
    
    /*for(i=0;i<n-1;i++)
    {sum+=a[i]*a[i+1];}*/
    printf("%d\n",ans);
//return 0;
system("pause");
}
