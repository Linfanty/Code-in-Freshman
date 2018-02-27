#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define INF 0x7fffffff

int a[105], b[105];       //boy，girl
/*解题思路：贪心。
把两个数组都从小到大排序，
再依次用当前最小的去跟对方比，
若符合条件，则双方下标都++；
若自己太低，则自己下标++，否
则对方下标++。
*/
int main()
{
    #ifdef sxk
        freopen("in.txt","r",stdin);
    #endif
    int n, m;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
            scanf("%d", &b[i]);
        sort(a, a+n);              //排序
        sort(b, b+m);
        int ans = 0;
        for(int i=0, j=0; i<n && j<m;){
            if(abs(a[i]-b[j])<=1) {     //符合条件
                ans++;
                i++;
                j++;
            }
            else if(a[i] > b[j]){        //对方太低
                j++;
            }
            else  i++;                   //自己太低
        }
        printf("%d\n", ans);
    }
    return 0;
}
