#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

struct Node
{
	int a;
	int b;
}node[105];

bool cmp(Node x,Node y)
{
//	if(x.b == y.b ) return x.a < y.a ;
	return x.b < y.b ;
}

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{
		for(int i=0;i<n;i++)
		scanf("%d %d",&node[i].a ,&node[i].b);
		
		sort(node,node + n,cmp);
		int mid = node[0].b ;
		int count = 1;
	
		for(int i=1;i<n;i++)
		{
			if(node[i].a >= mid  )
			{
				count ++ ;
				mid = node [i].b ;
			}
		}
		printf("%d\n",count);
	}
	
return 0;
}
