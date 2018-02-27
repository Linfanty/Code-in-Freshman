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
using namespace std;

const int kind = 26;
const int maxn = 100100;
int next1[maxn] = {0};
char p[maxn];
char pp[maxn];
char t[maxn];

char mid[maxn];

/// "����ƥ��ֵ"����"ǰ׺"��"��׺"����Ĺ���Ԫ�صĳ���
/// �ƶ�λ�� = ��ƥ����ַ��� - ��Ӧ�Ĳ���ƥ��ֵ

void makeNext (const char p[])
{
    int q, k;// q:ģ���ַ����±ꣻk:���ǰ��׺����
    int m = strlen(p); // ģ���ַ�������
    next1[0] = 0; // ģ���ַ����� ��һ���ַ�������ǰ��׺����Ϊ0
    for(q = 1, k = 0; q < m ; ++q )
    {// �ڶ����ַ���ʼ ���μ���ÿһ���ַ���Ӧ��next1ֵ
        while ( k > 0 && p[q] != p[k] )
        // �ݹ���� p[0] .. p[q] ��������ͬǰ��׺ ����k
            k = next1[k-1]; // ��ǰ����
        if( p[q] == p[k] ) //�����ȣ���ô�����ͬǰ��׺���ȼ�1
            k++;
        next1[q] = k;
        // cout << q << ' ' << k << endl;
    }
}

void getNext(const char *pStr)
{
    int j = 0, j_next = -1, pLen = strlen(pStr);
    next1[j] = j_next;
    int mLen = pLen - 1;
    while (j < mLen)
    {
        if (pStr[++j] != pStr[++j_next])
        {
            next1[j] = j_next;
            while (j_next != -1 && pStr[j] != pStr[j_next]) j_next = next1[j_next];
        }
        else next1[j] = next1[j_next];
    }
}
/*
int kmp(char *source, char* pattern) {
    int i = 0;
    int j = 0;
    int p_len = strlen( pattern );
    int s_len = strlen( source );
    //makeNext(pattern);
    getNext(pattern);

    while (j < p_len && i < s_len) {
        if (j == -1 || source[i] == pattern[j]) {
            i++;
            j++;
        }
        else {
            j = next1[j];
        }
    }
    if (j < strlen( pattern) )
        return -1;
    else
        return i - strlen( pattern );
}
*/

bool kmp(char t[],char p[])
{
    int n = strlen(t), m = strlen(p);
    int cnt = 0;
    makeNext(p);
    // getNext(p);


    int fl = 0;

    for(int i = 0, q = 0; i < n; ++i)
    {
        while( q > 0 && p[q] != t[i])
            q = next1[q-1];
        if( p[q] == t[i] )
            q++;
        if( q == m)
        {
            fl = 1;
            break;
        }
        //  cout << i << ' ' << q << ' ' << cnt << endl;
    }

    if( fl == 1)
        return true;
    else return false;
}

int main()
{
    int n, T;
    scanf("%d", &T);
    while( T-- )
    {
        scanf("%d", &n);
        int max_len = 0;

        for(int i = 1; i <= n ; ++i)
        {
            scanf("%s", p);

            int len = strlen(p);
            if( len > max_len )
            {
                strcpy(t, p);
                max_len = len;
            }

            strcat(p, "#");
            strcat(pp, p);
        }

        int len = strlen(pp);
        int low = 0;
        int flag = 0;

        //cout << endl <<  pp << endl << t << endl;
        for(int i = 0; i < len; ++i)
        {
            if( pp[i] == '#' )
            {
                memset(mid, 0, sizeof(mid));
                strncpy(mid, pp + low, i - low);

                int lenn = i - low;
                if(  !kmp(t, mid) )
                {
                    //  cout << lenn << ' ' << t << mid << ' ' << kmp(t, mid);
                    flag = 1;
                    break;
                }

                low = i + 1;
            }
        }

        if( flag == 1)
            cout << "No"  << endl;
        else cout << t << endl;
        memset(pp, 0, sizeof(pp));
        memset(p, 0, sizeof(p));
        memset(t,0, sizeof(t));
    }
}

