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
//f[N]:�ɸı䵱ǰ״̬�ķ�ʽ��NΪ��ʽ�����࣬f[N]Ҫ��getSG֮ǰ��Ԥ����
//SG[]:0~n��SG����ֵ
//S[]:Ϊx���״̬�ļ���
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

    //��ΪSG[0]ʼ�յ���0������i��1��ʼ
    for(i = 1; i <= n; i++){
        //ÿһ�ζ�Ҫ����һ״̬ �� ��̼��� ����
        memset(S,0,sizeof(S));

        for(j = 0; f[j] <= i && j <= N; j++)
            S[SG[i-f[j]]] = 1;  //�����״̬��SG����ֵ0���б��

        for(j = 0;; j++)
            if(!S[j]){   //��ѯ��ǰ���״̬SGֵ����С�ķ���ֵ
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

    for(int i = 0; i < n && a[i] <= x; i++) //n��i�ĸ���
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
