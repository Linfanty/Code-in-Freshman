#include<string.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<climits>
#include<map>
#include<set>
typedef long long ll;
const int maxn = 105;
using namespace std;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	char a[1005];
	char b[1005];
	while(scanf("%s ",&a)!=EOF)
	{
		int i,j;
		if(strcmp(a,"#")==0)
		break;
		else  scanf("%s ",&b);
		int sum=0;
		//printf("%s %s\n",a,b);
		for(i=0;i<strlen(a);i++)
		{
			for (j=0;j<strlen(b);j++)
			{
				//int k=j;
				if(a[i]!=b[j])
				break;
				else 	
				{
					i++;
					if(j==strlen(b)-1)
					 {
					 sum++;
					--i;
					}
				}
			}	
		}
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		printf("%d\n",sum);
	}
	return 0;
}
