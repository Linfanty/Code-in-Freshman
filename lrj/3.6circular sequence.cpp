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
        strcpy (ans, s);  						//��ʼans 
        for (int i = 0; i < l; ++i)            //ת��4�� 
        {  
            c = s[l - 1];  						//c=ĩβ��ĸ 
            for (int j = l - 1; j >= 1 ; --j)  //*S = DCBA    for(int j=l-1 ;  j>=1  ;j--)
											   //s[j] = s [j-1] ��������*s����ƶ�һλ   
                s[j] = s[j - 1];  			   //ת����*S = DCB  
            s[0] = c;                          //S[0]=S[L-1]ĩβ ��ĸ = A  
            if (strcmp (s, ans) < 0)  			//strcmp ǰ��С  ��С��0 
                strcpy (ans, s);  
        }  
        printf ("%s\n", ans);  
    }  
} 
