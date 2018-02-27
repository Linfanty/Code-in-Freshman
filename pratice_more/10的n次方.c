#include<stdio.h>
#include<math.h>
int main() 
{
	int t,i,sum=0,x,n=0;
	printf("Please input n=");
	scanf("%d",&n);
	int a[100];
    a[0]=2;
	
	
	for(i=1;i<n;i++)
	{t=pow(x=10,i);
	a[i]=2*t+a[i-1];
    sum=sum+a[i];
	}
	printf("Sn=%d",sum+2);
	system("pause"); 
	return 0;
}
