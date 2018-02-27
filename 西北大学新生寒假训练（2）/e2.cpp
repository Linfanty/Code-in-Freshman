/*
isalpha判断字符ch是否为英文字母，当ch为英文字母a-z或A-Z时，返回非零值(不一定是1)，否则返回零
       头文件为<ctype.h>
isalnum判断字符变量c是否为字母或数字，当c为数字0-9或字母a-z及A-Z时，返回非零值，否则返回零。
       头文件为<ctype.h>
*/ 

#include <ctype.h>
#include <stdio.h>
int main()
{
    int n, d, i;
    char sym[64];
    scanf("%d%*c", &n);
    while (n--)
    {
        scanf("%s",sym);
        if (sym[0] != '_' && !isalpha(sym[0]))
        {
            puts("no");
            continue;
        }
        for (d = i = 1 ; sym[i] ; i++)
        {
            if (!isalnum(sym[i]) && sym[i] != '_')
            {
                d = 0;
                break;
            }
        }
        puts(d ? "yes" : "no");
    }
    return 0;
}


