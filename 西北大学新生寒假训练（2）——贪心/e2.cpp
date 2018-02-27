// 贪心算法---先排序---后选择第一个没有用过的木头一次向后找，用掉所有可以用掉的木头，然后返回第一个没用过的木头继续找
#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
struct stick
{
    int len;
    int wei;
}a[5001];
bool used[5001];

bool cmp(stick k1,stick k2)       //按照长度从小到大排序，若长度相同按照重量递增排序
{
    if(k1.len==k2.len)
        return k1.wei<k2.wei;
    else
        return k1.len<k2.len;
}

int main()
{
    int T,n,i,j,st,count;
    bool flag;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(i=0;i<n;++i)
            scanf("%d%d",&a[i].len,&a[i].wei);
        sort(a,a+n,cmp);
        memset(used,false,sizeof(used));
        used[0]=true;
        st=0;       //记录第一个没有用过的木头
        count=0;
        while(st<n)
        {
            ++count;
            for(i=st+1,j=st,flag=true;i<n;++i)
            {
                if(used[i])
                    continue;
                if(a[j].len<=a[i].len&&a[j].wei<=a[i].wei)
                {
                    used[i]=true;
                    j=i;
                }
                else 
                {
                    if(flag)
                    {
                        st=i;      //只记录第一个没用过的木头
                        flag=false;
                    }
                }
            }
            if(flag)    //说明都用过了
                break;
        }
        printf("%d\n",count);
    }
    return 0;
}
/*
j = i+1;
				while (node[j].l >= node[j-1].l && node[j].w  >= node[j-1].w && j<n )
				{
					j++;
				}
				if(j!=n    )
				sum++;
				i=j-1;
*/
