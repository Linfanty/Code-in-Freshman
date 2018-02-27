#include<stdio.h>
#include<string.h>
#include<stdlib.h>
using namespace std;
int  main()
{
  int i,j,n,m;
  char g[200][1010],s[1010];
  scanf("%d",&n);
  getchar();
  gets(s);
  for(i=0;i<=110;i++)
  {
    for(j=0;j<=1005;j++)//以为要涉及补全矩形,就全重置为空格
      g[i][j]=' ';
  }
  int x=0,y=0;
  for(i=0;s[i];i++)
  {
    g[y][x++]=s[i];
    if(x%n==0)
    {
      y++;x=0;
    }
  }
  /*for(i=0;i<5;i++)
  {
    for(j=0;j<4;j++)
    {
      printf("%c",g[i][j]);
    }
    printf("\n");
  }*/
  if(x==0) y--;
  for(j=0;j<n;j++)
  {
    for(i=y;i>=0;i--)
    {
      printf("%c",g[i][j]);
    }
    printf("\n");
  }
}
