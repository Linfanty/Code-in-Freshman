#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    //freopen("a.txt","r",stdin);
    int king[1005],tianji[1005];
    int n;
    while(cin>>n&&n)
    {
        int t1,t2,k1,k2,cnt=0; //cnt用来记录 田忌赢了多少次
        int i;
        for(i=0;i<n;i++) cin>>tianji[i];
        for(i=0;i<n;i++) cin>>king[i];
        sort(tianji,tianji+n,cmp);//从大到小排序
        sort(king,king+n,cmp);
        t1=k1=0;t2=k2=n-1;
        for(i=0;i<n;i++)
        {
            if(tianji[t1]>king[k1]) //如果田忌最快的马比国王最快的马块
            {
                cnt++;
                t1++;
                k1++;
                continue;
            }
            if(tianji[t1]<king[k1]) //如果田忌最快的马比国王的慢，那么就让田忌最慢的马跟国王最快的马比
            {
                cnt--; //所以 田忌输了一次
                k1++;  //国王最快的马用掉了
                t2--; //田忌最慢的马用掉了
                continue;
            }
            if(tianji[t1]==king[k1]) //如果田忌的马跟国王的马速度相等
            {
                if(tianji[t2]>king[k2]) //比较最慢马  同理
                {
                    cnt++;
                    t2--;
                    k2--;
                    continue;
                }
                if(tianji[t2]<king[k2]) //同理 如果田忌最慢马比国王最慢马还慢，那么用田忌 的快马跟国王比
                {
                    cnt--;
                    t2--;
                    k1++;
                    continue;
                }
                if(tianji[t2]==king[k2]) //如果最快和最慢马都相等，那么用田忌最慢马和国王最快马相比
                {
                    if(tianji[t2]<king[k1])
                    {
                        cnt--;
                        t2--;
                        k1++;
                        continue;
                    }
                }
            }
        }
        cout<<cnt*200<<endl;

    }
    return 0;
}


