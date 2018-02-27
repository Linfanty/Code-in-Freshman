#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> vec;
	
int main()
{
	int N,M;
	scanf("%d %d",&N,&M);
	//vec.push_back(0);
	for(int i=1;i<=N;i++)
	{
		vec.push_back(i);
	}	
	
	while(M--)
	{
		int a,b,t;
		scanf("%d %d",&a,&b);
		if(a<b)
		continue;
		else
		if(a>b)
		{
			for(int i=0;i<N;i++)
			{
				if(vec[i]==b)
				{
					vec.erase(vec.begin() +  a-1 );
					vec.insert(vec.begin() + i - 1 +1,a);
					break;
				}	
			}
		//t=vec[a];vec[b]=vec[a];vec[a]=t;	
		}
	}
	
	for(int i=0;i<N;i++)
	{
		printf("%d ",vec[i]); 
	}	
}
