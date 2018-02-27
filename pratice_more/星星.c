#include<stdio.h>
int main()
{int i,j;
int c[6][6];
for(i=0;i<5;i++)
    for(j=0;j<5;j++)
    {
    printf("*");
    if(j==4)
    printf("\n");
    if(i==0&&j==4)
    printf(" ");
    if(i==1&&j==4)
    printf("  ");
    if(i==2&&j==4)
    printf("   ");
    if(i==3&&j==4)
    printf("    ");
  
    }
    
system("pause");
} 
 
