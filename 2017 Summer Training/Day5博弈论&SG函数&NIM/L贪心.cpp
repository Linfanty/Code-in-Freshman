/// 1.当$甲最小的字符<乙最大的字符$时，两者均靠左放置最小/大字符
/// 2.当$甲最小的字符>=乙最大的字符$时，两者均靠右放置最大/小字符
#include <bits/stdc++.h>
#include <iostream>
#include <deque>
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(ll i = a; i < b; i++)
const int maxn = 40005;
char s1[300005], s2[300005], s3[300005], s4[300005];

vector<char> ans;
deque<int> dq;
vector<char> s11;
vector<char> s22;
vector<char> :: iterator it;


bool check()
{
    if
}

int main() {
    cin >> s1 >> s2;
    int len = strlen(s1);
    sort(s1, s1 + len, less<char>());
    sort(s2, s2 + len, greater<char>());
    /// cout << s1 << endl << s2 << endl;

    int i = 0, j = 0, vita = 0, vitb = 0, lasta = len/2, lastb = len/2;
    if( len & 1 );
    else lasta++;
    int cnt = 0, ft = 0, ed = len - 1;

    while(1)    {
        if(cnt >= len - 1 || ft + 1 == ed)
            break;

        if( vita == 0 && s1[i] < s2[j])
        {
            dq.insert(ft,s1[i]);
            i++;
            ft++;
            vita = 1;
            vitb = 0;
        }
        else if( vita == 0 && s1[i] >= s2[j])
        {
            dq.insert(ed, s1[lasta]);
            lasta--;
            ed--;
        }
        ++cnt;

        if(cnt >= len - 1 || ft + 1 == ed)
            break;

        if( vitb == 0 && s1[i] < s2[j])
        {

            vitb = 1;
            vita = 0;
        }
        else if(vitb == 0 &&  s1[i] >= s2[j] )
        {
            dq.insert(ed, s2[lastb]);
            lastb--;
            ed--;
        }
    }
}
