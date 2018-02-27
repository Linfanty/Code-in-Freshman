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
         //cout << q << ' ' << k << endl;
    }
}

void kmp(int n)
{
    for(int i = 1; i <= n; ++i)
    {
        int tmp = i - next[i-1]; /// ��ѭ����ѭ����ÿһ�ڵĸ��� �Ƿ���Ա�����
        if( tmp == 0) /// �������� ˵����ѭ����
            continue;
        if( i % tmp == 0 && i / tmp > 1)
            printf("%d %d\n", i,i/ tmp); /// ���Ա�����Ϊ��������
    }
}

char p[1000005];

int main()
{
    int w = 1, t;
    while( scanf("%d", &t)!= EOF && t )
    {
        scanf("%s", p);
        makeNext(p);
        printf("Test case #%d\n",w++);
        kmp(strlen(p));
        printf("\n");
    }
    return 0;
}

