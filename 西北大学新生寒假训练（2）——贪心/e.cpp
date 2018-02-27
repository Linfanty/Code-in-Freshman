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
	int l;
	int w;
	int used;
}node[5005];

bool cmp(Node x,Node y)
{
	if(x.l == y.l ) return x.w < y.w ;
	return x.l < y.l ;
}

int main()
{
	int n,t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		
			for(int i=0;i< n;i++)
				{scanf("%d %d",&node[i].l , &node[i].w );  node[i].used =0;}
			sort(node, node + n,cmp);	
			
			int sum=0;
			for(int i=0;i<n;i++)
			{
				if(!node[i].used )
				{
					sum++;
					node[i].used = 1;
					for(int j=i ; j<n ;j++)
					{
						if(node[j].l>= node[i].l && node[j].w >= node[i].w  && node[j].used == 0)
						{
							node[j].used = 1;
							node[i].l = node[j].l  ;
							node[i].w = node[j].w  ;
							continue;
						}
					
					}
					
				}
				
			}
		printf("%d\n",sum);
	}
	
	
return 0;
}
