#include<bits/stdc++.h>
using namespace std;
vector<int>save[222222];
int maxdeep[222222],deep[222222],fa[222222];
/*��������������һ����������1�ڵ㵽x�ڵ��·����ֻ��һ����
��ô׷����ֻ�ܴ�1��ʼȥ׷x,��ôx�����ַ���һ��������1�ܣ�
������ʲô��·�ڿ����ߣ����Ǳ���x�ܣ�һֱ�ܵ����������
��ô����������ܹ�������ÿ���ӵ�Ϊ�������������ȣ���ô�������ͽ���ˡ�

x������������Ѿ��������ô�Ϳ�һ������x�����ߵ�·����û�в�·�ڣ�
ʹ���������·��Ϊ������������ȱ�֮ǰ�Ĵ�������ֵ*2��������Ҫ�Ĵ𰸡�
*/
void dfs(int now,int f,int d)
{
    deep[now]=maxdeep[now]=d;
    fa[now]=f;
   // printf("%d %d\n",now,fa[now]);
    int k=save[now].size();
    for(int i=0; i<k; i++)
    {
        int temp=save[now][i];
        if(temp!=f)
        {
            dfs(temp,now,d+1);
            maxdeep[now]=max(maxdeep[now],maxdeep[temp]);
        }
    }

}
int main()
{
    int n,x;

    while(scanf("%d%d",&n,&x)!=EOF)
    {
    memset(fa,0,sizeof(fa));
        for(int i=0; i<n-1; i++)
        {
            int u,v;
            scanf("%d%d",&u,&v);
            save[u].push_back(v);
            save[v].push_back(u);

        }
        dfs(1,1,0);
        int ans=2*maxdeep[x];
        for(int i=0,k=x; i<deep[x]; i++,k=fa[k])
        {
            if(i<deep[k])
            {
                ans=max(2*maxdeep[k],ans);
            }
            else
                break;
        }
        printf("%d\n",ans);
    }

}
