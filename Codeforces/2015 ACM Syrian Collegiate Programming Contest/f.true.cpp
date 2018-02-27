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
������ߵ���ͨ���ʵ�����Ͽ��Դ���ABCDE�����YES���������NO
���������
1.ABCDE���У�����Ҫ��ϣ�YES
2.��������ϳ�һ����C(7,2)��ö�ټ���
3.���ĵ���ϳ�������C(7,2)*C(5,2)ö�ټ���
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
            if(!num[i])gg=1;  // ȱ��ABCDE�е�һ�� gg = 1��

        if(gg) // ȱ��
        { // 2.��������ϳ�һ����C(7,2)��ö�ټ��� �ϳ�6��
            for(int i=0;i<7;i++)
                for(int j=i+1;j<7;j++)//j �� i+1 ��ʼö��
                {
                    int a=s[i]-'A'+1,   b=s[j]-'A'+1,   flag=1;
                    // a =      b =         flag = 1
                    // a b �ϳ�
                    num[a]--,num[b]--,num[a+b]++;

                    for(int k=1;k<=5;k++) // ������һ�� Ӧ���е� 5 ����ĸ
                        if(!num[k]) // !NUM[K] �� ����Ϊ 0
                            flag=0;// ����ȱ��ABCDE�е�һ��

                    if(flag)// ABCDE�ж����ˣ� ��ȱ���ˣ�
                        gg=0;
                    // ����
                    num[a]++,num[b]++,num[a+b]--;
                }

            //3.���ĵ���ϳ�������C(7,2)*C(5,2)ö�ټ��� �ϳ�5��
            if(gg)
            {
                for(int i=0;i<7;i++)
                    for(int j=i+1;j<7;j++)
                        // C(7,2)
        for(int ii=0;ii<7;ii++)
            for(int jj=ii+1;jj<7;jj++)
                // C(5,2)
                if( i!=ii && i!=jj && j!=ii && j!=jj )// C�ĸ������
                {
                    int a=s[i]-'A'+1,   b=s[j]-'A'+1;
                    int c=s[ii]-'A'+1,  d=s[jj]-'A'+1;
                    int flag=1;

                    num[a]--,num[b]--,num[a+b]++; // i j �ϳ�
                    num[c]--,num[d]--,num[c+d]++; // ii jj �ϳ�

                    for(int k=1;k<=5;k++)// ������һ�� �ϳɵ� 5 ����ĸ
                        if(!num[k]) // !NUM[K] �� ����Ϊ 0
                            flag=0; // ����ȱ��ABCDE�е�һ��

                    if(flag) // // ABCDE�ж����ˣ� ��ȱ���ˣ�
                        gg=0;

                    // ����
                    num[a]++,num[b]++,num[a+b]--;
                    num[c]++,num[d]++,num[c+d]--;
                }
            }

        }
        // ABCDE�ж����� gg = 0 ; Ϊ YES
        printf("%s\n",gg?"NO":"YES");
    }

    return 0;
}
