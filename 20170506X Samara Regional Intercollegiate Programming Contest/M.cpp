#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll num[2000010];
ll t = 0;
ll nu = 1;
int main()
{
	ll n;
	scanf("%I64d", &n);
	ll sum = 0;
	ll k = 0;
	for(ll i = 0; i < n; i++)
	{
		ll a;
		scanf("%I64d", &a);
		sum += a;
		for(ll j = 0; j < a; j++)
		{
			num[t++] = nu;
		}
		nu++;
	}
	if(sum >= n)
	{
		printf("NO\n");
	}
	else
	{
		printf("YES\n");
		t--;
		for(ll i = 0; i < sum; i++)
		{
			printf("%I64d %I64d\n", num[t--], n--);
		}
	}

	return 0;
}
