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
while(cin >> s)
{

    int len = s.size();

    int l = 0, r = len-1, flag = 0;
    int ll = 0, rr = 0;

    if( len % 2 || s[0] == ')' || s[len - 1] == '(')
    {
        flag = 1;
    }
    else
    {
        rep(i, 0, len-1)
        {
            if( l >= r )
                break;

            if( s[l] == '(' && s[r] == '(')
                ll += 2;
            else if( s[l] == ')' && s[r] == ')' )
                rr += 2;

            l++; r--;
            //cout << s << ' ' << ll <<' ' << rr <<endl;
        }
    }

    l = 0;  r = len-1;

    rep(i, 0, len-1)
    {
        if( l >= r)
            break;
        if( s[l] == '?' && s[r] == '?')
        {
            if(rr >= ll + 2 )
            {
                s[l] = '(';
                s[r] = '(';
                rr -= 2;
            }
            else if( ll >= rr + 2 )
            {
                s[l] = ')';
                s[r] = ')';
                ll -= 2;
            }
            else
            {
                s[l] = '(';
                s[r] = ')';
            }
        }
        else if( s[l] == '?' && s[r] == ')')
        {
            if

        }
        else if( s[l] == '?' && s[r] == '(')
        {


        }
        else if( s[l] == '(' && s[r] == '?')
        {


        }
        else if( s[l] == ')' && s[r] == '?')
        {

        }
        l++;
        r--;
    }

    if( flag == 1 || ll != rr)
        cout <<"Impossible"<<endl;
    else
        cout << s <<endl;
}
}
