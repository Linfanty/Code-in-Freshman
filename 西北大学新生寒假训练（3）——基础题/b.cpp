#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<climits>
typedef long long ll;
const int maxn = 105;
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);	freopen("out.txt","w",stdout);
	int n,t;
	scanf("%d ",&n);
	while(n--)
	{
		char s[55];
		memset(s,0,sizeof(s));
		
		gets(s);
		int j4=0,j3=0,j2=0,j1=0;
		for(int i=0;i<strlen(s);i++) //~,!,@,#,$,%,^; 
		{
			if(s[i]=='~' || s[i] =='!' ||s[i]=='@' || s[i]=='#' || s[i]=='$' || s[i]=='%' ||s[i]=='^')
			j4++;
			else if(isdigit(s[i]))
			j3++;
			else if(islower(s[i]))
			j2++;
			else if(isupper(s[i]))
			j1++;
		}
		int count=0;
		if(j1)
		count++;
		if(j2)
		count++;
		if(j3)
		count++;
		if(j4)
		count++;	
	//	printf("%s\n",s);
	//	printf("%d %d %d %d\n",j1,j2,j3,j4);
			if(strlen(s)>=8&&strlen(s)<=16&&count>=3)
			printf("YES\n");
			else
			printf("NO\n");
	}
	return 0;

}
