/*
isalpha�ж��ַ�ch�Ƿ�ΪӢ����ĸ����chΪӢ����ĸa-z��A-Zʱ�����ط���ֵ(��һ����1)�����򷵻���
       ͷ�ļ�Ϊ<ctype.h>
isalnum�ж��ַ�����c�Ƿ�Ϊ��ĸ�����֣���cΪ����0-9����ĸa-z��A-Zʱ�����ط���ֵ�����򷵻��㡣
       ͷ�ļ�Ϊ<ctype.h>
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


