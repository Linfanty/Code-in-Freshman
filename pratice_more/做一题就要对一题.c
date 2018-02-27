#include<stdio.h>
#define max(a,b) a>b?a:b
#define min(a,b) a<b?a:b
main()
{long int t;
int t1,m1,t2,m2,m;
int i=0,j=0;
long int f1[108001];
 FILE * in;
 FILE * out;
 in=fopen("d:\\in.txt","r");
 out=fopen("d:\\out.txt","w"); 
fscanf(in,"%d%ld",&m,&t);

//t=t/60;

/*for(i=1;i<=m;i++)
fscanf(in,"%d %d",&t1[i],&m1[i]);
for(i=1;i<=m;i++) 
for(j=0;j<=t;j++)
{//f[i][j]=(i==1?0:f[i-1][j]);

                 if(j>=t1[i])
             f[i][j]=max(f[i-1][j],f[i-1][j-t1[i]]+m1[i]);
             else f[i][j]=f[i-1][j];
} */
memset(f1,0,sizeof(f1));
for(i=1;i<=m;i++)
{fscanf(in,"%d%d%d%d",&m1,&t1,&m2,&t2);

//t1=t1/60; 
//t2=t2/60;

for(j=t;j>=0;j--)
 /* for(j=t;j>=min(t1,t2);j--)
     {
     if(j-t1>=0&&f[j]<f[j-t1]+w1) f[j]=f[j-t1]+w1;
     if(j-t2>=0&&f[j]<f[j-t2]+w2) f[j]=f[j-t2]+w2;
     }
 
*/
 {
 if(j>=t1) 
 f1[j]=max(f1[j],f1[j-t1]+m1);
 
 if(j>=t2) 
 f1[j]=max(f1[j],f1[j-t2]+m2);
 }

}

fprintf(out,"%ld",f1[t]);
//fprintf(out,"%d",f[m][t]);
    fclose(in);
    fclose(out);
    return 0;
}
