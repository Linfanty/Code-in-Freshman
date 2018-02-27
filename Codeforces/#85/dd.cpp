#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 100005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;

int n, x[maxn], y[maxn];
vector<int> data[maxn];
int node[maxn][500];
bool active[maxn];
int yinzi[maxn];
bool isyinzi[maxn];
int sz;

const int N = 100000 + 5;
int divisor[N];
/*

定义：divisor[i] ：以i为因子的最后一个数的下标；
用一个数组标记一个数，作为因子 最后出现在 第vis【i】个数
开始vis数组初始化为-1；

①对每个输入的数找出它的所有因子，
比较该因子是否在给定范围内也是其它数的因子；

②若不是，则累加计数；

③更新当前数的因子的位置为当前下标\
*/
int main()
{
    int n;
    cin>>n;

    int x, y;
    memset(divisor, -1, sizeof(divisor));

    for(int i = 0; i < n; i++)
    {
        cin >> x >> y;
        int res = 0;

        for(int j = 1; j * j <= x; j++)
            if(x % j == 0)
            {
                if(i - y > divisor[j])  // i - yi <= j < i 不满足已经存在的
                res++;
                if(j * j != x && i - y > divisor[x / j])
                res++;
                divisor[j] = divisor[x / j] = i;
            }

        cout<<res<<endl;
    }
}
