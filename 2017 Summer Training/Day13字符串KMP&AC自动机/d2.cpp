#include<iostream>
#include<cstdlib>
#include<stdio.h>
#include<string.h>
using namespace std;
const int maxm = 1000010;     // 模式串的最大长度
char p[maxm];
int  m, next[maxm];
void getNext()
{
        int i = 0, j = next[0] = -1;
        while(i < m)
        {
            if (j == -1 || p[i] == p[j])
            {

                ++i; ++j;
                next[i] = p[i] != p[j] ? j:next[j];

            }
            else
            j = next[j];
        }

}

int main()
{
       while(scanf("%s",p)!=EOF)
       {
           if(p[0]=='.') break;
           m=strlen(p);
           getNext();
           int cc=1;
           if(m%(m-next[m])==0)
           cc=m/(m-next[m]);
           cout<<cc<<endl;
       }
}
