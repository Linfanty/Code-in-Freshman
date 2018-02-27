#include<stdio.h>
main()
{ long int a[10000],b[10000],c[10000],v[10000];
  long int a1[10000],b1[10000],c1[10000],v1[10000];
  long int f[100000];
 long int i,j,k,n,m;
scanf("%d%d",&m,&n);//m表示背包容量，n表示个数 
    for(i=0;i<n;i++)
    {
    scanf("%d%d",&a[i],&b[i]);
    v[i]=a[i]*b[i];
    }
    j=0;
    for(i=0;i<n;i++)
    {
                    if(b[i]==5)
                    {c[j]=a[i];
                     v1[j]=v[i];
                     j++;}
    }
    for(i=0;i<n;i++)
    {
                    if(b[i]==4)
                    {c[j]=a[i];
                     v1[j]=v[i];
                     j++;}
    }
    for(i=0;i<n;i++)
    {
                    if(b[i]==3)
                    {c[j]=a[i];
                    v1[j]=v[i];
                     j++;}
    }

    for(i=0;i<n;i++)
    {
                    if(b[i]==2)
                    {c[j]=a[i];
                    v1[j]=v[i];
                     j++;}
    }
    for(i=0;i<n;i++)
    {
                    if(b[i]==1)
                    {c[j]=a[i];
                    v1[j]=v[i];
                     j++;}
    }
 // for(i=0;i<n;i++)
 //{printf("%d %d\n",v1[i],c[i]);
 // }
    
for(i=0;i<n;i++)
{
 //       scanf("%d%d",&v,&w);//v=价值，w=重量
        for(j=m;j>=c[i];--j)
            if(f[j]<f[j-c[i]]+v1[i])
                f[j]=f[j-c[i]]+v1[i];
    }
    printf("%d\n",f[m]);
return 0;
}
      
