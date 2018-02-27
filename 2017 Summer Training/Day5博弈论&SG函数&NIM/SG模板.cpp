//f[N]:可改变当前状态的方式，N为方式的种类，f[N]要在getSG之前先预处理
//SG[]:0~n的SG函数值
//S[]:为x后继状态的集合
int f[N],SG[MAXN],S[MAXN];
void  getSG(int n){
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

void SG(int x)
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
        if( vit[i] == false)
            return i;
}



 几项准备工作：
 mex求最小非负整数mex{} = 0,mex{0,1,2,4} = 3,mex{1,2,4} = 0
 sg[x] =mex{sg[y]|y是x的后继}//就是石头变少的继
 这样sg就满足几个性质

1.      sg[x] == 0时，它的后继都不为零

2.      sg[x] != 0时，它的后继一定有为零的

3.      当x点没有出边时，sg[x] == 0

由此可知：sg[x] == 0,x就是p-position



