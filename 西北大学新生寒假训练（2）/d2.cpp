#include <cstdio>
int main()
{
int n,m,score[50][5],num;
while(~scanf("%d%d",&n,&m))
{
double ans[2][50];
for(int i=0,sum=0;i<n;i++,sum=0)
{
for(int j=0;j<m;j++)
{
scanf("%d",&score[i][j]);
sum=sum+score[i][j];
}
ans[0][i]=(double)sum/m;//��ƽ��������ans[0][i]��
} //��0��Ϊÿ��ѧ����ƽ����

for(int i=0,sum=0;i<m;i++,sum=0)
{
for(int j=0;j<n;j++)
{
sum=sum+score[j][i];
}
ans[1][i]=(double)sum/n;
}//��ÿ�ſε�ƽ���ĳɼ�
num=0;
for(int i=0,flag=1;i<n;i++,flag=1)
{
for(int j=0;j<m;j++)
{
if(score[i][j]<ans[1][j])
{flag=0;break;}
}
if(flag)
num++;
}//���Ҹ��Ƴɼ������ھ�¦
for(int i=0;i<n;i++)
printf(i==n-1?"%.2lf\n":"%.2lf ",ans[0][i]);
for(int i=0;i<m;i++)
printf(i==m-1?"%.2lf\n":"%.2lf ",ans[1][i]);
printf("%d\n\n",num);
}
return 0;
}
