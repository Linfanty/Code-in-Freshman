#include <stdio.h>
#include <string.h>
int main()
{
char k[100],m[1000]; 
int is[1000];
int kn=0,mn=0; 
int i=0; 

freopen("vigenere.in","r",stdin);
freopen("vigenere.out","w",stdout);

scanf("%s\n%s",k,m);
kn=strlen(k);
mn=strlen(m);

for(i=0;i<mn;i++)
{
if(m[i]>='A'&&m[i]<='Z')
{
m[i]=m[i]+32;
is[i]=1;
}
else if(m[i]>='a'&&m[i]<='z')
{
is[i]=0;
}
}

for(i=0;i<kn;i++)
{
if(k[i]>='A'&&k[i]<='Z')
{
k[i]=k[i]+32;
}
}

for(i=0;i<mn;i++)
{
m[i]=(m[i]-k[i%kn]+26)%26+'a';
}
for(i=0;i<mn;i++)
{
if(is[i])
printf("%c",m[i]-32);
else
printf("%c",m[i]);
}
fclose(stdin);
fclose(stdout);
return 0;
}
