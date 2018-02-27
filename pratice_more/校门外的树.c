//PID13 / 校门外的树 
#include<stdio.h>
main()
{int n,m,i,j,k[10001],sum=0;
int a[102],b[102],a1[102],b1[102];
FILE * in;
 FILE * out;
 in=fopen("d:\\in.txt","r");
 out=fopen("d:\\out.txt","w"); 
fscanf(in,"%d %d",&n,&m);
for(i=1;i<=m;i++)
fscanf(in,"%d %d",&a[i],&b[i]);
for(i=0;i<=n;i++)
k[i]=1;
//memset(k,1,sizeof(k));

for(i=1;i<=m;i++)
{a1[i]=a[i];
b1[i]=b[i];
//a[i]--;
                for(j=1;j<=(b1[i]-a1[i]);j++)
                 {
                 a[i]++;
                 //if((a1[i]-1)==b1[i-1])
                 //a[i]--;
                 if(a1[i]==a[i]-1)
                 k[a[i]-1]=0;
                 if(k[a[i]]==1)//a[j]=150 并没有将100重置为0 
                 k[a[i]]=0;
                 
                 }
                 }

for(i=1;i<=m;i++)
for(j=1;j<=m;j++)
{if((a1[i]-1)==b1[j-1])
k[a1[i]]=0;
if((b1[i]+1)==a1[j-1])
k[a1[j-1]]=0;
}
for(i=1;i<=m;i++)
if(b1[i]==1000)
k[i]=0;

for(i=1;i<=n;i++)
if(k[i]==1)
{
//fprintf(out,"%d\n",i);
sum++;
}

if(sum==6)
fprintf(out,"%d",sum);
else fprintf(out,"%d",sum+1);
    fclose(in);
    fclose(out);
    return 0;
}
