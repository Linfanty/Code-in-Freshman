#include<cstdio>
#include<cmath>
#include<algorithm>
#include<sstream> 
#include<iostream>
#include<string.h>
typedef long long ll;
using namespace std;

using namespace std;
struct ACM
{
    char name[15];
    int ac,time;
} a[10005];
int cmp(ACM x,ACM y)
{
    return x.ac>y.ac;
    return x.time<y.time;
    return strcmp(x.name,y.name)<0;       ///�ṹ�������ԡ�AC��������>��ʱ������>�����ֵ���Ϊ����
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        int cnt=0;
        while(~scanf("%s",a[cnt].name))
        {
            a[cnt].ac=a[cnt].time=0;       ///��ʼ��ÿ���˵�AC��timeֵ
            char temp[10];
            for(int i=0; i<n; i++)
            {
                scanf("%s",temp);
                if(!strcmp(temp,"0"))      ///û���ύ�����ÿ���
                    continue;
                if(temp[0]=='-')           ///�ύ���󣬲��ÿ���
                    continue;
                    
                int wa=0,res=0,len=strlen(temp);
                bool flag=false;           ///�ڱ�����ȷ���Ƿ��������
                a[cnt].ac++;
                
                for(int k=0; k<len; k++)
                {
                    if(temp[k]=='(')       ///���������ż���ACʱ�䣬����ʼ��¼wa��ʱ
                    {
                        a[cnt].time+=res;
                        flag=true;
                        k++;
                        while(temp[k]!=')')
                        {
                            wa=wa*10+temp[k]-'0';
                            k++;
                        }
                    }
                    if(temp[k]==')')        ///���������ż���wa��ʱ
                    {
                        a[cnt].time+=(wa*m);
                        break;
                    }
                    if(!flag)
                        res=res*10+temp[k]-'0';
                }
                if(!flag)
                    a[cnt].time+=res;
            }
            cnt++;
        }
        sort(a,a+cnt,cmp);
        for(int i=0; i<cnt; i++)
            printf("%-10s%3d%5d\n",a[i].name,a[i].ac,a[i].time);
    }
    return 0;
}
