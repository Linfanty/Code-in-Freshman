#include<stdio.h>
int main()
{
    int k,i,j,a[10];
    for(i=0;i<5;i++)
    scanf("%d",&a[i]);
    for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    {if(a[i]<=a[j])
    {k=a[i];a[i]=a[j];a[j]=k;}
    }
    for(i=0;i<5;i++)
    printf("%d ",a[i]);
    system("pause");
    
}
