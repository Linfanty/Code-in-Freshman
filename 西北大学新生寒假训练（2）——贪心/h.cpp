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
	int deadline;
	int reduce;
	int use;
}node[1001];

bool cmp(Node x,Node y)
{
	if( x.reduce == y.reduce ) return x.deadline < y.deadline;
	return x.reduce > y.reduce ;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int m;
		scanf("%d",&m);
		for(int j=0;j<m;j++)
			scanf("%d",&node[j].deadline );
		for(int j=0;j<m;j++)
			scanf("%d",&node[j].reduce );
			
		for(int j=0;j<m;j++)
		node[j].use=0;
		
		sort(node, node +m, cmp);
		
		int k;
		int sum=0;
		for(int j=0;j<m;j++)
		{
			for(k= node[j].deadline  ;k>0;k--) //从后往前罚时  
			{
				if( node[k].use ==0 )
				{
					node[k].use =1;
					break;
				}
				
			}
			if( k == 0)
			 sum += node[j].reduce ;
		}
		
		
		
		
		printf("%d\n",sum);
	}
	return 0;
}
