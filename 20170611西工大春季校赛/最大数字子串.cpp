#include<bits/stdc++.h>
#include <algorithm>
#define rep(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
typedef long long int ll;
/* 13
-1 2 6 -3 5 -7 14 -5 -15 1 8 -4 9
��������a[i],������s[i]��¼���һ����Ϊa[i]ʱ������Ӵ���
״̬ת�Ʒ���Ϊ
s[i] = max(s[i-1]+a[i],a[i]); 1<=i<n-1
��ʼ����s[0]=a[0]
Ȼ��s[i]�����Ԫ�ؼ�Ϊ����
*/
int a, s, n, i, m, num;
int main()
{
    while( cin >> n)
    {
        cin >> s;
        num = s;
        rep(i,2,n)
        {
            cin >> a;
            if( s<0 )
                s = a;
            else s += a;
        //��¼���һ����Ϊa[i]ʱ������Ӵ���

            if( num < s) num = s;
        //Ҫ�������������ܺ�
            cout << "a:"<<a<<" s:"<<s<<" num:"<<num<<endl;
        }
    }
}
/*
13
-1 2 6 -3 5 -7 14 -5 -15 1 8 -4 9
a:2 s:2 num:2
a:6 s:8 num:8
a:-3 s:5 num:8
a:5 s:10 num:10
a:-7 s:3 num:10
a:14 s:17 num:17
a:-5 s:12 num:17
a:-15 s:-3 num:17
a:1 s:1 num:17
a:8 s:9 num:17
a:-4 s:5 num:17
a:9 s:14 num:17
*/
