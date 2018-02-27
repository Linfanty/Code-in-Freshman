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
#define maxn 100005
ll tree[maxn], n, a, b;

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
{IO;
    while( cin >> n  && n )
    {
        mem(tree);
        rep(j, 1, n)
        {
            cin >> a >> b;
            add(a, 1);
            add(b+1, -1);
        }
        //���µ�ʱ������˵�+1���Ҷ˵����һ��-1
        rep(i, 1, n)
            if( i == 1) cout << query(i);
                else cout << ' ' << query(i);

        cout << endl;
    }

}

