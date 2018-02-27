//DP过河 
#include<stdio.h>
int S,T,M,a[10000],f[10000],d[101],max,sol;
long L,array[101];
 
void init()  /* 数据读入 */
{
  int i;
  scanf("%ld%d%d%d",&L,&S,&T,&M);
  array[0]=-1;
  for(i=1;i<=M;i++)
    scanf("%ld",&array[i]);
}
void select(long a[], int count)   /* 将石子出现的位置排序 */
{
  int i,j,temp;
  for(i=0;i<count;i++)        
  {
    temp=a[i];
    j=i-1;
    while(j>=0 && temp<a[j])
    {
      a[j+1]=a[j];
      j--;
    }
    a[j+1]=temp;
  }
}
/* 求空长条的长度，并压缩空长条 */
/* 从第1颗石子开始压缩，若第1颗石子的位置与青蛙能跳的最小步长S之差大于max,则应压缩，压缩量d=array[1]-array[0]-max,更新array[1]的值: array[1]=array[1]-d; 从第二颗石子（i>=2)开始，若第i颗石子位置与第i-1颗石子位置（注意第i-1颗石子位置在上一轮循环中更新了，更新量为d）之差大于d+max,则应压缩第i-1与第i颗石子间的空条子，更新总压缩量d的值：d=array[i]-array[i-1]-max，若否则不要压缩，总压缩量d保持原值不变；不论是否压缩，都应更新array[i]的值:array[i]=array[i]-d;(因为d不为0)。若令array[0]=S,d=0,则第1颗石子也适用以上规则。  */
void blank()
{
  int i;
  long d=0;
  array[0]=S;
  for(i=1;i<=M;i++)
  {
    if(d<array[i]-array[i-1]-max)
      d=array[i]-array[i-1]-max;
    array[i]=array[i]-d;
  }
}
void dbf()
{
  int i,j;
  memset(a, 0, sizeof(a));
  for(i=1;i<=M;i++)a[array[i]]=1; /* 用数组a标记桥上哪些位置（是压缩后更新的位置）有石子 */
  /*  以下动态规划求数组f的值  */
  f[0]=0;     /* 初始化 */
  for(i=1;i<array[M]+T;i++) f[i]=100;  /* 初始化 */
  for(i=S;i<=T;i++) f[i]=a[i];
  for(i=T+1;i<array[M]+T;i++)   /* 压缩后，青蛙跳到array[M] 至 array[M]+T-1的任一位置就算过桥了 */
  {
    for(j=i-T;j<=i-S;j++)
      if(f[i]>f[j]+a[i]) f[i]=f[j]+a[i];
  }
  /* 以下求最后结果 */
  sol=100;
  for(i=array[M];i<array[M]+T;i++)
    if(f[i]<sol)sol=f[i];//求结果
}
 
int main()
{
  int k;
  freopen("river.in","r",stdin);
  freopen("river.out","w",stdout);
  init();
  if(T==S)
  {
    sol=0;  /* T=S的情形，直接计算  */
    for(k=1;k<=M;k++)
      if(array[k]%T==0)sol++;
  }
  else
  {
    max=(2*T-S-2)/(T-S);
    max=max*T;
    select(array,M+1);
    blank();
    dbf();
  }
  printf("%d\n",sol); 
  return 0;
}

