#include<stdio.h>
#include<string.h>
int maxn=1e5 +10;
/*
题意：给一个奇数，要求交换两个数字使它成为偶数，并且值要尽可能大。 

简析：设最右的数为d，从左到右找第一个比d小的偶数与之交换即可，
若偶数都比d大则要选择最右边的那个偶数，除此之外无解
*/
int main()
{
	char s[maxn];
	int count=0,q=2;
	scanf("%s",s);
//	sprintf(s,"%lld",n);
	for(int i=0;i<strlen(s);i++)
	{
		if((s[i]-'0')%2!=0)
		count++;
	}
	if(count==strlen(s))
	printf("-1");
	else 
	for(int i=0;i<strlen(s);i++)
	{
			if((s[i]-'0')%2==0&&s[i]<s[strlen(s)-1])
			{
				char t;
				t=s[i];s[i]=s[strlen(s)-1];s[strlen(s)-1]=t;
					printf("%s",s);
					q++;
				break;
			}
	}
	if(q==2)
	{
		for(int i=strlen(s)-2;i>=0;i--)
			if((s[i]-'0')%2==0)
			{
				char t;
				t=s[i];s[i]=s[strlen(s)-1];s[strlen(s)-1]=t;
					printf("%s",s);
				break;
			}
	}
	
}
