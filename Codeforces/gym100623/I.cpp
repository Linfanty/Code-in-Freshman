#include <bits/stdc++.h>
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
using namespace std;
typedef long long ll;
const int N = 1e3 + 5;

int main()
{
    //freopen("important.in", "r", stdin);
    //freopen("important.out", "w", stdout);
    cout <<"Yes" <<endl;
    int n;
    cin >> n;
    getchar();
    string s;
    getline(cin, s);
    cout << s[0] << '|' << '~' << s[0] ;
    rep(i, 1, n-1)
    {
        getline(cin, s);
        cout << '|'<< s[0];
    }
    cout << "=>" <<s[0] << '|' << '~' << s[0] <<endl;

}
