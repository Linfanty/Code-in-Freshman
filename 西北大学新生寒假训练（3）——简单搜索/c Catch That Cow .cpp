//author QJS;
/*在搜索专题中，我们经常用到两种算法，一种是DFS（深度优先搜索）和BFS(广度优先搜索）。
在搜索中 ，我们采用队列的形式，就是先进先出，就好比我们排队吃饭一样，我排在前面的，我就可以先打到饭。
在搜索中，我们讲符合条件的
点放进队列用，在取出来用的时候，就是先把放进去的先取出来使用。
本题我采用的是BFS算法。因为BFS算法比较通用。
在本题中，农场主有三种方式，一种是往前走一步，一种是往后走一步，还有一种是瞬移到原来位置的两倍。
在BFS循环的时候就可以将这三种
操作进行处理。 走过的位置标记。代表不会走回原来的位置。因为不标记的话，会导致死循环，爆内存。
在找到牛的时候跳出。
在判断是否越界的时候，不能像题目中所说，当牧场主所在的位置大于10W的时候，就认为他越界。   因为他有可能先去到
100010的时候 ，在回来。所以再判断是时候，越界的最大值最好为20W。这样就不会出错了。
下面是我BFS算法的代码。
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;
struct point
{
	int x, y, step;
} st;
queue <point> q;
int vis[200000];//标记数组，判断这个点是否走过。
int n, m;
int flat;
int bfs()
{
	while (!q.empty())//每一次都将队列里面的数清空
	{
		q.pop();
	}

	memset(vis, 0, sizeof(vis));
	vis[st.x] = 1;//牧场主开始的位置标记，代表不会走回来
	q.push(st);
	while (!q.empty())//当队列中还有数存在是时候，一直循环
	{

		point now = q.front();
		if(now.x==m)
			return now.step;//当一开始，牧场主和牛的位置一样的时候，就直接返回。这个不要忘记
		q.pop();
		for (int j = 0; j < 3; j++)//三种情况的循环
		{
			point next = now;

			if (j == 0)
			{
				next.x = next.x + 1;
			}
			else if (j == 1)
			{
				next.x = next.x - 1;
			}
			else if (j == 2)
			{
				next.x = next.x * 2;
			}
			++next.step;
			if (next.x == m)
			{
				return next.step;
			}
			if (next.x >= 0 && next.x <= 200000 && !vis[next.x])//判断是否越界
			{
				vis[next.x] = 1;
				q.push(next);
			}
		}
	}
return 0;
}
int main()
{
	while (~scanf("%d %d", &n, &m))
	{
		st.x = n;
		st.step=0;
		printf("%d\n", bfs());
	}

	return 0;
}
