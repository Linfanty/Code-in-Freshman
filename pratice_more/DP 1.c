#include<stdio.h>
int c[10][100];
int knapsack(int m,int n)
{
    int i,j,w[10],p[10];
    for(i=1;i<n+1;i++)
    scanf("\n%d,%d",&w[i],&p[i]);
    for(i=0;i<10;i++)
    for(j=0;j<100;j++)
    c[i][j]=0;
    for(i=1;i<n+1;i++)
    for(j=1;j<m+1;j++)
    {
        if(w[i]<=j){
             if(p[i]+c[i-1][j-w[i]]>c[i-1][j])
                 c[i][j]=p[i]+c[i-1][j-w[i]]; 
             else
                 c[i][j]=c[i-1][j];
        }else 
             c[i][j]=c[i-1][j];
     }
     return(c[n][m]);
}
int main()
{
    int m,n;int i,j;
    printf("input the max capacity and the number of the goods:\n");
    scanf("%d,%d",&m,&n);
    printf("Input each one(weight and value):\n");
    printf("%d",knapsack(m,n));
    printf("\n");
    for(i=0;i<10;i++)
        for(j=0;j<15;j++)
        {
             printf("%d ",c[i][j]);
             if(j==14)printf("\n");
        }
    system("pause");
}

