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
int next[500005] = {0};
char p[500005];

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

void kmp(int x)
{
    if( next[x-1] == 0)
        return;
    kmp( next[x-1] );
        printf("%d ", next[x-1]);
}

/*
ababcababababcabab
1 0
2 1
3 2
4 0
5 1
6 2
7 3
8 4
9 3
10 4
11 3
12 4
13 5
14 6
15 7
16 8
17 9
*/

int main()
{
    while( scanf("%s", p) != EOF)
    {
        makeNext(p);
        kmp(strlen(p));
        printf("%d\n", strlen(p));
    }
    return 0;
}

