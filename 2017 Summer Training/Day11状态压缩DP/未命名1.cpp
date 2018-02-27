#include <iostream>
#include <string.h>
#define mod 1000000007
using namespace std;
int n,m;
int dp[21][1<<20];
void dfs(int j,int i,int state,int nex)
{
	if (j==m)
	{
		dp[i+1][nex]+=dp[i][state];
		dp[i+1][nex]%=mod;
		return ;
	}
	//这个位置不能填
	if (((1<<j)&state)>0) dfs(j+1,i,state,nex);
	else
	{
		//竖着
		dfs(j+1,i,state,nex|(1<<j));/// 竖着时nex状态才增加 001 100
		//横着
		if (j+1<m && ((1<<(j+1))&state)==0)
			dfs(j+2,i,state,nex); /// 横着nex状态不增加 继续下一个dfs 竖着j+1时nex才增加
	}
}

int main()
{
	while (cin>>n>>m)
	{
		memset(dp,0,sizeof(dp));
		dp[0][0]=1;
		for (int i=0;i<n;i++)
			for (int state=0;state<(1<<m);state++)
			if (dp[i][state]) /// dp 不为零 至少为1才有情况
			{
				dfs(0,i,state,0);
				cout << i << ' ' << state <<' ' << dp[i][state] << "     " << endl;
			}
		cout<<dp[n][0]<<endl;
	}
}
