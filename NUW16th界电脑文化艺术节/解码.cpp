/*
������������ 
Ժϵ����Ϣ��ѧ�뼼��ѧԺ 
רҵ���������
�༶������
ѧ�ţ�2016118072
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
	printf("��ʾ�����Իس�����Ϊ��������Ľ�����־\n");
	printf("�����������Ӵ���");
	while( scanf("%c",&password) )
	{
		if(flag == 0)
		{
			printf("��Ӧ��Դ�룺");
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
