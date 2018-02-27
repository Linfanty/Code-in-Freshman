/*
姓名：王天阳 
院系：信息科学与技术学院 
专业：软件工程
班级：二班
学号：2016118072
*/
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iostream>
#define maxn 10005
#define fin(i,a,b) for(int i=a ; i<b ;i++)
#define mem(a,b) memset(a,b,sizeof(a));
#define fre freopen("in.txt","r",stdin)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	char password;	
	int flag = 0;
	printf("提示：请以回车键作为数据输入的结束标志\n");
	printf("请输入密码子串：");
	while( scanf("%c",&password) )
	{
		if(flag == 0)
		{
			printf("对应的源码：");
			flag = 1;
		}
		if(password == 10 )
		{
			printf("\n");
			break;
		}
		else printf("%c",password - 7 );
	}

return 0;
}
