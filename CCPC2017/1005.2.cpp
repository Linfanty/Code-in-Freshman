#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
     int t;
     scanf("%d", &t);
     while(t--){
          int n;
          scanf("%d", &n);
          ll x = sqrt(n/2);
          ll l = x * x * 2;
          ll r = (x + 1) * (x + 1) * 2;
          ll ans;
          if(n == l)
               ans = x * 4;
          else if(n - l <= x - 1)
               ans = x * 4 + 1;
          else if(n - l < (r - l) / 2)
               ans = x * 4 + 2;
          else if(n - l <= (r - l) / 2 + x - 1)
               ans = x * 4 + 3;
          else
               ans = x * 4 + 4;
          if(n == 1 || n == 2)
               ans = 4;
          printf("%I64d\n", ans);
     }
     return 0;
}
