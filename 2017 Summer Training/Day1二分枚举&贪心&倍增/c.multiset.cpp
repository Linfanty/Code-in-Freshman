#include <stdio.h>
#include <bits/stdc++.h>
#define mid ((l+r)>>1)
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 40005;

stack <char> t;//�м����
multiset<char> st;//���ظ������ֵ���ķ�ʽ���ַ�
multiset<char>::iterator it;
//�������ҵ�һ�� �ǵݼ����ֵ�����С���Ӵ�
//Ȼ��������������ַ���
string s, u;
int len, min1 = 30, cnt = 0, pos = 0;
//ջ�������ȼ����ں�׺�����ȼ������ջ

int main()
{
    cin >> s;
    len = s.size();
    rep(i, 0, len-1) st.insert( s[i] );//aabbbb���ظ� �ֵ���

    while( u.length() < s.length() )
    {
        //                           *(st.begin()) �����ҵ�abcd����һ��
        //                           *(st.begin()) С����ջ
        if( pos < len && ( t.empty() || *(st.begin()) < t.top() ) )
        {
            //cout <<  *(st.begin()) << ' ';
            t.push( s[pos++]);//��ջ
                it = st.find( s[pos-1] ); // ����multiset��Ԫ��
        //�����ַ��Ž���stack�� �ʹ�multiset����ɾ��
            if( it != st.end())  // ��ȥ�õ���Ԫ��
                    st.erase(it);
        }
        else//��ʱջ���ַ�С�ڵ���minn����ʱҪ�����Ԫ�ص�λ�ӡ� ���ջ
        {
            char x = t.top();//ջ������ַ����
            t.pop(); // ��ջ
            u += x;
        }
    }
    cout << u << endl;
}


