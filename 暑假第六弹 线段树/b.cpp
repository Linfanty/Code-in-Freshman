#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
using namespace std;
const int maxn = 200005;
    int mx[maxn*3], sum[maxn*3];
    char op[10];
    int a, b, n, m, t, ww = 1;
        #define lson rt<<1, l, (l+r)>>1
        #define rson rt<<1| 1, ((l+r)>>1)+1, r

    void pushup(int rt){
        mx[rt] = max(mx[rt<<1], mx[rt<<1|1]);
        sum[rt] = sum[rt<<1] + sum[rt<<1|1];
    }

    void build(int rt, int l, int r)
    {
        if(l == r)
            {scanf("%d", &mx[rt]); return;}
        build(lson);
        build(rson);
        pushup(rt);
    }

    void update(int rt, int l, int r)
    {
        if(a < l || a > r) return;/**/
        if( l == r )/**/
            {mx[rt] = b;  return;}
        update(lson);
        update(rson);
        pushup(rt);
    }

    int query(int rt, int l, int r)
    {
        if(a <= l && b >= r )   return mx[rt];/*a l_r  b*/
        if(a > r || b < l) return 0;/*a r */ /* b l */
        int ans = 0;

        ans =  max(query(lson), query(rson));
        return ans;
    }

int main()
{
    int m;
    while( scanf("%d %d",&n, &m)  !=EOF)
		{build(1, 1, n);

		while (m--)
        {

            scanf("%s",op);
			if( op[0] == 'E') break;
                scanf("%d %d", &a, &b);

			if(op[0] == 'U')
                update(1, 1, n);

            else if(op[0] == 'Q')
                printf("%d\n", query(1, 1, n));

        }
	}
    return 0;
}
