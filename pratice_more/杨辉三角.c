#include<stdio.h>
int main()
{
int a,b,c[11][11]={0};
int i,j;
c[0][0]=1,c[1][0]=1;c[1][1]=1;
for(i=0;i<10;i++)
c[i][0]=1;
for(i=2;i<10;i++)
for(j=1;j<10;j++)
    {
    c[i][j]=c[i-1][j]+c[i-1][j-1];
    }
    for(i=0;i<10;i++)
    for(j=0;j<10;j++)
    {if(c[i][j]!=0)
    printf("%d ",c[i][j]);
    if(j-i==0)
    printf("\n");
    }    
system("pause");
} 
