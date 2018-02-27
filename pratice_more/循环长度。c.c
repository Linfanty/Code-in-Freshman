//循环长度
#include<stdio.h>
main()
{unsigned long n,m,m1;
int k;
int l=0,l1=1;
int m2;
FILE * in;
 FILE * out;
 in=fopen("d:\\in.txt","r");
 out=fopen("d:\\out.txt","w"); 
fscanf(in,"%d %d",&n,&k);
int k1=1,i;
     for(i=1;i<=k;i++)
k1=k1*10;

m1=n%k1;
m2=(m1*m1)%k1;
while(m1!=m2)
{
m2=((m2*m1)%k1);
++l;
l1++;
if(l1==100)
break;
}

if(l1==100)
fprintf(out,"%d",-1);
else fprintf(out,"%d",l);
    fclose(in);
    fclose(out);
    return 0;
}
/*
//循环长度
#include<stdio.h>
main()
{unsigned long n,m,m1;
unsigned long k;
unsigned long l=0,l1=1;
unsigned long m2;

scanf("%d %d",&n,&k);
int k1=1,i;
     for(i=1;i<=k;i++)
k1=k1*10;

m1=n%k1;
m2=(m1*m1)%k1;
while(m1!=m2)
{
m2=((m2*m1)%k1);
++l;
l1++;
if(l1==100)
break;
}

if(l1==100)
printf("%d",-1);
else printf("%ld",l);
    
    return 0;
}
*/
