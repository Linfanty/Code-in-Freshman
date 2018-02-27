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
    int n, x, y;
    cin >> n >> x >> y;
    if(( x ==  n/2 || x == n/2+1) && (y == n/2 || y == n/2+1 ))
        cout << "NO";
    else cout << "YES";
}

