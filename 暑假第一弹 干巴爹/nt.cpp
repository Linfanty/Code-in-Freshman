#include <cstdio>
typedef long long LL;

LL C(LL n, LL k) {
	if(n - k < k) k = n - k;
	LL ans = 1;
	for(int i = 1; i <= k; i++)
		ans = ans * (n - i + 1) / i;
	return ans;
}

int main() {
	int cas;
	LL n, t, p;
	scanf("%d", &cas);
	while(cas--) {
		scanf("%lld%lld%lld", &n, &t, &p);
		t = t - n * p;
		LL ans = C(n + t - 1, n - 1);
		printf("%lld\n", ans);
	}
	return 0;
}
