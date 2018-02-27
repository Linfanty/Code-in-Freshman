#include <bits/stdc++.h>
#define _xx ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
typedef long long ll;
ll a, b;

bool cmp(const string& s1, const string& s2)    //s1 <= s2 ? true : false
{
    if(s1.size() == s2.size())
    {
        for(int i = 0; i < s1.size(); i++)
            if(s1[i] != s2[i]) return s1[i] < s2[i];
        return true;
    }
    else s1.size() < s2.size();
}

bool isok(const string& s)
{
    ll x = 0, y = 0;
    for(int i = 0; i < s.size(); i++)
    {
        x = (x*10 + s[i] - '0')%a;
        y = (y*10 + s[i] - '0')%b;
    }
    return x != 0 && y != 0;
}

void addone(string& s)
{
    int i;
    for(i = s.size() - 1; i >= 0; i--)
        if(s[i] != '9') break;
        else s[i] = '0';
    s[i]++;
}

int main()
{_xx
    freopen("in1.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    string s1, s2, ans;
    int t = 0;
    while(cin >> a >> b >> s1 >> s2)
    {
        if(a == 1 || b == 1)
        {
            cout << -1 << endl;
            continue;
        }
        s2.insert(0, "0");
        while(s1.size() < s2.size()) s1.insert(0, "0");
        ans = "-1";
        while(cmp(s1, s2))
        {
            if(isok(s1))
            {
                ans = s1;
                break;
            }
            else addone(s1);
        }
        ans.erase(0, ans.find_first_not_of("0"));
        cout << ans << endl;
    }
    return 0;
}
