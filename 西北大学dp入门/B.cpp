#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <climits>
#include <queue>
#include <map>
#include <set>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define maxn 100005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)

int main()
{
	int dp[60] = {0};
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	dp[4] = 4;
	dp[5] = 6;
	
	//ȥ���ĸţ��ֻҪû�������������������f(n-1)ͷ��
	//���������ĸţ�ж��٣���ǰ��(��n-3��)�ж���ͷĸţ��
	//��ô���˽�����Щţ������Сţ�ˣ���˳�����Ϊf(n-3)
	
	//f(n)=f(n-1)+f(n-3)
	
	rep( i, 5, 55)
	{
		dp[i] = dp[i-1] + dp[i-3]; // 
	}
	
	int n;
	while( cin>>n  )
	{
		if(n==0)
		break;
		cout<<dp[n]<<endl;
	}
}
