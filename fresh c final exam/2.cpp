#include<stdio.h>
int main()
{
	int i,x[3][3]={9,8,7,6,5,4,3,2,1},*p;
	p=&x[0][0];
		printf("%d\t",p);
	for(i=0;i<10;i++)
	printf("%d\t",p[i]);
}

