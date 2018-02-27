#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;

int main()
{
	int n;
	while(scanf("%d",&n)!=EOF&&n)
	{	
		int m;
		int count=0;
		while(n--)
		{
			scanf("%d",&m);
			while(m)
			{
				if(m-100>=0)
				{
					count++;
					m=m-100;
				}
				else if(m-50>=0)
				{
					count++;
					m=m-50;
				}
				else if(m-10>=0)
				{
					count++;
					m=m-10;
				}
				else if(m-5>=0)
				{
					count ++;
					m=m-5;
				}
				else if(m-2>=0)
				{
					count ++;
					m=m-2;
				}
				else if(m-1>=0)
				{
					count++;
					m=m-1;
				}
			}
		}
			printf("%d\n",count);
	}	
	
return 0;
}
 
