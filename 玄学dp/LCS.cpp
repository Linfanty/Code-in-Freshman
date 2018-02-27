#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define N 400
#define maxn 100100

int LCS(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    int c[len1+1][len2+1], result = 0;

    for(int i = 0; i <= len1; i++)
        for(int j = 0; j <= len2; j++)
        {
            if( i == 0 || j == 0 )
                c[i][j] = 0;
            else if (s1[i-1] == s2[j-1] )
                c[i][j] = c[i-1][j-1] + 1;
            else c[i][j] = max(c[i-1][j], c[i][j-1]);
        }
    return c[len1][len2];
}

int lcs(string s1, string s2)//zichuan
{
    int len1 = s1.length();
    int len2 = s2.length();
    int c[len1+1][len2+1], result = 0;

    for(int i = 0; i <= len1; i++)
        for(int j = 0; j <= len2; j++)
        {
            if( i == 0 || j == 0 )
                c[i][j] = 0;
            else if (s1[i-1] == s2[j-1] )
            {
                c[i][j] = c[i-1][j-1] + 1;
                result = max(c[i][j], result);
            }
            else c[i][j] = 0;
        }
    return result;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << LCS(s1, s2) << endl;
}
