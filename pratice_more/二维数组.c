#include<stdio.h>
int main()
{
    int a[10][10];
    int i,j;
    while(scanf("%d",&a)==1)
    for(i=0;i<10;i++)
    for(j=0;j<10;j++)
    printf("%d",a[i][j]);
    
    system("pause");
    }
