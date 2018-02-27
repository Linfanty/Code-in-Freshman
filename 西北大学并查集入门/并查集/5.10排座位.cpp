#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
int pre[105];

int find(int x)
{
	int r = x;
	while( r != pre[r] )
		r = pre[r];
	
	int i = x ,j;
	
	while( i != j)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	return r;
}

void join(int x, int y)
{
	int fx = find(x);
	int fy = find(y);
	if( fx != fy)
		pre[fx] = fy;
}
int vis[105][105];
int main()
{
	memset(vis,0,sizeof(vis));
	int n, m, k, p1, p2, flag, x1, x2;
	cin>>n>>m>>k;
	
	for(int i = 1;i<=n;i++)
		pre[i] = i;
	while(m--)
	{
		cin>>p1>>p2>>flag;
		
		if( flag == 1)
		{
			join( p1, p2);
		}
		else if( flag == -1)
		{
			vis[p1][p2] = 1;
			vis[p2][p1] = 1;
		} 
	}
	while(k--)
	{
		cin >> x1 >> x2 ;
		if(vis[x1][x2] == 1 )
		{
			if(find(x1) == find(x2) )
				cout<<"OK but..."<<endl;
			else cout<<"No way"<<endl;
		}
		else if(find(x1) == find(x2))
			cout<<"No problem"<<endl; //
		else cout<<"OK"<<endl;//..
	}
	cout<<endl<<pre[1]<<' '<<pre[2]<<' '<<pre[3]<<' '<<pre[4]<<' '<<pre[5]<<' '<<pre[6]<<' '<<pre[7]<<endl;
}
/*
7 8 4
5 6 1
2 7 -1
1 3 1
3 4 1
6 7 -1
1 2 1
1 4 1
2 3 -1
3 4
5 7
2 3
7 2
*/
