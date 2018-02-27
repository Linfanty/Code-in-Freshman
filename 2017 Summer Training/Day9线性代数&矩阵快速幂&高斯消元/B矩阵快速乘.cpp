#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ULL unsigned long long
struct Matrix
{
    ULL m[3][3];
} I,A,B,T;

int ssize = 2;

Matrix Mul(Matrix a,Matrix b)
{
    int i, j, k;
    Matrix c;
    for(i = 1; i <= ssize; i++)
    {
        for(j = 1; j <= ssize; j++)
        {
            c.m[i][j]=0;
            for(k = 1; k <= ssize; k++)
            {
                c.m[i][j] += (a.m[i][k] * b.m[k][j]);
            }
        }
    }
    return c;
}

Matrix quickpagow(ULL n)/// a i 的 n-1 次方
{
    Matrix m = A, b = I;
    while(n > 0)
    {
        if(n & 1)
            b = Mul(b,m);/// I * a
        n = n >> 1;
        m = Mul(m,m);
    }
    return b;
}

int main()
{
    ULL p, q;
    ULL a, b, n;
    int t;
    int cas = 0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%llu%llu%llu",&p,&q,&n);
        memset(I.m,0,sizeof(I.m));
        memset(A.m,0,sizeof(A.m));
        memset(B.m,0,sizeof(B.m));
        for(int i = 1; i <= ssize; i++)
            I.m[i][i]=1;//单位矩阵

        A.m[1][1] = p;//初始化等比矩阵
        A.m[1][2] = -q;
        A.m[2][1] = 1; A.m[2][2] = 0;

        B.m[1][1] = p;
        B.m[2][1] = 2;
        B.m[1][2] = 0;
        B.m[2][2] = 0;
        /// F(0) = 2   F(1) = a+b = p

        if(n == 0)
        {
            printf("Case %d: 2\n",++cas);
            continue;
        }
        /// A ^ n-1
        T = quickpagow(n-1);//注意n-1为负的情况
        T = Mul(T,B);///  T = (A ^ n-1) * b
        printf("Case %d: %llu\n",++cas,T.m[1][1]);
    }
    return 0;
}
