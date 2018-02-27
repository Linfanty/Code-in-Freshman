#include<stdio.h>
int main()
{
	long long n,a,b,c;
	long long int k=0;
	scanf("%lld %lld %lld %lld",&n,&a,&b,&c);
	for(int i=0;i<4;i++)
	if((n+i)%4==0)
	{
		k=i;
		break;
	}
	if(k==0)
	printf("0");
	if(k==1)
	{
	
	if(a<=(b+c)&&a<=(c*3))
	printf("%lld",a);
    else	if((b+c)<=a&&(b+c)<=(c*3))
	printf("%lld",b+c);
    else if((c*3)<=a&&(c*3)<=(b+c))
	printf("%lld",c*3);
   }

	if(k==2)
	{
	if((a*2)<=b&&(a*2)<=(c*2))
	printf("%lld",a*2);
	else if(b<=(a*2)&&b<=(c*2))
	printf("%lld",b);
	else if((c*2)<=b&&(c*2)<=(a*2))
	printf("%lld",c*2);
	}
	
    if(k==3)
	{
	if((a*3)<=(b+a)&&(a*3)<=c)
		printf("%lld",a*3);
	else if((a+b)<=c&&(a+b)<=(a*3) )
		printf("%lld",a+b);
	else if(c<=(a*3) && c<=(a+b))
		printf("%lld",c);
	}
	return 0;	
}
