#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
struct result
{
	char name[25];
	int num;
}people[1005];
bool cmp1(result x,result y)
{
	if(x.num ==y.num)
	return x.name<y.name;//name 不能直接比大小 
	else return x.num>y.num; 
}
/*bool cmp2(result x,result y)
{
	return x.name>y.name; 
}
*/
int main()
{
	int N,M,G,T,count=0;
	int m[25];
	int t;
	int score[1005];
	memset(score,0,sizeof(score));
	while(scanf("%d",&N)!=EOF)
	{
		if(N==0)
		break;
		scanf("%d %d",&M,&G);
		memset(score,0,sizeof(score));
		count=0;
		for(int i=1;i<=M;i++)
		scanf("%d",&m[i]);
		
		for(int i=1;i<=N;i++)
			{
				scanf("%s %d",people[i].name,&T);
				for(int j=1;j<=T;j++)
					{
						scanf("%d",&t);
						score[i]+=m[t];	
					}	
			}
		for(int i=1;i<=N;i++)
		{
			people[i].num=score[i];
				if(people[i].num>=G)
				count++;
		}
	sort(people+1,people+N+1,cmp1);
//	sort(people+1,people+N+1,cmp2);
	printf("%d\n",count);
	for(int i=1;i<=N;i++)
		{
			if(people[i].num>=G)
			printf("%s %d\n",people[i].name,people[i].num);
		}	
	}
	return 0;
}
