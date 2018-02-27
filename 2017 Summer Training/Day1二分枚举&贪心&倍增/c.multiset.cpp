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

stack <char> t;//中间变量
multiset<char> st;//可重复的以字典序的方式存字符
multiset<char>::iterator it;
//从左到右找到一个 非递减且字典序最小的子串
//然后逆序输出其他字符。
string s, u;
int len, min1 = 30, cnt = 0, pos = 0;
//栈顶的优先级大于后缀的优先级，则出栈

int main()
{
    cin >> s;
    len = s.size();
    rep(i, 0, len-1) st.insert( s[i] );//aabbbb可重复 字典序

    while( u.length() < s.length() )
    {
        //                           *(st.begin()) 依次找到abcd的下一个
        //                           *(st.begin()) 小则入栈
        if( pos < len && ( t.empty() || *(st.begin()) < t.top() ) )
        {
            //cout <<  *(st.begin()) << ' ';
            t.push( s[pos++]);//入栈
                it = st.find( s[pos-1] ); // 查找multiset中元素
        //若把字符放进了stack里 就从multiset里面删除
            if( it != st.end())  // 除去用掉的元素
                    st.erase(it);
        }
        else//此时栈顶字符小于等于minn【此时要加入的元素的位子】 则出栈
        {
            char x = t.top();//栈顶这个字符输出
            t.pop(); // 出栈
            u += x;
        }
    }
    cout << u << endl;
}


