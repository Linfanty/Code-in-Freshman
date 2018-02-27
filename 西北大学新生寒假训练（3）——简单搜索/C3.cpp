#include <iostream>
#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;
struct node
{
    int x,time;
};
int N,K;
int flag[100005];
bool judge(node p)
{
    if(p.x<0 || p.x>100000 || p.time>flag[p.x])
    {
        return false;
    }
    return true;
}
void bfs()
{
    node p,temp;
    int i;
    flag[N]=0;
    p.x=N;
    p.time=0;
    queue<node>q;
    while(!q.empty())
    {
        q.pop();
    }
    q.push(p);
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(i=0;i<3;i++)
        {
            temp=p;
            if(i==0)
            {
                temp.x+=1;
            }
            if(i==1)
            {
                temp.x-=1;
            }
            if(i==2)
            {
                temp.x*=2;
            }
            temp.time=p.time+1;
            if(!judge(temp))
            {
                continue;
            }
            if(temp.x==K)
            {
                printf("%d\n",temp.time);
                return;
            }
            flag[temp.x]=temp.time;
            q.push(temp);
        }
    }
}
int main()
{
    while(~scanf("%d%d",&N,&K))
    {
        if(N==K)
        {
            printf("0\n");
            continue;
        }
        memset(flag,0x7F,sizeof(flag));
        bfs();
    }
    return 0;
}
