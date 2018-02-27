#include  <bits/stdc++.h>
typedef unsigned long long ll;
using namespace std;

int main()
{
	int n;
	cin >> n;
	ll a[105], b[105], sum[105];

	a[1] = 8;
	b[1] = 1;
	sum[1] = 8;
    for(int i = 2; i <= n; i++)
    {
        sum[i] = sum[i-1];

        for(int j = 1; j < i; j++)
        {
            b[j] = b[j] * 10;
            sum[i] += b[j] ;
        }

        sum[i] = 9 * pow(10,i-1) - sum[i];
        b[i] = sum[i] ;
    }

	cout << sum[n] << endl;
}
