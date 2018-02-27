#include<stdio.h>
#define max(a,b) a>b?a:b
main()
{long int t,m;
long int t1[1001],m1[1001];
long int i,j,f[1001][101];
 FILE * in;
 FILE * out;
 in=fopen("d:\\in.txt","r");
 out=fopen("d:\\out.txt","w"); 
fscanf(in,"%d %d",&t,&m);
for(i=1;i<=m;i++)
fscanf(in,"%d %d",&t1[i],&m1[i]);
for(i=1;i<=m;i++) 
for(j=0;j<=t;j++)
{if(j>=t1[i])
             f[i][j]=max(f[i-1][j],f[i-1][j-t1[i]]+m1[i]);
              else f[i][j]=f[i-1][j];
}



fprintf(out,"%d",f[m][t]);
    fclose(in);
    fclose(out);
    return 0;
}
