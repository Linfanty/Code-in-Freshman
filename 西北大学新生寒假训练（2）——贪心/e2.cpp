// ̰���㷨---������---��ѡ���һ��û���ù���ľͷһ������ң��õ����п����õ���ľͷ��Ȼ�󷵻ص�һ��û�ù���ľͷ������
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

bool cmp(stick k1,stick k2)       //���ճ��ȴ�С����������������ͬ����������������
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
        st=0;       //��¼��һ��û���ù���ľͷ
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
                        st=i;      //ֻ��¼��һ��û�ù���ľͷ
                        flag=false;
                    }
                }
            }
            if(flag)    //˵�����ù���
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
