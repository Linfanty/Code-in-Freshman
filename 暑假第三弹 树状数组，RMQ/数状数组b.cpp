#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
typedef long long ll;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define mem(a) memset(a, false, sizeof(a))
#define maxn 500005
ll tree[maxn], n;

struct Num{
    ll val, pos;
    bool operator < (const Num& x) const{
        return val < x.val;}
}a[maxn];

//lowbit(k)=lowbit(1010)=0010(2����)
void add(ll k, ll num){//����k������num
    while(k <= n){
        tree[k] += num;
        k += k&-k;
    }
}
ll query(ll k) {//��ѯ1~k�������
    ll sum = 0;
    while(k){
        sum += tree[k];
        k -= k&-k;
    }
    return sum;
}


int main()
{
    while( cin >> n && n )
    {
        mem(tree);
        rep(i, 1, n)
            cin >> a[i].val, a[i].pos = i;

        /**
        9 1 0 5 4
        1 2 3 4 5
        ``````````````````````````````````````
        0 1 4 5 9 ��С��������
        3 2 5 4 1 ��Ӧ�ı��pos
        ���ҵ�����x������ta��
        a[5].pos = 1,ans = 0  1 0 0 0 0
        a[4].pos = 4,ans = 1  1 0 0 1 0
        a[3].pos = 5,ans = 3  1 0 0 1 1
        a[2].pos = 2,ans = 4  1 1 0 1 1
        a[1].pos = 3,ans = 6  1 1 1 1 1
        */
        sort(a+1, a+n+1);
        //ö��ÿ������Ȼ���ѯ�����ǰ�������ֵ���ܺ�
        ll ans = 0;
        //per(i, n, 1)���
            //ans += query(a[i].pos), add(a[i].pos, 1);
            rep(i,1,n)//�Ե�
                add(a[i].pos, 1), ans += query(n) - query(a[i].pos);
            // add(a[i].r,1);
            //ans+=sum(y)-sum(a[i].r);
        cout << ans <<endl;
    }
}

