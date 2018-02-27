#include<stdio.h>

int main()
{
	char a,b,c;
	char t;
	
	while((scanf("%c%c%c",&a,&b,&c))!=EOF)
	{
		if(b<a)
		{
			t=a;a=b;b=t;
		}		
	if(c<b)
		{
			t=b;b=c;c=t;
		}	
	if(b<a)
	{
	t=a;a=b;b=t;
	}
		
		printf("%c %c %c\n",a,b,c);
		getchar();
	}
	return 0;
}
 
