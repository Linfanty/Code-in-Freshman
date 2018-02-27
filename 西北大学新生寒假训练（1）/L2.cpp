#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vec;
vector<int> aa;
vector<int> bb;

struct Node
{
	int a;
	int b;
}node[505];
bool cmp(Node x,Node y)
{
	if(x.a == y.a ) return x.b < y.b; 
	return x.a < y.a ;
}
int main()
{
	int N,M;int a[505],b[505];
	scanf("%d %d",&N,&M);
		
	for(int i=0;i<M;i++)
		scanf("%d %d",&node[i].a , &node[i].b );
		
	
	
	sort(node , node+M , cmp ) ;  //结构体排序 
	
	for(int i=0;i<M;i++)//将结构体放入 vector 容器中
	{
		aa.push_back(node[i].a);
		bb.push_back(node[i].b);  
	}
	/*
	int q = 0;					// 统计 第一次 a 相同时 的次数 
	for(int i=0;i<=N;i++)		 
	{
		if (node[i].a == node[i+1].a )
		q++;
		else break;
	}
	
	int w=0; // 
	
	vec.push_back(node[0].a);  // 1
	vec.push_back(node[0].b);  // 1 3
//	node[0].a = 0;
//	node[0].b = 0;
		
	for(int i=1;i<=q;i++)  //第一次输入 1  3  5
 	{
		vec.push_back(node[i].b);
//		node[i].a=0;
//		node[i].b=0;	
	}	
	
	for(int i=0;i<=N;i++)
	{
		if(node[i].b == node[0].a )
		{
			vec.insert(vec.begin() + w , node[i].a  );	
			w++;	
		}
	} 
	*/
	int count = 0;
	
	for(int i= 0 ; i <  M ;i++)
	{
		if(aa[0] == aa[i] || aa[0] == aa[b] )
		count++;	
	}
	
	for (int i=0;i <= count; i++)
	{
		vec.push_back() 
	}

	/*
	for(int i=q;i<M;i++)
		{
			for(int j=0 ; j< vec.size() ; j++)
			{
				if(node[i].a < )	
			}			
		}
	*/
	for( int i=0;i<vec.size();i++)
	printf("%d ",vec[i]);
	
	
return 0;
}
