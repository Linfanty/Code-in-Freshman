#include<iostream>
#include<stack>
#include<stdio.h>
using namespace std;
#define maxx 110000
long long int str[maxx],t[maxx];

struct node
{
    long long int num,pre,next;    //num记录数值，pre记录向前延伸多少个，next记录向后延伸多少个,k记录本身所处的位置
    long long int k; // k记录本身所处的位置
}tmp;

int main()
{
    int n;
    while(scanf("%d",&n)>0)
    {
        stack<node>Q;

        long long int ans=-100,sum=-100,num;
        str[0]=0;
        for(long long int i=1;i<=n;i++)
        {
            scanf("%I64d",&t[i]);
            if(i==1)
                str[i]=t[i];
            else
                str[i]=str[i-1]+t[i];
        }

        tmp.num=t[1];
        tmp.pre=1;
        tmp.next=1;
        tmp.k=1;
        Q.push(tmp);

        long long int x=0,y=0;
        for(long long int i=2;i<=n;i++)
        {
            node tmp1;
            tmp1.num=t[i];
            tmp1.pre=tmp1.next=1;
            tmp1.k=i;

            while( !Q.empty() && tmp1.num <= Q.top().num )
            {
                tmp=Q.top();
                Q.pop();

                if(!Q.empty())
                    Q.top().next+=tmp.next;
                tmp1.pre+=tmp.pre;
                ans= tmp.num * (str[tmp.k+tmp.next-1]-str[tmp.k-tmp.pre]);
                if(ans>=sum)
                {
                    sum=ans;
                    x=tmp.k-tmp.pre+1;
                    y=tmp.k+tmp.next-1;
                }
            }
            Q.push(tmp1);
        }
        while(!Q.empty())
        {
            tmp=Q.top();
            Q.pop();
            if(!Q.empty())
            Q.top().next+=tmp.next;
            ans=tmp.num*(str[tmp.k+tmp.next-1]-str[tmp.k-tmp.pre]);
            if(ans>=sum)
            {
                sum=ans;
                x=tmp.k-tmp.pre+1;
                y=tmp.k+tmp.next-1;
            }
        }

        if(n==0)x=y=0;
        printf("%I64d\n%I64d %I64d\n",sum,x,y);
    }
    return 0;
}
