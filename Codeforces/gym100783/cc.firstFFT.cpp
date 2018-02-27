//http://codeforces.com/gym/100783/attachments/download/3773/20142015-acmicpc-southwestern-europe-regional-contest-swerc-14-en.pdf
//����n������Ȼ���ٸ���һ����k,��������Ƿ������n�����е�һ������
//��˵�������������n�����е��������ɣ��������Լ�*2��
/// �� 70 �� Ϊ��Ҫ����
#include<bits/stdc++.h>
using namespace std;
const double PI = acos( -1);
#define FOR(i, a, b) for (int i = (a); i < (b); i++)

typedef double T;
const int MAXN = 1 << 20;
struct cplex {
	T r, i;
	cplex() : r(0), i(0) {}
	cplex(T n) : r(n), i(0) {}
	cplex(T r, T i) : r(r), i(i) {}
	T real() {return r;}
	cplex operator + (cplex b) {return cplex (r + b.r, i + b.i);}
	void operator += (cplex b) {r += b.r, i += b.i;}
	cplex operator - (cplex b) {return cplex(r - b.r, i - b.i);}
	cplex operator * (cplex b) {return cplex(r * b.r - i * b.i, r * b.i + i * b.r);}
	cplex operator *= (cplex b) {T r2 = r * b.r - i * b.i, i2 = r * b.i + i * b.r; r = r2, i = i2;}
	void operator /= (T n) {r /= n, i /= n;}
};
cplex fa[MAXN << 1], fb[MAXN << 1];
void fft(cplex a[], int n, int invert) {
	for (int i = 1, j = 0; i < n; i++) {
		for (int s = n; j ^= s >>= 1, ~j & s;);
		if (i < j) swap(a[i], a[j]);
	}
	for (int m = 1; m < n; m <<= 1) {
		T p = PI / m * (invert ? -1 : 1);
		cplex w = cplex(cos(p), sin(p));
		for (int i = 0; i < n; i += m << 1) {
			cplex unit = 1;
			for (int j = 0; j < m; j++) {
				cplex& x = a[i + j + m], &y = a[i + j], t = unit * x;
				x = y - t;
				y = y + t;
				unit *= w;
			}
		}
	}
	if (invert) for (int i = 0; i < n; i++) a[i] /= n;
}
void multiply(int a[], int b[], long long c[], int na, int nb) {
	int n = 1; while (n < na + nb) n <<= 1;
	for (int i = 0; i < n; i++) fa[i] = fb[i] = cplex(0);
	for (int i = 0; i < na; i++) fa[i] = cplex(a[i]);
	for (int i = 0; i < nb; i++) fb[i] = cplex(b[i]);
	fft(fa, n, 0); fft(fb, n, 0);
	for (int i = 0; i < n; i++) fa[i] *= fb[i];
	fft(fa, n, 1);
	for (int i = 0; i < n; i++) c[i] = (long long) (fa[i].real() + 0.5);
}

const int maxn = 200000 + 10;
int n, m;
int a[MAXN];
long long b[MAXN << 1];

void solve() {
	cin >> n;
	a[0] = 1;
	FOR(i, 0, n) {
		int k; cin >> k;
		a[k] = 1;
	}
	multiply(a, a, b, maxn, maxn);
	/// ����Ĳ���Ϊ a + a -> �ɼӵ�/�ɴﵽ�� b
	cin >> m;
	int ans = 0;
	while (m--) {
		int d; cin >> d;
		if (b[d]) ans++;
	}
	cout << ans << "\n";
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
#ifdef _LOCAL_
	freopen("in.txt", "r", stdin); //freopen("out.txt", "w", stdout);
#endif
	solve();
#ifdef _LOCAL_
	//printf("\nTime elapsed: %dms", 1000 * clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}
