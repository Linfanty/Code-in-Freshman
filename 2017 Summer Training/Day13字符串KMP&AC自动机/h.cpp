#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
const double PI = acos(-1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T Min(T a, T b) { return a < b ? a : b; }
template<class T> inline T Max(T a, T b) { return a > b ? a : b; }
bool cmpbig(int a,int b){return a>b;}
bool cmpsmall(int a,int b){return a<b;}
using namespace std;
const int maxn = 100005;
int pre[maxn], dis[maxn], x, y, t, n;
char qu[5];

int fd(int x)
{
    if( pre[x] == x)
        return pre[x];
    int rt = fd(pre[x]);
    dis[x] += dis[pre[x]];
    return pre[x] = rt;
}

int main() {
    scanf("%d", &t);
    while(t--)
    {
       scanf("%d", &n);
       for(int i = 0; i <= n; ++i)
            pre[i] = i, dis[i] = 0;
       while( scanf("%s",qu) && qu[0] != 'O')
       {
          if( qu[0] == 'E')
          {
              scanf("%d", &x);
              fd(x);
              printf("%d\n", dis[x]);
          }
          else
          {
                scanf("%d %d",&x,&y);
                pre[x] = y;
                dis[x] = abs(x-y)%1000;
          }
       }
    }

}



