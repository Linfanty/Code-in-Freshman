#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
using namespace std;

struct Node
{
	int c;
	int d;
	int count;
}node[500];

bool cmp(Node x,Node y)
{
//	if(x.d == y.d ) return x.c < y.c ;
	return x.c < y.c ;
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
			{
			scanf("%d %d",&node[j].c  ,& node[j].d );
			if(node[j].c >node[j].d )
			swap(node[j].c ,node[j].d);
			}
		sort(node, node +m, cmp);
		//ll mid =0;
	for(int j=0;j<500;j++)
	node[j].count =0;
		/*	
		for(int j=node[0].c ;j<= node[0].d ;j++)
		node[j].count ++;
		*/
		for(int j=0;j<m;j++)
		{
			/*
			if(node[j].c < node[j-1].d && node[j].d >node[j-1].d && node[j-1].c < node[j].c  ) //node[j].c node[j-1].d 在中间 
			{
				for(int k= node[j].c ;k<=node[j-1].d ;k++)
				node[k].count  ++;		
			}
			else if(node[j].c >node[j-1].c && node[j].d <node[j-1].d )// node[j] 整体在中间 
			{
				for(int k=node[j].c ;k<= node[j].d ;k++)
				node[k].count  ++;	
			}
			else if(node[j].c < node[j-1].c && node[j].d < node[j-1].d &&node[j].d >node[j-1].c)//node[j].d node[j-1].c 在中间 
			{
				for(int k= node[j-1].d ;k<=node[j].c ;k++)
				node[k].count  ++;	
			}
			else if(node[j].c < node[j-1].c && node[j].d > node[j-1].d )//node[j-1] 整体在中间 
			{
				for(int k= node[j-1].c ;k<=node[j-1].d ;k++)
				node[k].count  ++;	
			}
			*/
			if(node[j].c % 2 == 1 && node[j].d % 2 == 1 ) // 1 5
			for(int k=node[j].c ;k<= node[j].d+1 ;k++)
				node[k].count  ++;	
				
			else if(node[j].c % 2 == 1 && node[j].d % 2 == 0  ) // 1 6
				for(int k=node[j].c ;k<= node[j].d ;k++)
				node[k].count  ++;	
				
			else if(node[j].c % 2 == 0 && node[j].d % 2 == 1  ) // 2 5
				for(int k=node[j].c -1 ;k<= node[j].d+1 ;k++)
				node[k].count  ++;	
					
			else if(node[j].c % 2 == 0 && node[j].d % 2 == 0  ) // 2 6
			for(int k=node[j].c -1 ;k<= node[j].d ;k++)  
				node[k].count  ++;	
				
			/*	
			for(int k=node[j].c ;k<= node[j].d ;k++)
				node[k].count  ++;	
			*/
				
		}
		int max= 0;
		for(int j=0;j<401;j++)
		{
			//printf("%d\n",node[j].count );
			if(node[j].count >max)
				max = node[j].count ;
		}
		
		printf("%d\n",max*10);
	}
	return 0;
}
