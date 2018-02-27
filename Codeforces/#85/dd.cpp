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

���壺divisor[i] ����iΪ���ӵ����һ�������±ꣻ
��һ��������һ��������Ϊ���� �������� ��vis��i������
��ʼvis�����ʼ��Ϊ-1��

�ٶ�ÿ����������ҳ������������ӣ�
�Ƚϸ������Ƿ��ڸ�����Χ��Ҳ�������������ӣ�

�������ǣ����ۼӼ�����

�۸��µ�ǰ�������ӵ�λ��Ϊ��ǰ�±�\
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
                if(i - y > divisor[j])  // i - yi <= j < i �������Ѿ����ڵ�
                res++;
                if(j * j != x && i - y > divisor[x / j])
                res++;
                divisor[j] = divisor[x / j] = i;
            }

        cout<<res<<endl;
    }
}
