#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 100005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define rep(i,a,b) for(int i=a;i<b;i++)
//const int N = 2e5 + 5;
using namespace std;
typedef long long int ll;

ll n, m, a;
int b[maxn],p[maxn];
//�òƲ������������ĳ�,Ȼ����ֱƽ�

//ѡk��Ǯ����ˣ���k������ٵĳ���Ȼ��һһ��Ӧ��
//�����Ϲ�ͬ�ʽ����ھ���һ�����⣬ȷ��k��ֵ

//���k���У���ôk֮��Ķ�������
//����Թ������������� &��Ǯ
bool check(int mm)
{
    ll sum = 0;
    rep(i,0,mm)
        if(p[mm-1-i] > b[n-1-i])
            {sum += p[mm-1-i] - b[n-1-i];
             //cout << mm <<' ' <<  p[mm-1-i] << ' ' << b[n-1-i] << endl;
            }
            //cout << endl;
        //mm:3 p[2-i] b[3-i]
        // 2 3 5 6 7
        // 1 1 2 8

        //      p[2] b[3]  �������˵Ļ� �Ͳ�����sum
        //      p[1] b[2]  ����sum
        //      p[0] b[1]  ����sum

        // 2 3
        //   1 2
    if(sum > a)
        return false;
    return true; // �ܵĻ���С�ڵ��ڿɲ�����a
}

void erfen()
{
    ll low = 0, high = min(n,m);
    while( low <= high){
        ll mid = (low+high)/2;
        //cout << mid << ' ' << check(mid) << endl;
        if( check(mid) )
        {
            ll ans = mid;
            low = mid + 1;
        }
        else high = mid - 1;
    }
    ll sum = 0;
    //cout << low << ' ' << high << endl; //4 3

    rep(i,0,low)//�ӻ������ٵĳ�����ѡ��
        {sum += p[high-1-i];
         //cout << high-1-i << ' '<<p[high-1-i]<<endl;
        }
        //p[2]: 5
        //p[1]: 3
        //p[0]: 2
        //p[-1]: 0

    sum = max(0ll, sum-a);//��ȥ�ܿ��Բ����Ľ��
    cout << high << ' ' << sum << endl;
}

int main()
{
    cin >> n >> m >> a;
    rep(i,0,n) cin >> b[i];
    rep(i,0,m) cin >> p[i];
    sort(b,b+n); sort(p,p+m);
    erfen();
}
