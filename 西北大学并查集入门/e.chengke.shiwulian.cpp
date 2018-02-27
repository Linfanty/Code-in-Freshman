#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

#define maxn 50005
#define mem(a, b) memset(a, b, sizeof(a))

struct Node {
	int pre, relation; //0同类，1表示吃父结点，2表示被父结点吃
}fa[maxn];

int n,k;

int Find(int x) 
{
	if (fa[x].pre == x) return x;
	
	int tmp = Find(fa[x].pre);
	
	fa[x].relation = (fa[x].relation + fa[fa[x].pre].relation) % 3;
	return fa[x].pre = tmp;
}

int main() 
{
	
	scanf("%d%d", &n, &k);
	int ans = 0;
	
	for (int i = 1; i <= n; i++) {
        fa[i].pre = i;
        fa[i].relation = 0;
	}
	
	while (k--) 
	{
		int d, x, y;
		scanf("%d%d%d", &d, &x, &y);
		if (d == 2 && x == y || x > n || y > n) 
		{
            ans++;
            continue;
		}
		
		int fx = Find(x), fy = Find(y);
		
		if (fx == fy) 
			if ((fa[x].relation - fa[y].relation + 3) % 3 != d - 1)
				ans++;
				
		else 
		{
			int relation = (fa[y].relation + d - 1 - fa[x].relation + 3) % 3;
			fa[fx].pre = fy;
			fa[fx].relation = relation;
		}
	}
	
	printf("%d\n", ans);
	
}
