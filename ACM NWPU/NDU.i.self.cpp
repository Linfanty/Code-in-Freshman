//�ַ��� & �ṹ������ 
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<ctime>
#define maxn 26+5
using namespace std;
char str[maxn];
int cnt[maxn];

struct Node   //struct Node 
{
    char name;
    int num;
}node[maxn];   // node [maxn +5 ]

bool cmp(Node x, Node y)  //bool cmp(Node x,Node y) 
	{  
    return x.name > y.name;    //�ص�  return x.name>y.name;   return x.num>y.num;
    }  
    
int main()
{system("COLOR 1f");
    int T;
    scanf("%d",&T);
    for(int kase=1;kase<=T;kase++)
    {
        memset(cnt,0,sizeof(cnt)); 

        while(1)
        {
            gets(str);  //char str[maxn+5];
            for(int i=0;i<strlen(str);i++)
            {
                if(str[i]=='#') cnt[i]++;  //���� cnt[i] ++ 
            }
            if(str[0]=='A') break;
        }

        for(int i=0;i<strlen(str);i++)
        {
            node[i].name='A'+i;
            node[i].num=cnt[i];
        }
        sort(node,node+strlen(str),cmp);   //�Խṹ���������  ����һ��char name һ�� int num 

        printf("Case #%d:\n",kase);
        printf("%d\n",strlen(str));
        for(int i=0;i<strlen(str);i++)
        {
            printf("%c %d\n",node[i].name,node[i].num);
        }
    }
    return 0;
}
