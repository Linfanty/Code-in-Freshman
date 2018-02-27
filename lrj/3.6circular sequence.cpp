#include<cstdio>  
#include<cstring>  
using namespace std;  
const int N = 150;  
char s[N], ans[N], c;  
int t, l;  
   
int main()  
{  
  //  scanf ("%d", &t);  
// while (t--)  
    {  
        scanf ("%s", s);  
        l = strlen (s);  
        strcpy (ans, s);  						//初始ans 
        for (int i = 0; i < l; ++i)            //转化4次 
        {  
            c = s[l - 1];  						//c=末尾字母 
            for (int j = l - 1; j >= 1 ; --j)  //*S = DCBA    for(int j=l-1 ;  j>=1  ;j--)
											   //s[j] = s [j-1] 整体数组*s向后移动一位   
                s[j] = s[j - 1];  			   //转化成*S = DCB  
            s[0] = c;                          //S[0]=S[L-1]末尾 字母 = A  
            if (strcmp (s, ans) < 0)  			//strcmp 前面小  则小于0 
                strcpy (ans, s);  
        }  
        printf ("%s\n", ans);  
    }  
} 
