#include <cstdio>
#include <iostream>
using namespace std;

int pre[1000];
int total;

int find (int x)		//���Ҹ��ڵ� 
{
	int r = x;
	while( pre[r] != r)
		r = pre[r];		//���ظ��ڵ� 
		
		int i = x, j;
		
	while( i!=j)   		//·��ѹ�� 
	{
		j = pre[i];		//�ϼ�j 
		pre[i] = r;		//��i�ϼ���Ϊ���ڵ� 
		i = j;			//�ݹ���� 
	}// i = j = pre[i] = r ;
	return r;
}

void join( int x, int y, int &t) //�ж���ͨ  �ϲ�
{
	int fx = find(x);
	int fy = find(y);
	//����ǲ���ͨ�ģ���ô����������֧������
    //��֧�������ͼ�����1�����轨��·Ҳ�ͼ���1
	if( fx != fy)	
		{
			pre[fx] = fy;	
			t--;		
		}
}

int main()
{
	int n, m, p1, p2, i, f1, f2;
	while(scanf("%d %d",&n,&m) && n)
	{
		//�տ�ʼ��ʱ����n������һ��·��û�� 
		//��ôҪ��n-1��·���ܰ�����������
		total = n-1;
		for( int i = 1; i<=n; i++)
		//ÿ���㻥��������Գ�һ�����ϣ���1��ŵ�n
			pre[i] = i;  //����ÿ������ϼ������Լ�
		//scanf("%d", &m); //����m��·
		while(m--) 	//join���� 
		{
			scanf("%d %d",&p1,&p2);
			int f1 = find(p1);
			int f2 = find(p2);
			if( f1 != f2)
			{
				pre[f2] = f1;
				total --;
			}
		}
		cout<<total<<endl;
	}
}




