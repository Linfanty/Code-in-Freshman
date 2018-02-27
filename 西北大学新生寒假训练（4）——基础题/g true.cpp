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
    return strcmp(x.name,y.name)<0;       ///结构体排序，以“AC数量降序>总时间升序>名字字典序”为依据
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
            a[cnt].ac=a[cnt].time=0;       ///初始化每个人的AC和time值
            char temp[10];
            for(int i=0; i<n; i++)
            {
                scanf("%s",temp);
                if(!strcmp(temp,"0"))      ///没有提交，不用考虑
                    continue;
                if(temp[0]=='-')           ///提交错误，不用考虑
                    continue;
                    
                int wa=0,res=0,len=strlen(temp);
                bool flag=false;           ///哨兵变量确定是否存在括号
                a[cnt].ac++;
                
                for(int k=0; k<len; k++)
                {
                    if(temp[k]=='(')       ///碰到左括号加入AC时间，并开始记录wa罚时
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
                    if(temp[k]==')')        ///碰到右括号加入wa罚时
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
