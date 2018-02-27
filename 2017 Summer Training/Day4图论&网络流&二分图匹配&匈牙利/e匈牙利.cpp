#include<stdio.h>
#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
/* **************************************************************************
//���������� ����ͼƥ�䣨�������㷨��DFSʵ�֣�
//��ʼ����g[][]���߶���Ļ������
//����g[i][j]��ʾi->j�������  ������ұߵ�ƥ��
//gû�б��������ʼ��Ϊ0

//uN��ƥ����ߵĶ�������vN��ƥ���ұߵĶ�����
//���ã�res = hungary();������ƥ����
//�ŵ㣺�����ڳ���ͼ��DFS������·��ʵ�ּ���������
//ʱ�临�Ӷ�:O(VE)
//***************************************************************************/
//�����Ŵ�0��ʼ��
const int MAXN=510;
int uN,vN;//u,v��Ŀ

int g[MAXN][MAXN];
int linker[MAXN];// ��ƥ��Ķ���
bool used[MAXN];// DFS���õ��ķ��ʱ��

bool dfs(int u)//����߿�ʼ������·��
{
    for(int v = 0; v < vN; v++)//��������Ŵ�0��ʼ����Ҫ��1��ʼ��Ҫ�޸�
    //ɨ��ÿ������
      if( g[u][v]  && !used[v] ) {
//������������һ�û�б�ǹ�
          used[v] = true;
          if( linker[v]==-1 || dfs(linker[v]) )
          {//������·������
              linker[v] = u; //���������������ڳ���λ����������ʹ�õݹ�
              return true;
          }
      }
    return false;//�����Ҫ����
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
         printf("Case %d: %d\n",iCase++, uN + vN - hungary() );  //��С���㸲��������ö�������ȥ��ʱ��
     }
     return 0;
}
