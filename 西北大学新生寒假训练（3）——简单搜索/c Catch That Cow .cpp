//author QJS;
/*������ר���У����Ǿ����õ������㷨��һ����DFS�����������������BFS(���������������
�������� �����ǲ��ö��е���ʽ�������Ƚ��ȳ����ͺñ������ŶӳԷ�һ����������ǰ��ģ��ҾͿ����ȴ򵽷���
�������У����ǽ�����������
��Ž������ã���ȡ�����õ�ʱ�򣬾����ȰѷŽ�ȥ����ȡ����ʹ�á�
�����Ҳ��õ���BFS�㷨����ΪBFS�㷨�Ƚ�ͨ�á�
�ڱ����У�ũ���������ַ�ʽ��һ������ǰ��һ����һ����������һ��������һ����˲�Ƶ�ԭ��λ�õ�������
��BFSѭ����ʱ��Ϳ��Խ�������
�������д��� �߹���λ�ñ�ǡ��������߻�ԭ����λ�á���Ϊ����ǵĻ����ᵼ����ѭ�������ڴ档
���ҵ�ţ��ʱ��������
���ж��Ƿ�Խ���ʱ�򣬲�������Ŀ����˵�������������ڵ�λ�ô���10W��ʱ�򣬾���Ϊ��Խ�硣   ��Ϊ���п�����ȥ��
100010��ʱ�� ���ڻ������������ж���ʱ��Խ������ֵ���Ϊ20W�������Ͳ�������ˡ�
��������BFS�㷨�Ĵ��롣
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
int vis[200000];//������飬�ж�������Ƿ��߹���
int n, m;
int flat;
int bfs()
{
	while (!q.empty())//ÿһ�ζ�����������������
	{
		q.pop();
	}

	memset(vis, 0, sizeof(vis));
	vis[st.x] = 1;//��������ʼ��λ�ñ�ǣ��������߻���
	q.push(st);
	while (!q.empty())//�������л�����������ʱ��һֱѭ��
	{

		point now = q.front();
		if(now.x==m)
			return now.step;//��һ��ʼ����������ţ��λ��һ����ʱ�򣬾�ֱ�ӷ��ء������Ҫ����
		q.pop();
		for (int j = 0; j < 3; j++)//���������ѭ��
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
			if (next.x >= 0 && next.x <= 200000 && !vis[next.x])//�ж��Ƿ�Խ��
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
