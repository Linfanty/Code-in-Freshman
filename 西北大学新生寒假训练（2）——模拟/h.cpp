#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
	string line;
	int bait=0,count=0,fish=0,sum=0;
	while(getline(cin, line))
	{
		if(line=="fish")
		{
			if(bait >= 2 &&( (count >= 7 && fish >=2 ) || sum==0 ))  
			//����unit���� ������70min ����һ�� ����/�� ����30���ӵĴ��� ���� ��һ�ε��㵫�ǵ��ж� �� 
			{
				sum++; fish=0;count=0;bait=bait-2;
			}
			else fish++;
			count++;  //x�� ָ�� 
		}
		else if(line== "bait")
		{
			if(bait<6) bait++;
			count++;
		}
		else if(line== "lunch") count++;
	}	
	printf("%d\n",sum);
return 0;
}
