#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
#define maxn 100005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,false,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;

int main()
{
    string s;

while(    cin >> s )
{

    int cnt[10] = {0};
    int len = s.size();
    int min1 = inf;
    rep(i, 0, len - 1)
    {
        if( s[i] == 'i' || s[i] == 'I'  )
            cnt[1]++;
        else if( s[i] == 'l' || s[i] == 'L'  )
            cnt[2]++;
        else if( s[i] == 'o' || s[i] == 'O'  )
            cnt[3]++;
        else if( s[i] == 'v' || s[i] == 'V'  )
            cnt[4]++;
        else if( s[i] == 'e' || s[i] == 'E'  )
            cnt[5]++;
        else if( s[i] == 'c' || s[i] == 'C'  )
            cnt[6]++;
        //else if( s[i] == 'e' || s[i] == 'E'  )
        //    cnt[7]++;
        else if( s[i] == 's' || s[i] == 'S'  )
            cnt[7]++;
    }

    rep(i, 1, 7)
    {
        min1 = min(min1, cnt[i]);
        //cout << min1 << ' ';
    }

    if( 2 * min1 <= cnt[5]  )
        cout << min1<<endl;
    else
        cout << cnt[5] / 2 <<endl;
}
}
