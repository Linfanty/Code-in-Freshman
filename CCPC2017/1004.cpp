#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
using namespace std;
int next[1000005] = {0};

/// "����ƥ��ֵ"����"ǰ׺"��"��׺"����Ĺ���Ԫ�صĳ���
/// �ƶ�λ�� = ��ƥ����ַ��� - ��Ӧ�Ĳ���ƥ��ֵ
void makeNext (const char p[])
{
    int q, k;// q:ģ���ַ����±ꣻk:���ǰ��׺����
    int m = strlen(p); // ģ���ַ�������
    next[0] = 0; // ģ���ַ����� ��һ���ַ�������ǰ��׺����Ϊ0
    for(q = 1, k = 0; q < m ; ++q )
    {// �ڶ����ַ���ʼ ���μ���ÿһ���ַ���Ӧ��nextֵ
        while ( k > 0 && p[q] != p[k] )
        // �ݹ���� p[0] .. p[q] ��������ͬǰ��׺ ����k
            k = next[k-1]; // ��ǰ����
        if( p[q] == p[k] ) //�����ȣ���ô�����ͬǰ��׺���ȼ�1
            k++;
        next[q] = k;
       //cout << q << ' ' << k << endl;
    }
}

int kmp(char t[],char p[])
{
    int n = strlen(t), m = strlen(p);
    int cnt = 0;
    makeNext(p);
    for(int i = 0, q = 0; i < n; ++i)
    {
        while( q > 0 && p[q] != t[i])
            q = next[q-1];
        if( p[q] == t[i] )
            q++;
        if( q == m)
            cnt++;
         cout << i << ' ' << q <<' ' << cnt <<  endl;
    }
    return cnt;
}
/// sum = (sum+((1+j)*j/2)%mod)%mod;

char t[ 1000005 ], p[ 1000005], pp[1000005];
int main()
{
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%s", t);
        scanf("%s", p);
        int len = strlen(p);
        for(int i = 0; i < len/2 ; ++i)
            swap(p[i], p[len-1-i]);

        long long int sum = 0;
        for(int i = 1; i <= len ; i++)
        {
            memset(pp, 0, sizeof(pp));
            strncpy(pp, p + 0, i);

            int lenn = strlen(pp);
            for(int i = 0; i < lenn/2 ; ++i)
                swap(pp[i], pp[lenn-1-i]);

            //cout << pp << ' ' <<kmp(t,pp)<< endl;
            sum += i * kmp(t, pp);
            //cout << sum << ' ';
            sum %= 1000000007;
        }
        printf("%lld\n",sum);
        //printf("%d\n",kmp(t, p));
    }
    return 0;
}

