#include<stdio.h>
float f1(int n1);
float f2(int n2);
int main()
{
	
	int n;
	printf("plz input an integer: \n");
	scanf("%d",&n);
	if(n%2==0) f1(n);
	else f2(n);
}

float f1(int n1)
{
	float sum1=0;
	int term1=2;
	for(;term1<=n1;term1+=2)
	    sum1=sum1+1.0/term1;
	    printf("%g",sum1);
}

float f2(int n2)
{
	float sum2=0;
	int term2=1;
	for(;term2<=n2;term2+=2)
	     sum2=sum2+1.0/term2;
	         printf("%g",sum2);
}
