#include <iostream>
#include <cstdio>
#include<climits>
using namespace std;
const int INF = 233333;
int H[11111];

int main(void)
{
    int N, h;
    while(~scanf("%d", &N))
    {
        int cnt = 0;
        for(int i = 0; i < N; i++)
        {
            int tmp = INF, pos;
            scanf("%d", &h);
            for(int j = 0; j < cnt; j++)
            {
                if(H[j] < h) continue;
                if(tmp > H[j]) tmp = H[j], pos = j;
            }
            if(tmp == INF) H[cnt++] = h;
            else H[pos] = h;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
