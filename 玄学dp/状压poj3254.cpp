//http://poj.org/problem?id=3254
//http://blog.csdn.net/y990041769/article/details/24658419״̬ѹ��dp
#include<bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define maxn 30
/*
����������֪���� i-1 �е����еĿ��Էŵ����.���ڵ� i �еĿ��Էŵ�һ�����
ֻҪ�ж����� i - 1 �е�����������ܲ���������Ŀ������ţ������

һ�ַŷ��������12�� 0 ���� 1 ��ɵģ��ö����Ƶ�һ��������ʾһ�ַŷ���

����״̬dp��i����j������ i ��״̬Ϊ j ��ʱ���ţ������
j �Ļ�����ת���ɶ����ƣ��ӵ�λ����λ���� 1 ��ʾ��ţ0��ʾû�з�ţ��
�Ϳ��Ա�ʾһ�����е����

��ôת�Ʒ��� dp��i����j��=sum��dp��i-1����k����
*/
//x & ��x<<1�����ж�һ����������λ�ǲ���ͬʱΪ1
//x & y �Ĳ���ֵ���ж���ͬΪ�ǲ���ͬʱΪ1��


/*ÿһ���ܹ�2^N��״̬������ɾȥ�����ڵ�״̬��ɾ�������ϸ���������״̬��
���������յ�����״̬��Ȼ��ʼdp��

�������£�ÿһ��֮��������һ�С�
���Դ���һ��ת�ƹ�ȥ����״̬�������������ˡ�*/

const int N = 13;
const int M = 1<<N;
const int mod = 100000000;

int st[M],mp[M];  //�ֱ��ÿһ�е�״̬�͸����ص�״̬
int dp[N][M];  //��ʾ�ڵ�i��״̬Ϊjʱ����Է�ţ������

bool judge2(int i, int x)//���ܷŵĵط�����
{
    //cout << i << x << mp[i] << st[x] << ' ' << (mp[i]&st[x])<< endl;
/*
10 00 0
11 01 0
12 02 0
13 04 0
14 05 0

20 50 0
21 51 1
22 52 0
23 54 4
24 55 5
*/
    return mp[i]&st[x];
}

int main()
{
    int n, m, x;
    while( cin >> n >> m )
    {
        memset(st,0,sizeof(st));
         memset(mp,0,sizeof(mp));
          memset(dp,0,sizeof(dp));

        rep(i, 1, n)
        {
            rep(j, 1, m)
            {
                cin >> x;
                if( x == 0)
                    mp[i] += (1<<(j-1));
            }
        }
//cout << (1<<(j-1)) << mp[i]<<endl;
/*
2 3
1 1 1 mp[1] = 0
1.0 1  0
1.1 2  0
1.2 4  0
0 1 0 mp[2] = 5
2.0 1  1 //001���ɷ���
2.1 2  1 //001
2.2 4  5 //101�Ѷ�����ѹ����һ��ʮ��������
*/

        int k = 0;
        rep(i, 0, (1<<m)-1 )//ѡ���������ڲ��ȵ�״̬
            if( !( i & i<<1 ) ) //i&(i<<1) Ϊ��˵�����������ڵ����
                st[k++] = i;
//http://blog.csdn.net/became_a_wolf/article/details/50592475
//st[0] = 0 [1] = 1 [2] = 2 [3] = 4 [4] = 5 ���Էŵ�
        rep(i, 0, k-1)
            if( !judge2(1, i))
                dp[1][i] = 1;


        rep(i, 2, n)
        {
            rep(j, 0, k-1)
            {
                if(judge2(i,j))//�жϵ�i�� ���簴״̬j��ţ�Ļ��в��С�
                    continue;

                rep(f, 0, k-1)
                {
                    if( judge2(i-1, f))//http:blog.csdn.net/became_a_wolf/article/details/50592475
                        continue;//��֦ �ж���һ������״̬�Ƿ�����
                // ö���ҳ�   ��i-1�е�ͼ��  ʵ�����  ƥ������
                    if( !(st[j]&st[f] ) )
                    //i �� ���ڵ����  �� i-1�б�����ȫ��ƥ��
                        dp[i][j] +=dp[i-1][f];
                }
            }
        }

        int ans = 0;
        rep(i, 0, k-1)
        {
            ans += dp[n][i];
            ans %= mod;
        }
        cout << ans << endl;
    }

}
