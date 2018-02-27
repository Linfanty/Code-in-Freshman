#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<climits>
typedef long long ll;
const int maxn = 105;
using namespace std;

int main()
{
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
int n,t;
	scanf("%d",&n);
	while(scanf("%d",&t)!=EOF)
	{
		int sum=3;
		for(int i=0;i<t;i++)
		sum=(sum-1)*2;
		printf("%d\n",sum);
	
	}
	return 0;
}
