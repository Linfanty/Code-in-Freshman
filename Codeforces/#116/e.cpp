#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

const int N = 200100;
vector <int> cols[100100];
///对颜色分组 组内用尺取法
int main()
{
    int n, m, k;
    while (~scanf("%d%d%d", &n, &m, &k))
    {
        for (int i = 1; i <= m; ++i)
        {
            cols[i].clear();
        }
        int val;
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &val);
            cols[val].push_back(i);
        }
        int ans = 0;
        for (int i = 1; i <= m; ++i)
        {
            int cnt = cols[i].size();
            int st = 0, ed = st, num = 0;
            while (1)
            {
                while (ed < cnt && num <= k)
                {///sum += sequence[i++];
                    ++ed;
                    if (ed >= cnt)
                        break;
                    num += cols[i][ed] - cols[i][ed - 1] - 1;
                }
                ans = max(ans, ed - st);
                if (ed >= cnt)
                    break;

                ++st;/**/
                num -= cols[i][st] - cols[i][st - 1] - 1;
                ///sum -= sequence[s];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
