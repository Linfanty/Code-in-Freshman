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
				printf("����ɼ���Ϊ����,����������ɼ���\n");
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
	
	printf("��ʾ�������������Ϊ����\n");
	printf("      ÿ�ж�Ҫ�Իس�����Ϊ������������Ľ�����־\n");
	printf("      �������������ϸ�ѧ������ɼ�������back\n");
	printf("      ������������ĳ��ѧ������ɼ�������new\n\n");
	
	int tote;//��� 
	char s[maxn];//�Ż� 
	printf("������ȫ���������");
	scanf("%s",s);

	printf("\n");
	tote = atoi(s);
	
	while(tote <= 0 )
	{
		printf("����������Ϊ���ֻ�������С�ڵ���0�ˣ�����������ȫ���������");
		scanf("%s",s);
		
		tote = atoi(s);	
		printf("\n");
	}
	
	int sum = 0 ;
	int score[maxn];
	
	for(int i=1 ; i<=tote ; i++) 
	{
		printf("�������%dλѧ���ĳɼ���ָ�", i );
		
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
			printf("������ڼ���ѧ��:");
			int newx;
			scanf("%s", person );
			
			while( !judge_noalnum() || atoi(person) > tote || atoi(person) <=0 )
			{
				printf("�������,������ڼ���ѧ��:");
				scanf("%s", person );
			}
			
			newx = atoi(person);
			
			printf("�������%d��ѧ���ĳɼ�:",newx);
			
			scanf("%s" , person);
			while( !judge_noalnum() || atoi(person)<=0 || atoi(person) > 100 )
			{
				printf("�������,�������%d��ѧ���ĳɼ�:",newx);
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
			printf("����ɼ�С�ڵ���0���ߴ���100������������ɼ���\n");
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
	printf("\n�ð���%d���ˣ��༶ƽ���ɼ�Ϊ:%d��\n��%d%%ѧ���ĳɼ����ڰ༶ƽ���ɼ�\n", tote, average, selected*100/tote );
	printf("��߷���Ϊ��%d��\n", max1 );
	printf("��ͷ���Ϊ��%d��\n", min1 );
	getchar();
	getchar();

return 0;
}
