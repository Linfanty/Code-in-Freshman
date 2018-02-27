#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <stdio.h>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 500005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define rep(i,a,b) for(int i=a;i<=b;i++)
//const int N = 2e5 + 5;
using namespace std;
typedef long long int ll;

ll n;
ll a[maxn];
ll cnt = 0;
//��Ϊ�������䶼������ģ����a[i]>a[j]˵��a[i]~a[mid]������a[j]
void zonghe(int low, int mid, int high)
{
    int i = low, j = mid + 1;
    while( i <= mid && j <= high)
    {
        if( a[i] <= a[j]) // 0 <= 4 1 <= 4
            i++;
        else               // 9 > 4 9 > 5
        {
            j++;
            cnt += mid - i + 1; //  cnt���� a[i]>a[mid] ֮��ĸ��� ��Ϊ������
        }
    }
    sort(a+low, a+high+1); // ��������
}


void debug(int low, int high)
{
    if( low < high)  // С��(��������) ��鲢����
    {
        int mid = (low + high) / 2;
        debug(low, mid);  // ����
        debug(mid+1, high);//����
                                // �������ˣ� 0 1 9 \ 4 5
        for(int i = 1; i <= n; i++)
            cout << a[i];
        cout << endl;
        zonghe(low, mid, high);  // ��ͳ��ÿ�����������ֵ������� 019 \ 45
    }
}

int main()
{
while(cin >> n)
{
    if( n == 0)
        break;
    cnt = 0;

    rep(i, 1, n)
        cin >> a[i];  // 9 1 0 5 4
    /*���� ��ʱ
    rep(i, 1, n)
    {
        rep(j, 1, i)
        {
            if( a[j] > a[i])
                cnt++;
        }
    }
    */
    debug(1, n);
    cout << cnt << endl;

}
}
