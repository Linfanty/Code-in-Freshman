#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 10005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;

//贪心
/*Each line contains exactly two different lowercase Latin letters
 without separators that represent the forbidden pairs.
 It is guaranteed that each letter
 is included in no more than one pair.
 所以没有 as sd 的禁止对
 */
int main()
{
    string s;
    cin >> s;
    int len = s.size();

    int n;
    cin >> n;
    int ans = 0;
    string a;

    while(n--)
    {
        cin >> a;
            rep(i, 0, len-1)
            {
                int l = 0, r = 0;
                //acca dee a b ca
                //统计连起来的， 并且减掉最少出现的
                //2        0  1
                while( s[i] == a[0] || s[i] == a[1] )
                {
                    if( s[i] == a[0] ) l++;
                    if( s[i] == a[1] ) r++;
                    i++;
                }
                //分类统计 并且善用min求总和
                ans += min(l,r);
            }
    }
    cout << ans << endl;
}
