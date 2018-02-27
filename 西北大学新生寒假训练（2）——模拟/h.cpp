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
			//存在unit并且 （集满70min 垂钓一次 并且/或 大于30分钟的垂钓 或者 第一次钓鱼但是得有饵 ） 
			{
				sum++; fish=0;count=0;bait=bait-2;
			}
			else fish++;
			count++;  //x条 指令 
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
