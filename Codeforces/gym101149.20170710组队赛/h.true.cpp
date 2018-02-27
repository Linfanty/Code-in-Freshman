#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 500005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
using namespace std;
typedef long long int ll;

int main()
{

    string s;
    cin >> s;
    int len = s.size();
    int flag = 0;
    int l = 0, r = 0;

    if( len&1 )
        flag = 1;

    for(int i = 0; i < len && !flag ; i++)
        if(s[i] == '(') l++;
            else if(s[i] == ')') r++;

    int k = len/2 - l; // 剩下的需要转化成左括号的个数
    int c=0, d=0;

    rep(i, 0, len-1)
    {
        if( s[i] == '?' && k )
        {
            s[i] = '(';
            k--; //需要的左--
        }
        else if( s[i] == '?')
            s[i] = ')'; // k用完了 则为右括号

        if( s[i] == '(' )
            c++; //左++
        if( s[i] == ')')
            d++; //右++
        if( c<d ) // 左 < 右 不符合 则跳出
        {
            flag = 1;
            break;
        }
    }


    if( flag == 1 || c != d)
        cout <<"Impossible"<<endl;
    else cout << s << endl;
}
