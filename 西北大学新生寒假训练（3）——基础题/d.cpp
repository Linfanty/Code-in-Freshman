#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<climits>
typedef long long ll;
const int maxn = 105;
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	double x1,y1,x2,y2,x3,y3,x4,y4;
	while(scanf("%lf %lf %lf %lf %lf %lf %lf %lf",&x1,&y1,&x2,&y2,&x3,&y3,&x4,&y4)!=EOF)
	{
		if(x1<x2 && y1>y2 )
		{
			swap(y1,y2);
		}
		else if(x1>x2 && y1>y2)
		{
			swap(x1,x2);
			swap(y1,y2);
		}
		else if(x1>x2 && y2>y1)
		{
			swap(x1,x2);
		}
		
		if(x3<x4 && y3>y4 )
		{
			swap(y3,y4);
		}
		else if(x3>x4 && y3>y4)
		{
			swap(x3,x4);
			swap(y3,y4);
		}
		else if(x3>x4 && y4>y3)
		{
			swap(x3,x4);
		}
		
			x1=max(x1,x3);
            y1=max(y1,y3);
            x2=min(x2,x4);
            y2=min(y2,y4);
            printf("%.2lf\n",x1>x2||y1>y2?0:(x2-x1)*(y2-y1));
	
		
	}
	
	return 0;
}
