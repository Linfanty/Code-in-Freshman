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
	double j;
	double f;
	int used;
}node[5005];

bool cmp(Node x,Node y)
{
	return (x.j / x.f ) > (y.j / y.f ) ;
}

int main()
{
	int m,n,t;
	while(scanf("%d %d",&m,&n)!=EOF&& m!=-1 )
	{		
			for(int i=0;i < n;i++)
				{scanf("%lf %lf",&node[i].j , &node[i].f );  node[i].used =0;}
			sort(node, node + n,cmp);	
			
			double sum=0;
			for(int i=0;i<n;i++)
			{
				if( !node[i].used )
				{
					node[i].used =1;
					if((double)m - node[i].f > 0)
					{
						sum += node[i].j ;
						m = (double)m-node[i].f ;
					}
					else if((double)m - node[i].f == 0)
					{
						sum += node[i].j ;
						m = (double)m-node[i].f ;
						break;
					} 
					else
					{
						sum += node[i].j * ((double)m)/ node[i].f ;
						break;
					}
				}
				
			}
		printf("%.3lf\n",sum);
	}
	
	
return 0;
}
