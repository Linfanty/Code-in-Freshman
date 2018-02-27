#include <cstdio>
#include <iostream>
using namespace std;
char str[1000000];
int length;
void read()
{
    char c;
    while(~scanf("%c",&c))
        str[length++] = c;
    str[length++] = '\n';
    str[length] = 0;
}
void step1()
{
    char c = str[0];
    int pos = 0;
    while(c)
    {
        if(c == '/')
        {
            if(str[pos + 1] == '/')
                while(str[pos] != '\n') str[pos++] = 1;
            else if(str[pos + 1] == '*'){
                while(str[pos + 2] != '*' || str[pos + 3] != '/') str[pos++] = 1; 
                str[pos] = str[pos + 1] = str[pos + 2] = str[pos + 3] = 1;
            }
        }
        c = str[++pos];
    }
}
void step2()
{
    char c = str[0];
    int pos = 0;
    while(true)
    {
        if(pos == length) break;
        int f = 0;
        int beg = pos;//本行第一个字符 
        for(;str[pos] != '\n';pos++)
        {
            if(str[pos] == 1) continue;//已经被删除过的字符不必考虑在内 
            if(str[pos] != ' ') {
                beg = pos + 1;
                f = 1;
            }
        }
        //pos 指向/n
        for(int i = beg;i < pos;i++) str[i] = 1; 
        if(!f) str[pos] = 1;
        pos ++;
    }
    str[length-1] = 1;
}
void print()
{
    int pos = 0;
    while(str[pos])
    {
        if(str[pos] != 1) putchar(str[pos]);
        pos++;
    }
}
int main()
{
    freopen("test.txt","r",stdin);
    freopen("out.txt","w",stdout);
    read();
    step1();
    step2();
    print();
}