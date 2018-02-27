#include <stdio.h>
#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 100005;

int ans_l, ans_r;
ll a[maxn], sum[maxn], ans;

// ����Ϊn������ ������min��sum
// ö��ÿһ���� ������Ϊ��Сֵ������
// ������ ��ʱ
// ��������ջ ����ÿ����a[i]
// С�ڵ��� ջ���� ��ջ��Ϊ��Сֵ��������Ҷ���i
// ջ��a[j] ��ջ �� a[k] < a[j] ����ջ��

// �Ҷ�ֵ ��Ԫ����˵�ֵҲҪ��..��Ϊa[j]�����
// �ظ�����ֱ��ջ��  ���� ��Ԫ��

// ��ջʱ ǰ���� ���������� Ϊ��

struct Node {
    int l, r;//num��ֵ pre��ǰ������ٸ� next���������ٸ�
    ll num;
}s[maxn];

void update(int top)    {
    int l = s[top].l , r = s[top].r;
    cout << top << ' ' << l << ' ' << r << ' ' << ans << endl;
    if( (sum[r] - sum[l-1]) * s[top].num > ans) // sum ǰ׺��������lҪ��1 l-1;
    {
        ans = (sum[r] - sum[l-1]) * s[top].num;
        ans_l = l;
        ans_r = r;
    }
    if( top > 0)
        s[top - 1].r = s[top].r;
}


int main()  {
    ll n;
    while( cin >> n )
    {
        ans = -1;  sum[0] = 0;

        rep(i, 1, n)
            cin >> a[i], sum[i] = sum[i-1] + a[i];// 3 1 6 4 5 2

        int top = -1; /// ջ�׼�Ϊ-1
        rep(i, 1, n)    {
            Node v = {i, i, a[i]};
            while( top != -1 && s[top].num >= a[i])
            {
                update(top);/// 0 1
                v.l = s[top].l; /// V.L = S[TOP].L = S[0].L = 1
                top--;
            }
                                   // top
            s[++top].l = v.l;     // 1 1 3 3 5 3
            s[top].r = v.r;       // 1 2 3 4 5 6
            s[top].num = v.num;   // 3 1 6 4 5 2
            // cout << s[top].l << ' ' << s[top].r << ' ' << s[top].num << endl;
        }

        while( top!= -1)
        {
            update(top);
            top--;
        }
        cout << ans << endl;
        cout << ans_l<< ' ' << ans_r << endl;
    }
}
