//DP���� 
#include<stdio.h>
int S,T,M,a[10000],f[10000],d[101],max,sol;
long L,array[101];
 
void init()  /* ���ݶ��� */
{
  int i;
  scanf("%ld%d%d%d",&L,&S,&T,&M);
  array[0]=-1;
  for(i=1;i<=M;i++)
    scanf("%ld",&array[i]);
}
void select(long a[], int count)   /* ��ʯ�ӳ��ֵ�λ������ */
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
/* ��ճ����ĳ��ȣ���ѹ���ճ��� */
/* �ӵ�1��ʯ�ӿ�ʼѹ��������1��ʯ�ӵ�λ����������������С����S֮�����max,��Ӧѹ����ѹ����d=array[1]-array[0]-max,����array[1]��ֵ: array[1]=array[1]-d; �ӵڶ���ʯ�ӣ�i>=2)��ʼ������i��ʯ��λ�����i-1��ʯ��λ�ã�ע���i-1��ʯ��λ������һ��ѭ���и����ˣ�������Ϊd��֮�����d+max,��Ӧѹ����i-1���i��ʯ�Ӽ�Ŀ����ӣ�������ѹ����d��ֵ��d=array[i]-array[i-1]-max��������Ҫѹ������ѹ����d����ԭֵ���䣻�����Ƿ�ѹ������Ӧ����array[i]��ֵ:array[i]=array[i]-d;(��Ϊd��Ϊ0)������array[0]=S,d=0,���1��ʯ��Ҳ�������Ϲ���  */
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
  for(i=1;i<=M;i++)a[array[i]]=1; /* ������a���������Щλ�ã���ѹ������µ�λ�ã���ʯ�� */
  /*  ���¶�̬�滮������f��ֵ  */
  f[0]=0;     /* ��ʼ�� */
  for(i=1;i<array[M]+T;i++) f[i]=100;  /* ��ʼ�� */
  for(i=S;i<=T;i++) f[i]=a[i];
  for(i=T+1;i<array[M]+T;i++)   /* ѹ������������array[M] �� array[M]+T-1����һλ�þ�������� */
  {
    for(j=i-T;j<=i-S;j++)
      if(f[i]>f[j]+a[i]) f[i]=f[j]+a[i];
  }
  /* ����������� */
  sol=100;
  for(i=array[M];i<array[M]+T;i++)
    if(f[i]<sol)sol=f[i];//����
}
 
int main()
{
  int k;
  freopen("river.in","r",stdin);
  freopen("river.out","w",stdout);
  init();
  if(T==S)
  {
    sol=0;  /* T=S�����Σ�ֱ�Ӽ���  */
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

