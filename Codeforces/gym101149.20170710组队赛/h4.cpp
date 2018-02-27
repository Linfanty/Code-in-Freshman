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
    for(int i = 0; i < len; i++)
        if(s[i] == '(') l++;
            else if(s[i] == ')') r++;

    if( len % 2 || s[0] == ')' || s[len - 1] == '(' )
        flag = 1;
    else
    {
        for(int i = 0; i < len && l < len / 2; i++)
        {
            if(s[i] == '?')
                s[i] = '(', l++;
        }
        for(int i = len - 1; i >= 0 && r < len / 2; i--)
        {
            if(s[i] == '?')
                s[i] = ')', r++;
        }
    }

    if( flag == 1 || r != l)
        cout <<"Impossible"<<endl;
    else cout << s << endl;
}
