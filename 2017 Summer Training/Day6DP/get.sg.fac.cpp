#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int sg[105];
int a[105];
int n = 20;
const int MAXN = 1005;
const int N = 30;
//f[N]:可改变当前状态的方式，N为方式的种类，f[N]要在getSG之前先预处理
//SG[]:0~n的SG函数值
//S[]:为x后继状态的集合
//int f[N],SG[MAXN],S[MAXN];

void init()
{
    a[1] = 1,a[2] = 2;
    for(int i = 3; i < 20; i ++)
    {
        a[i] = a[i - 1] + a[i - 2];
        // cout<<a[i]<<endl;
    }
 }
/**
void init1()
{
    f[1] = 1,f[2] = 2;
    for(int i = 3; i < 1000;i ++)
    {
        f[i] = f[i - 1] + f[i - 2] ;
        // cout<<a[i]<<endl;
    }
}*/
/**

void getSG(int n){
    int i,j;
    memset(SG,0,sizeof(SG));

    //因为SG[0]始终等于0，所以i从1开始
    for(i = 1; i <= n; i++){
        //每一次都要将上一状态 的 后继集合 重置
        memset(S,0,sizeof(S));

        for(j = 0; f[j] <= i && j <= N; j++)
            S[SG[i-f[j]]] = 1;  //将后继状态的SG函数值0进行标记

        for(j = 0;; j++)
            if(!S[j]){   //查询当前后继状态SG值中最小的非零值
                SG[i] = j;
                break;
        }
    }
}
*/
int SG(int x)
{
    bool vis[105] ={false};
    int tmp;

    for(int i = 0; i < n && a[i] <= x; i++) //n是i的个数
    {
        tmp = x - a[i];
        if( sg[tmp] == -1)
            sg[ tmp ] = SG(tmp);
        vis[ sg[tmp] ] = true;
    }

    for(int i = 0; ; i++)
        if( vis[i] == false)
            {sg[x] = i;
            cout << i << endl; break;}
}


int main()
{
    init();
//    getSG(1000);
    SG(30);
    for(int i = 0; i < 21; i ++)
       printf("%d ", sg[i]);
}
