#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h> 

int main()
{
long int a,b,c[11],d[11],last=0,first=0;
long int num=1,sum=0;
memset(c,0,sizeof(c));
memset(d,-1,sizeof(d));
int i,j,k=0;
scanf("%ld %ld",&a,&b);

c[0]=6;c[1]=2;c[2]=5;c[3]=5;c[4]=4;c[5]=5;c[6]=6;c[7]=3;c[8]=7;c[9]=6;
for(i=a;i<=b;i++)
{num=i;
while(num!=0)
   {
   d[k]=(num%10);
   num=num/10;
   k++;
    }
for(j=0;j<7;j++)
if(d[j]!=-1)
sum+=c[d[j]];

k=0;               
memset(d,-1,sizeof(d));   
}    
printf("%ld",sum);    
system("pause");
return 0;
}

/*

for(i=1;i<8;i++)
{
k=pow(10,i);
c[i]=a/k;
d[i]=b/k;
if(c[i]==0&&c[i-1]!=0)
first=i;
if(d[i]==0&&d[i-1]!=0)
last=i;
}

if(fist==1&&last==1)
for(i=a;i<=b;i++)
sum+=c[i];

if(first==1&&last==2)
for(i=a;i<=b ;i++)
{
sum+=c[i];
}

if(first==1&&last==3)
if(first==1&&last==4)
if(first==1&&last==5)
if(first==1&&last==6)

if(first==2&&last==2)
if(first==2&&last==3)
if(first==2&&last==4)
if(first==2&&last==5)
if(first==2&&last==6)

if(first==3&&last==3)
if(first==3&&last==4)
if(first==3&&last==5)
if(first==3&&last==6)

if(first==4&&last==4)
if(first==4&&last==5)
if(first==4&&last==6)

if(first==5&&last==5)
if(first==5&&last==6)

if(first==6&&last==6)

*/


/*
if(b==1)
for(i=a;i<b;i++)
sum+=c[i];

if(b==2)
for(i=a;i<b;i++)
sum+=c[i];

if(a<10&&b>=10)
for(i=a;i<10;i++)
sum+=c[i];


if(a>=10,b<100)
for(i=a;i<10;i++)
sum+=c[i];
*/


//printf("%ld %ld\n",first,last);
