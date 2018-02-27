#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 100010
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,0,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;

int prime[maxn];//may be small 1000010
bool isprime[maxn+1];
int sz;

//����ɸ �� �õ����е�����
void getPrime()
{
    sz = 0;
    memset(isprime, true, sizeof(isprime)); //��ʼ��Ϊ��
    rep(i, 2, maxn)
    {
        if(isprime[i])
            for(int j = 2*i; j <= maxn ; j+=i)
                isprime[j] = 0;     //Ϊ��
    }

    rep(i, 2, maxn)
        if( isprime[i] )
            prime[sz++] = i;        // Ϊ��  ��������
}

bool active[maxn];// �Ƿ���ʹ�
int data[maxn][10];
//vector<int> data[maxn];
int cnt[maxn];//���� һ������������������ ����Ϊ����� ������� ���101��

int n, m;   string s;   int q;

bool init()
{
    getPrime();
    //�õ������������� ���Ҵ���data��
    rep(i,0,sz-1)
    {
        // j = prime[i] : 2 3 5 7
        // j : 2 4 6 8 10 ... 2���� data
        // j : 3 6 9 12 15 ... 3���� data
        // j : 5 10 15 20 ... 5���� data
        /*data[2][ ++data[2][0] ] = 2;
         data[4][ ++data[4][0] ] = 2;
         data[6][ ++data[6][0] ] = 2;
         ���ÿ�������� �����뵽 data��
         */
        for(int j = prime[i]; j < maxn; j += prime[i])
            data[j][ ++data[j][0] ] = prime[i];
            //data[j].push_back( prime[i] );
            //�ڶ�λ����ͳ��*һ���ж��ٸ��������ӣ����������ܺ�
    }
    /*
    rep(i,0,5)
    cout << data[12][i] << ' '; // 2 2 3

    rep(i,0,5)
    cout << data[6][i] << ' '; // 2 2 3

    rep(i,0,6)
    cout << data[10][i] << ' '; // 2 2 5
    **/
}

void input()
{
    cin >> n >> m;
    mem(active);
    mem(cnt);


    rep(i, 1, m)
    {
        cin >> s >> q;
        if( s[0] == '+' )
        {
            if( active[q] )
                cout << "Already on" << endl;
            else
            {
                bool b = 0;
                rep(j, 1, data[q][0] )
                    if( cnt[ data[q][j] ] )
                    {
                        cout << "Conflict with " << cnt[ data[q][j] ] << endl;
                        b = 1; break;
                    }

                if( !b )
                {
                    rep(j, 1, data[q][0] )
                        cnt[ data[q][j] ] = q;  //����
                        //cnt[ data[6][1] = 6
                        //cnt[ data[6][2] = 6
                    cout << "Success" << endl;
                    active[q] = 1; // ����

                }
            }

        }
        else // "-"
        {
            if( !active[q] )
                cout << "Already off" <<endl;
            else
            {
                rep(j, 1, data[q][0] )
                    cnt[  data[q][j] ] = 0;  //����
                cout << "Success" << endl;
                    active[q] = 0;
            }

        }
    }
}

int main()
{
    init();
    input();

}
