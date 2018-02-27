#include<stdio.h>
#include<string.h>
main()
{char ch;
 int a[100] ,n,i,m;
 int lk,lc;
 int is[1000];
 char k[100],c[1000];
FILE *in;
FILE *out;
in=fopen("D:\\in.txt","r");
out=fopen("D:\\out.txt","w");
fscanf(in,"%s\n%s",k,c);
lk=strlen(k);
lc=strlen(c);//lcÃÜÎÄ
for(i=0;i<lc;i++)
{
if(c[i]>='A'&&c[i]<='Z')
{
c[i]=c[i]+32;
is[i]=1;
}
else if(c[i]>='a'&&c[i]<='z')
{
is[i]=0;
}
}
//1huo0
for(i=0;i<lc;i++)
{
if(k[i]>='A'&&k[i]<='Z')
{
k[i]=k[i]+32;
}
}
//×ª»»
for(i=0;i<lc;i++)
{
c[i]=(c[i]-k[i%lk]+26)%26+'a';
}
for(i=0;i<lc;i++)
{
if(is[i])

fprintf(out,"%c",c[i]-32);
else
fprintf(out,"%c",c[i]);
}

   fprintf(out,"%d",48%26);
fclose(in);
fclose(out);
}
