#include<stdio.h>
int main()
{FILE * in;
FILE * out;
long int a[0],n,i;
in=fopen("D:\\in.txt","r");
out=fopen("D:\\out.txt","w");
fscanf(in,"%d",&a[0]);
//n=a[0];
//for(i=0;i<=n;i++)
//fscanf(in,"%d",&a[i]);
for(i=0;i<=n;i++)
{fprintf(out,"%d",a[i]);
//if(i!=n)
//fprintf(out," ");
}
fclose(in);
fclose(out);
    }





