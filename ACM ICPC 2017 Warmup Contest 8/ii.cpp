#include <bits/stdc++.h>
using namespace std;
#define maxn 100005
int a[maxn], sz[maxn], dep[maxn], id[maxn], val[maxn], son[maxn], mx[maxn], top[maxn], pre[maxn], tot;
vector<vector<int> >g(maxn);

struct tree{
	long long sm, lazy;
}c[maxn * 4];

void dfs(int x, int fa, int d){
	sz[x] = 1;
	pre[x] = fa;
	dep[x] = d;
	son[x] = 0;
	int cur;
	for(int i = 0; i < g[x].size(); ++i){
		cur = g[x][i];
		if(cur == fa) continue;
		dfs(cur, x, d + 1);
		sz[x] += sz[cur];
		if(sz[son[x]] < sz[cur]){
			son[x] = cur;
		}
	}
}

void dfs1(int x, int tp){
	id[x] = ++tot;
	top[x] = tp;
	if(son[x]){
		dfs1(son[x], tp);
	}
	int cur;
	for(int i = 0; i < g[x].size(); ++i){
		cur = g[x][i];
		if(cur == pre[x] || cur == son[x]) continue;
		dfs1(cur, cur);
	}
	mx[x] = tot;
}

void build(int o, int l, int r){
	c[o].lazy = 0;
	if(l == r){
		c[o].sm = val[l];
		return;
	}
	int mid = l + r >> 1;
	build(o << 1, l, mid);
	build(o << 1 | 1, mid + 1, r);
	c[o].sm = c[o << 1].sm + c[o << 1 | 1].sm;
}

void pushdown(int o, int l, int r){
	if(l == r || c[o].lazy == 0) return;
	int mid = l + r >> 1;
	c[o << 1].lazy += c[o].lazy;
	c[o << 1 | 1].lazy += c[o].lazy;
	c[o << 1].sm += c[o].lazy * (mid - l + 1);
	c[o << 1 | 1].sm += c[o].lazy * (r - mid);
	c[o].lazy = 0;
}

long long query(int o, int l, int r, int L, int R){
	pushdown(o, l, r);
	if(l >= L && r <= R){
		return c[o].sm;
	}
	int mid = l + r >> 1;
	long long ans = 0;
	if(mid >= L) ans += query(o << 1, l, mid, L, R);
	if(mid < R) ans += query(o << 1 | 1, mid + 1, r, L, R);
	return ans;
}

long long getsm(int x){
	int tp = top[x];
    long long ans = 0;
    while(tp != 1){
        ans += query(1, 1, tot, id[tp], id[x]);
        x = pre[tp];
        tp = top[x];
    }
    ans += query(1, 1, tot, 1, id[x]);
    return ans;
}

void add(int o, int l, int r, int L, int R, int v){
	pushdown(o, l, r);
	if(l >= L && r <= R){
		c[o].lazy += v;
		c[o].sm += 1LL * v * (r - l + 1);
		return;
	}
	int mid = l + r >> 1;
	if(mid >= L) add(o << 1, l, mid, L, R, v);
	if(mid < R) add(o << 1 | 1, mid + 1, r, L, R, v);
	c[o].sm = c[o << 1].sm + c[o << 1 | 1].sm;
}
int main(){
	int n, m, u, v;
	char op[10];
	scanf("%d %d", &n, &m);

	for(int i = 1; i <= n; ++i)
		a[i] = 1;

	for(int i = 1; i < n; ++i){
		scanf("%d %d", &u, &v);
		g[u].push_back(v);
		g[v].push_back(u);
	}

	tot = 0;
	dfs(1, 0, 1);
	dfs1(1, 1);

	for(int i = 1; i <= n; ++i){
		val[id[i]] = a[i];
	}

	build(1, 1, tot);

	int flag = -1; // hong : 1

	for(int i = 1; i <= m; ++i){
		scanf("%s", op);
		if(op[0] == 'I'){

			scanf("%d", &u);
			val[u] = -val[u];
			add(1, 1, tot, id[u], mx[u], flag);

			flag = -flag;
		}
		else
        {
			scanf("%d", &u);
			getsm(u);

			if( c[u].sm == 0 )
			{
			    if( val[u] == 1)
                    printf("B\n");
                else printf("R\n");
			}
            else
            {
			    if( val[u] == -1)
                    printf("B\n");
                else printf("R\n");
			}
			//printf("%lld ", getsm(u));
			//printf("%d %d %d %d %d\n", a[u], val[u], id[u], val[a[u]], c[u].sm);
		}
	}
}

/*
���⣺һ������1e5���ڵ㣬ÿ���ڵ���Ȩֵ��1e5�β�����ÿ�β���Ҫô�޸�ĳ�ڵ��ֵ��
Ҫô�޸Ľڵ��Լ������������е��ֵ��Ҫôѯ��ĳ�㵽��·�������е��Ȩֵ�͡�

˼·��
�����ʷֵ����⣬���߶�������������޸ĺͲ�ѯ�����������޸����������е�Ĳ������ؼ�
������ô�����������еĵ��Ӧ���߶����ϣ���ʵһ�����������е���������������нڵ��
��С��ŵ�����ţ�dfs���ʾ����ģ�֪������ͼ��ˣ�ά��һ������ż��ɣ���С���
���Ǹ��ڵ��Լ��������޸ĺ�·���Ͳ�ѯ���ǻ��������ˡ�
*/
