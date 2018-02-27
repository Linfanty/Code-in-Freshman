#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
/* **************************************************************************
//求最大独立集 二分图匹配（匈牙利算法的DFS实现）
//初始化：g[][]两边顶点的划分情况
//建立g[i][j]表示i->j的有向边  左边向右边的匹配
//g没有边相连则初始化为0

//uN是匹配左边的顶点数，vN是匹配右边的顶点数
//调用：res = hungary();输出最大匹配数
//优点：适用于稠密图，DFS找增广路，实现简洁易于理解
//时间复杂度:O(VE)
//***************************************************************************/
//顶点编号从0开始的
const int MAXN=510;
int uN,vN;//u,v数目

int g[MAXN][MAXN];
int linker[MAXN];// 所匹配的顶点
bool used[MAXN];// DFS中用到的访问标记

bool dfs(int u)//从左边开始找增广路径
{
    for(int v = 0; v < vN; v++)//这个顶点编号从0开始，若要从1开始需要修改
    //扫描每个妹子
      if( g[u][v]  && !used[v] ) {
//如果有暧昧并且还没有标记过
          used[v] = true;
          if( linker[v]==-1 || dfs(linker[v]) )
          {//找增广路，反向
              linker[v] = u; //名花无主或者能腾出个位置来，这里使用递归
              return true;
          }
      }
    return false;//这个不要忘了
}

int hungary()
{
    int res=0;
    int u;
    memset(linker,-1,sizeof(linker));

    for(u = 0; u < uN; u++) {
        memset(used,0,sizeof(used));
        if(dfs(u))
            res++;
    }
    return res;
}
//******************************************************************************/

int main()
{
     int m, u, v, iCase=1;
     while(scanf("%d %d %d",&uN,&vN,&m) != EOF && uN && vN)
     {
         for(int i=0;i<uN;i++)
           for(int j=0;j<vN;j++)
              g[i][j]=1;

         while(m--) {
             scanf("%d%d",&u,&v);
             u--, v--;
             g[u][v]=0;
         }
         printf("Case %d: %d\n",iCase++, uN + vN - hungary() );  //最小顶点覆盖求出，用顶点数减去就时答案
     }
     return 0;
}
