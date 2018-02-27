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

//aiemckgobjfndlhp 20 
// A C G J L P     6

int main()
{
	string s;
	cin>> s;
	int dp[105];
	
	int len = s.size(), max1 = 0 ;
	/*
	��dp[i]��ʾǰi���ַ��ܴճ����������е���󳤶�
	dp[i] = max(dp[j]+1, dp[i]) 
	��j < i && s[j] < s[i]��
	*/
	//http://blog.sina.com.cn/s/blog_6ceb295d0100lzut.html
	rep( i, 1, len) 
	{
		dp [i] = 1;
		
		rep( j, 1, i-1)
		{
			cout<<"i:"<<i<<" j:"<<j<<' '<<s[j-1] << ' ' << s[i-1]
				<<' '<< dp[i] << ' '<< dp[j]+1 <<endl;
			/*
				ö��һ��Ԫ�� ֮ǰ��ÿһ��Ԫ�� 
				�� ǰ���Ԫ�� ��  �����С
				�� ��ǰԪ�� = max( i , j+1 )  
				i:3 j:1 a e 1 2
				i:3 j:1 a e 2 2
				i:3 j:2 i e 2 3
				i:3 j:2 i e 2 3
				dp[j] + 1
			*/
			
			if( s[j-1] < s[i-1] )
				dp[i] = max (dp[j] + 1, dp[i]);
			cout<<"i:"<<i<<" j:"<<j<<' '<<s[j-1] << ' ' << s[i-1]
				<<' '<< dp[i] << ' '<< dp[j]+1 <<endl;				
		}
		cout<<endl<<endl;
		max1 = max ( max1, dp[i] );
	
	}
	
	cout << 26 - max1 <<endl;
	

	return 0;
}







