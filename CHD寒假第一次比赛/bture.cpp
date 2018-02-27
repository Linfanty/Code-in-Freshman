#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
typedef long long ll;
const int maxn = 105;
using namespace std;
/*对两个数组非降序排序，
如果 ai > bj + 1，那么ai 后面的肯定也和bj 
配对不成功；如果   ai 和 bj 配对成功，
ai+1 和 bj  也能配对成功，
那么这时候我们把bj  和 ai 组在一起，
让ai+1有机会和 bj+1 配对。
*/
int an[maxn],bn[maxn];
 int n,m;
 int main()
 {
     while (scanf("%d",&n)!=EOF)
     {
         for (int i=0 ;i<n ;i++) scanf("%d",&an[i]);
         scanf("%d",&m);
         for (int i=0 ;i<m ;i++) scanf("%d",&bn[i]);
         int cnt=0;
         sort(an,an+n);
         sort(bn,bn+m);
         int j=0;
         for (int i=0 ;i<n ;i++)
         {
             while (j<m && an[i]-bn[j]>1) j++;
             if (j==m) break;
             if (abs(an[i]-bn[j])==1 || an[i]==bn[j]) {cnt++;j++; }
         }
         printf("%d\n",cnt);
     }
     return 0;
 }
