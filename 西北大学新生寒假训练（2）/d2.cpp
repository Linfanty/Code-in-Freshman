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
ans[0][i]=(double)sum/m;//将平均数放入ans[0][i]中
} //第0行为每个学生的平均数

for(int i=0,sum=0;i<m;i++,sum=0)
{
for(int j=0;j<n;j++)
{
sum=sum+score[j][i];
}
ans[1][i]=(double)sum/n;
}//算每门课的平均的成绩
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
}//查找各科成绩均大于均娄
for(int i=0;i<n;i++)
printf(i==n-1?"%.2lf\n":"%.2lf ",ans[0][i]);
for(int i=0;i<m;i++)
printf(i==m-1?"%.2lf\n":"%.2lf ",ans[1][i]);
printf("%d\n\n",num);
}
return 0;
}
