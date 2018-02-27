#include<stdio.h>
#include<math.h>
#include<stdlib.h>
double solve(int x,int y)
{
	double l=sqrt(2),s=0;
	for(int i=1;i<x+y;i++)
	s += i*l;
	s += l*x;
	for(int i=0;i<x+y;i++)
	s += sqrt( i*i + (i+1) * (i+1) );
	
	return s;
	
	}
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int x1,y1,x2,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		
		printf("%.3lf\n",fabs(solve(x1,y1) - solve(x2,y2)));
	}

return 0;
}

