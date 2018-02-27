#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
const double PI = acos(-1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
template<class T> inline T Min(T a, T b) { return a < b ? a : b; }
template<class T> inline T Max(T a, T b) { return a > b ? a : b; }
bool cmpbig(int a,int b){return a>b;}
bool cmpsmall(int a,int b){return a<b;}
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
        // cout << q << ' ' << k << endl;
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
         //cout << i << ' ' << q << endl;
    }
    return cnt;
}

char t[ 1000005 ], p[1000005 ];
int main()
{
    int T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%s", p);
        scanf("%s", t);
        printf("%d\n",kmp(t, p));
    }
    return 0;
}

