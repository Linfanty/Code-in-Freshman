#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<cmath>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
const int maxn=100010;
const int maxm=100010;
const int SIGMA_SIZE=26;
int n;
char t[maxn],s[maxn];

struct AC
{
    int ch[maxm][26];
    int val[maxm];
    int fail[maxm],last[maxm];
    int sz;
    void clear(){memset(ch[0],0,sizeof(ch[0]));sz=1;}
    int idx(char x){return x-'a';}
    void insert(char *s)
    {
        int u=0;
        int n=strlen(s);
        for(int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            if(!ch[u][c])
            {
                memset(ch[sz],0,sizeof(ch[sz]));
                val[sz]=0;
                ch[u][c]=sz++;
            }
            u=ch[u][c];
        }
        val[u]++;
    }
    void getfail()
    {
        queue<int> q;
        fail[0]=0;
        int u=0;
        for(int i=0;i<SIGMA_SIZE;i++)
        {
            u=ch[0][i];
            if(u){q.push(u);fail[u]=0;last[u]=0;}
        }
        while(!q.empty())
        {
            int r=q.front();q.pop();
            for(int i=0;i<SIGMA_SIZE;i++)
            {
                u=ch[r][i];
                if(!u){ch[r][i]=ch[fail[r]][i];continue;}
                q.push(u);
                int v=fail[r];
                while(v&&!ch[v][i])v=fail[v];
                fail[u]=ch[v][i];
                last[u]=val[fail[u]]?fail[u]:last[fail[u]];
            }
        }
    }
    int find(char *s)
    {
        int u=0,cnt=0;
        int n=strlen(s);
        for(int i=0;i<n;i++)
        {
            int c=idx(s[i]);
            u=ch[u][c];
            int temp=0;//必须赋初值为0，表示如果下面两个判断都不成立的时候while可以正常执行
            if(val[u])
                temp=u;
            else if(last[u])
                temp=last[u];
            while(temp)
            {
                cnt+=val[temp];
                val[temp]=0;
                temp=last[temp];
            }
        }
        return cnt;
    }
}tree;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        int maxlen=0;
        tree.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%s",t);
            int lt=strlen(t);
            if(lt>maxlen)
            {
                maxlen=lt;
                strcpy(s,t);
            }
            tree.insert(t);
        }
        tree.getfail();
        int ans=tree.find(s);
        if(ans==n)
        {
            printf("%s\n",s);
        }
        else
        {
            printf("No\n");
        }
        //printf("%d\n",ans);
    }
    return 0;
}
