#include<iostream>
#include<cstring>
using namespace std;
int map[105][105];
int visit[105],flag[105];
int n,m;
bool dfs(int a)
{
    for(int i=1; i<=n; i++)
    {
        if(map[a][i]&&!visit[i])
        {
            visit[i]=1;
            if(flag[i]==0||dfs(flag[i]))
            {
                flag[i]=a;
                return true;
            }
        }
    }
    return false;
}
int main()
{
    while(cin>>n1 >>n2 >>m)
    {
        memset(map,0,sizeof(map));
        for(int i=1; i<=m; i++)
        {
            int x,y;
            cin>>x>>y;
            map[x][y]=1;
        }
        memset(flag,0,sizeof(flag));
        int result=0;
        for(int i=1; i<=n1; i++)
        {
            memset(visit,0,sizeof(visit));
            if(dfs(i))result++;
        }
        cout<<result<<endl;
    }
    return 0;
}


bool find(int x){
    int i,j;
    for (j=1;j<=m;j++){    //ɨ��ÿ������
        if (line[x][j]==true && used[j]==false)
        //������������һ�û�б�ǹ�(�����ǵ���˼����β�������ͼ�ı�������ӵĹ������⣬����û�гɹ������ԾͲ���Ϲ�ѹ����ˣ�
        {
            used[j]=1;
            if (girl[j]==0 || find(girl[j])) {
                //���������������ڳ���λ����������ʹ�õݹ�
                girl[j]=x;
                return true;
            }
        }
    }
    return false;
}

//��������������������ÿһ���൱����������������һ�������е�һ��

for (i=1;i<=n;i++)
{
    memset(used,0,sizeof(used));    //�����ÿһ�������
    if find(i) all+=1;
}
