#include<stdio.h>
#include<string.h>
int maxn=1e5 +10;
/*
���⣺��һ��������Ҫ�󽻻���������ʹ����Ϊż��������ֵҪ�����ܴ� 

�����������ҵ���Ϊd���������ҵ�һ����dС��ż����֮�������ɣ�
��ż������d����Ҫѡ�����ұߵ��Ǹ�ż��������֮���޽�
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
