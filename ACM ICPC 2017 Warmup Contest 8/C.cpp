#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
#define maxn 10005
#define ll long long

char s[maxn];
int main()
{
   int n;
   scanf("%d\n", &n);
   for(int j = 0; j < n; j++)
   {
       memset(s, 0, sizeof(s));
       char c; int i = 0;
       while(scanf("%c", &c) && c != '\n')
       {
           if(isalpha(c))
            s[i++] = tolower(c);
       }
       int l = 0, r = strlen(s) - 1;
       bool ok = 1;
       //printf("%s\n", s);
       while(l < r && ok)
        if(s[l++] != s[r--])
            ok = 0;
        printf("%s\n", ok ? "YES" : "NO");
   }

    return 0;
}
