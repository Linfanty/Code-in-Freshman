#include<stdio.h>
#include<string.h>
main()
{
	char a[10];
	int t=0,p=0,sum=0,b=0,f=0;
	while(gets(a))
	{
		if(strcmp(a,"")==0)
		{
			printf("%d\n",sum);
			b=0;
			p=0;
			t=0;
			f=0;
			sum=0; 
		}
		if(strcmp(a,"bait")==0)
		{
			if(b<6)
		{
				b++;
			}
			if(t==1)
			p++;
		}
		if(strcmp(a,"lunch")==0&&t==1)
		{
			p++;
		}
		if(strcmp(a,"fish")==0)
		{
			if(t==1) p++;
			if(t==1&&b>=2) f++;
			if(t==1&&(p>=7||f>=3)&&b>=2)
			{
				sum++;
				f=0;
				p=0;
				b-=2;
			}
			else if(t==0&&b>=2)
			{
			sum++;
			f=0;
			p=0;
			b-=2;
			t=1;
			}
		}
		
	}
}
