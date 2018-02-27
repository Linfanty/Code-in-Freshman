#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define maxn 100005
#define mem(a,b) memset((a),(b),sizeof((a)))
using namespace std;

int main()
{
	int T,n;
	int ans[maxn];
	mem(ans,0);
	
	for(int m=1;m<maxn;m++)
	{
		int x=m,y=m;
		
		while (x>0)
		{
			y+=x%10;                //数字的末尾数 y = y + x % 10  
			x/=10;          		//x=x/10 数字的前半部分 
		}
		if(ans[y]==0||m<ans[y])     //ans[y]==0||m<ans[y]
		ans[y]=m;
	}
		
		
		scanf("%d",&T);
		while(T--)
		{
			scanf("%d",&n);
			printf("%d\n",ans[n]);
		}
	return 0;
}

