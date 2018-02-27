#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define maxn 30
/*
如果这七道题通过适当的组合可以凑齐ABCDE则输出YES，否则输出NO
三种情况：
1.ABCDE都有，不需要组合，YES
2.把两道题合成一道，C(7,2)的枚举即可
3.把四道题合成两道，C(7,2)*C(5,2)枚举即可
*/
char s[maxn];
int T,num[maxn];

int main()
{
    scanf("%d",&T);

    while(T--)
    {
        memset(num,0,sizeof(num));

        scanf("%s",s);
        int gg=0;
        for(int i=0;i<7;i++) // s[i]-'A'+1
            num[s[i]-'A'+1]++;


        for(int i=1;i<=5;i++)
            if(!num[i])gg=1;  // 缺少ABCDE中的一个 gg = 1；

        if(gg) // 缺少
        { // 2.把两道题合成一道，C(7,2)的枚举即可 合成6个
            for(int i=0;i<7;i++)
                for(int j=i+1;j<7;j++)//j 从 i+1 开始枚举
                {
                    int a=s[i]-'A'+1,   b=s[j]-'A'+1,   flag=1;
                    // a =      b =         flag = 1
                    // a b 合成
                    num[a]--,num[b]--,num[a+b]++;

                    for(int k=1;k<=5;k++) // 暴力跑一遍 应该有的 5 个字母
                        if(!num[k]) // !NUM[K] 即 存在为 0
                            flag=0;// 还是缺少ABCDE中的一个

                    if(flag)// ABCDE中都有了， 不缺少了！
                        gg=0;
                    // 回溯
                    num[a]++,num[b]++,num[a+b]--;
                }

            //3.把四道题合成两道，C(7,2)*C(5,2)枚举即可 合成5个
            if(gg)
            {
                for(int i=0;i<7;i++)
                    for(int j=i+1;j<7;j++)
                        // C(7,2)
        for(int ii=0;ii<7;ii++)
            for(int jj=ii+1;jj<7;jj++)
                // C(5,2)
                if( i!=ii && i!=jj && j!=ii && j!=jj )// C的各不相等
                {
                    int a=s[i]-'A'+1,   b=s[j]-'A'+1;
                    int c=s[ii]-'A'+1,  d=s[jj]-'A'+1;
                    int flag=1;

                    num[a]--,num[b]--,num[a+b]++; // i j 合成
                    num[c]--,num[d]--,num[c+d]++; // ii jj 合成

                    for(int k=1;k<=5;k++)// 暴力跑一遍 合成的 5 个字母
                        if(!num[k]) // !NUM[K] 即 存在为 0
                            flag=0; // 还是缺少ABCDE中的一个

                    if(flag) // // ABCDE中都有了， 不缺少了！
                        gg=0;

                    // 回溯
                    num[a]++,num[b]++,num[a+b]--;
                    num[c]++,num[d]++,num[c+d]--;
                }
            }

        }
        // ABCDE中都有了 gg = 0 ; 为 YES
        printf("%s\n",gg?"NO":"YES");
    }

    return 0;
}
