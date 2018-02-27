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

string s1, s2;
int t, q[maxn];
vector <int> ans[maxn];

int main()
{
    cin >> s1 >> s2;
    rep(i,0,s1.size()-1)
        if(s1[i] >= 'A' && s1[i] <= 'Z')
            s1[i] = s1[i] - 'A';
        else if(  s1[i] >= 'a' && s1[i] <= 'z' )
            s1[i] = s1[i] - 'a';

    rep(i,0,s2.size()-1)
        if(s2[i] >= 'A' && s2[i] <= 'Z')
            s2[i] = s2[i] - 'A';
        else if(  s2[i] >= 'a' && s2[i] <= 'z' )
            s2[i] = s2[i] - 'a';

    if( s1 < s2)
        cout << -1;
    else if( s1 == s2)
        cout << 0;
    else cout << 1;

}
