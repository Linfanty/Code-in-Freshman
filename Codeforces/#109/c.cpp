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

vector<char> s1;
int main()
{
    string s, a[15];
    int n;
    cin >> s;
    int len = s.size();
    rep(i,0, len-1)
        s1.push_back(s[i]);
    cin >> n;

    rep(i, 1, n)
        cin >> a[i];


    int cnt = 0;
    vector<char>::iterator it;
    rep(j, 1, n)
        for(it = s1.begin(); it!=s1.end(); it++)
        {
            //if(*(it+1) == NULL)
            //   break;
            if((*it == a[j][0] && *(it+1) == a[j][1] )
            || (*it == a[j][1] && *(it+1) == a[j][0]))
            {
                //s[i+1] = '9';
                if((*(it-1) == a[j][0] && *it == a[j][1] )
                || (*(it-1) == a[j][1] && *it == a[j][0]))
                s1.erase(it);
                else s1.erase(it+1);
                cnt++;
                //cout << *it << cnt  << endl;
            }
        }

        cout << cnt << endl;
}



