#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iostream>
#define maxn 1005
#define fin(i,a,b) for(int i=a ; i<b ;i++)
#define mem(a,b) memset(a,b,sizeof(a));
#define fre freopen("in.txt","r",stdin)
//#define  atoi atof
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

char person[105];

bool judge_noalnum()
{
		int size = strlen( person );
		for(int j = 0 ; j < size; j++ )
		{
			if( person[j] < '0' || person[j] >'9' )
			{
				printf("输入成绩不为数字,请重新输入成绩：\n");
				return false;
				break;
			}
		}
		return 1;
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	printf("提示：请输入的数据为整数\n");
	printf("      每行都要以回车键作为单个数据输入的结束标志\n");
	printf("      若想重新输入上个学生输入成绩，则打出back\n");
	printf("      若想重新输入某个学生输入成绩，则打出new\n\n");
	
	int tote;//最初 
	char s[maxn];//优化 
	printf("请输入全班的人数：");
	scanf("%s",s);

	printf("\n");
	tote = atoi(s);
	
	while(tote <= 0 )
	{
		printf("输入人数不为数字或者人数小于等于0人，请重新输入全班的人数：");
		scanf("%s",s);
		
		tote = atoi(s);	
		printf("\n");
	}
	
	int sum = 0 ;
	int score[maxn];
	
	for(int i=1 ; i<=tote ; i++) 
	{
		printf("请输入第%d位学生的成绩或指令：", i );
		
		int flag = 0 ;
		//char person[105];
		scanf("%s",person);
		
		if( strcmp(person,"back") == 0 )
		{
			if(i == 1)
			{
				i --;
				continue;
			}
		 	else i -= 2;
		 	continue;
		}
		
		if( strcmp(person,"new") == 0)
		{
			printf("请输入第几名学生:");
			int newx;
			scanf("%s", person );
			
			while( !judge_noalnum() || atoi(person) > tote || atoi(person) <=0 )
			{
				printf("输入错误,请输入第几名学生:");
				scanf("%s", person );
			}
			
			newx = atoi(person);
			
			printf("请输入第%d名学生的成绩:",newx);
			
			scanf("%s" , person);
			while( !judge_noalnum() || atoi(person)<=0 || atoi(person) > 100 )
			{
				printf("输入错误,请输入第%d名学生的成绩:",newx);
				scanf("%s" , person);
			}
				score[newx] = atoi(person);
			//scanf("%d" , &score[newx]);
			//printf("\n");
			
			i --;
			continue;
		}
		
	
		if( !judge_noalnum() )
		{
				i--;
				continue;
		}
		
		score[i] = atoi(person);
		//printf("%d  ",score[i]);
		
		if( score[i] <= 0 || score[i] >100 )
		{
			printf("输入成绩小于等于0或者大于100，请重新输入成绩：\n");
			i -- ;
			continue;
		}
		sum += score[i];
	}
	
	int average = sum / tote;
	int selected = 0;
	int max1 = 0;
	int min1 = 200;
	
	for(int i=1; i<= tote ; i++) 
	{
		if(score[i] > average )
		selected ++ ;
		min1 = min(min1, score[i]);
		max1 = max(max1, score[i]);
	}
	
	
	//printf("%d %d\n",selected,tote); 
	printf("\n该班有%d个人，班级平均成绩为:%d分\n有%d%%学生的成绩高于班级平均成绩\n", tote, average, selected*100/tote );
	printf("最高分数为：%d分\n", max1 );
	printf("最低分数为：%d分\n", min1 );
	getchar();
	getchar();

return 0;
}
