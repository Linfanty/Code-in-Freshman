#include <iostream>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdio>
typedef long long ll;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define mem(a) memset(a, false, sizeof(a))
#define maxn 1000005
int tree[maxn], n, t, w = 1, x, y;

struct Node{
    int l, r, id;
    bool operator < (const Node& y) const{
        if( l != y.l )
            return l < y.l;
        return r < y.r;}
}a[maxn];


//lowbit(k)=lowbit(1010)=0010(2����)
void add(int k, int num){//����k������num
    while(k <= y){
/**yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy*/
/**cahngdunnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn*/
/**mubanbbnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnnn*/
        tree[k] += num;
        k += k&-k;
    }
}

int query(int k) {//��ѯ1~k�������
    int sum = 0;
    while(k){
        sum += tree[k];
        k -= k&-k;
    }
    return sum;
}


ll ans;
int main()
{/**��ȫ������IO*/
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d",&x, &y, &n);
        mem(tree);
        ans = 0;

        rep(i, 1, n)
            scanf("%d %d",&a[i].l, &a[i].r), a[i].id = i;

        sort(a+1, a+1+n);

        per(i,n,1)
         cout << a[i].r<< ' ';
        cout << endl;
        //rep(i,1,n)
        per(i, n, 1)
            ans += query(a[i].r), add(a[i].r, 1);
/**
1
3 4 4
1 4
2 3
3 2
3 1
3 4 2 1��Ҫ����������Щ���ֱ�� ��sort
Test case 1: 1
*/
/**
2
3 3 3
1 2
2 2
3 2
3 2 1
Test case 1: 3
3 3 3
3 2
2 2
1 2
1 2 3
Test case 2: 0
*/

        //rep(i, 1, n)
        //    add(a[i].r, 1), ans += query(y) - query(a[i].r);
        printf("Test case %d: %lld\n",w++,ans);
    }
}
