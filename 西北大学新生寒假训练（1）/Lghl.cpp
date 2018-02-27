/*有N个比赛队（1<=N<=500），编号依次为1，2，3，。。。。，N进行比赛，
比赛结束后，裁判委员会要将所有参赛队伍从前往后依次排名，
但现在裁判委员会不能直接获得每个队的比赛成绩，只知道每场比赛的结果，
即P1赢P2，用P1，P2表示，排名时P1在P2之前。现在请你编程序确定排名。 
*/
#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
int a[510][510]; 
int n,m,c[510]; 
int q[510];
void ppp()
{
	int i,j,top,k=0;
	for(j=0;j<n;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(c[i]==0) 
			{
				top=i;
				break;
			}
		}
		q[k++]=top;  //q[0]==1 就是没输过 序号小的排前面
		c[top]=-1;   
		for(i=1;i<=n;i++)  //输给这个人的人的输的次数减一
		{
			if(a[top][i])
			   c[i]--;
		}
	}
	for(i=0;i<k-1;++i)
	   printf("%d ",q[i]);
	printf("%d\n",q[k-1]);
} 

int main()
{
	int i,p1,p2;
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		memset(c,0,sizeof(c));  //表示输的次数 
		memset(a,0,sizeof(a));
		for(i=0;i<m;i++)
		{
			scanf("%d%d",&p1,&p2);
			if(a[p1][p2]==0)
			{
				a[p1][p2]=1;
			    c[p2]++;
			}
		}
		ppp();
	} 
	return 0;
}
/*-
就是没输过 序号小的排前面  //一定有一个没输过  

开始至少有一个人没输过

用一个数组记每个人输的次数

用一个数组记比赛结果

找出一个没输过 序号小的后   

输给这个人的人的输的次数减一

就这样循环
*/
