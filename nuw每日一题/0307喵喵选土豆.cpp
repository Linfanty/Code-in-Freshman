/*
���Ǽ�����01����ʾÿһ����ŵ�����ȡ���ǲ�ȡ�����ǣ�����ÿһ��ȡ�����ķ�ʽ������Ψһ�Ķ����ƴ���֮��Ӧ����ȡ1,3,4,7����������Ӧ��Ϊ1001101�����������ţ������������Ӧ������ֵ��1 * 3^0 + 0 * 3^1 + 1 * 3^2 + 1 * 3^3 +0 * 3^4 + 0 * 3^5 + 1 * 3^6 ����ʵ�Ͼ���������ĵ���������չ����ֵ����������Щ01�����ɶ����ƺ͵��������ƵĴ�С��ϵ����ͬ�ģ����ԣ�������k��ķ�����Ӧ�ĵ�01������k�Ķ����Ʊ�ʾ��������һ����01����������Ӧ�������������������������չ����ֵ�����Ǳ���ⷨΪ����k����Ӧ�Ķ����ƴ����������ƴ�תΪʮ���ơ�
*/
#include<iostream>
#include<algorithm>
#include<string.h>
#include<math.h>
#define ll long long
#define IO ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;
void deal(ll x)
{
    ll ans = 0;
    ll k = 1ll;
    while(x){
        ans += (x & 1ll) * k;
        k *= 3ll;
        x = x >> 1;
    }
    cout << ans << endl;
}
int main()
{IO;
    ll T;
    cin >> T;
    for(int i = 1; i <= T; i ++){
        cout << "case " << i << ": ";
        ll n;
        cin >> n;
        deal(n);
    }
    return 0;
}
