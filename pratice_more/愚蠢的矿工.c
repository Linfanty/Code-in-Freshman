//PID30 / [stupid]ÓÞ´ÀµÄ¿ó¹¤
#include<stdio.h>
main()
{int n,m,i,j,k[1001],sum=0,count=0;
int a[1001],b[1001],p=0;
FILE * in;
 FILE * out;
 in=fopen("d:\\in.txt","r");
 out=fopen("d:\\out.txt","w"); 
fscanf(in,"%d %d",&n,&m);
for(i=1;i<=n;i++)
fscanf(in,"%d",&k[i]);
for(i=1;i<=n;i++)
fscanf(in,"%d %d",&a[i],&b[i]);

for(j=1;j<=n;j++)
{

for(i=1;i<=n;i++)
{if(a[i]==p)
{sum=sum+k[i];
count++;
}
if(count==m&&i==4)
fprintf(out,"%d",sum);
}
 p++;
} 
 
    fclose(in);
    fclose(out);
    return 0;
}
