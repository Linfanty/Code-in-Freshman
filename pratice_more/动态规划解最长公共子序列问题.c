/*动态规划解最长公共子序列问题 求解：

引进一个二维数组c[][]，用c[i][j]记录X[i]与Y[j] 的LCS 的长度，
b[i][j]记录c[i][j]是通过哪一个子问题的值求得的，以决定搜索的方向。
我们是自底向上进行递推计算，那么在计算c[i,j]之前，
c[i-1][j-1]，c[i-1][j]与c[i][j-1]均已计算出来。
此时我们根据X[i] = Y[j]还是X[i] != Y[j]，就可以计算出c[i][j]。
*/
#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{
    int i, j;
    
    for(i = 0; i <= m; i++)
        c[i][0] = 0;
    for(j = 1; j <= n; j++)
        c[0][j] = 0;
    for(i = 1; i<= m; i++)
    {
        for(j = 1; j <= n; j++)
        {
            if(x[i-1] == y[j-1])
            {
                c[i][j] = c[i-1][j-1] + 1;
                b[i][j] = 0;
            }
            else if(c[i-1][j] >= c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                b[i][j] = 1;
            }
            else
            {
                c[i][j] = c[i][j-1];
                b[i][j] = -1;
            }
        }
    }
}

void PrintLCS(int b[][MAXLEN], char *x, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    if(b[i][j] == 0)
    {
        PrintLCS(b, x, i-1, j-1);
        printf("%c ", x[i-1]);
    }
    else if(b[i][j] == 1)
        PrintLCS(b, x, i-1, j);
    else
        PrintLCS(b, x, i, j-1);
}

int main()
{
    char x[MAXLEN] = {"ABCBDAB"};
    char y[MAXLEN] = {"BDCABA"};
    int b[MAXLEN][MAXLEN];
    int c[MAXLEN][MAXLEN];
    int m, n;
    
    m = strlen(x);
    n = strlen(y);
    
    LCSLength(x, y, m, n, c, b);
    PrintLCS(b, x, m, n);
    system("pause");
    return 0;
}
