#include <cstdio>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#include <sstream>
#include <cstdlib>
#include <stack>
#include <climits>
#include <queue>
#include <map>
#include <set>

#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define maxn 1005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(int i = a; i<=b ;++i)
#define per(i,a,b) for(int i = a; i>=b ;--i)

int pre[maxn] = {0}, n, d;

struct Node
{
	int x, y;
	bool flag;
} node[maxn];

double cal(Node xx, Node yy)
{
	//cout << "AAAAA";
	//cout <<"qwe" << sqrt( (xx.x -yy.x) * (xx.x -yy.x) + (xx.y -yy.y) * (xx.y -yy.y) );
	return sqrt( (double)(xx.x -yy.x) * (xx.x -yy.x) +(double) (xx.y -yy.y) * (xx.y -yy.y) );
}

int find(int x)
{
	int r = x;
	
	while( pre[r] != r)
		r = pre[r]; // 返回根节点 
		
	int i = x, j;
	
	if( i != j )
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}  
	return r;
}
/*

int find(int x)
{
	return pre[x] == x ? x : pre[x] = find( pre[x] ) ; 
}
*/
void join(int x, int y)
{
	int px = find(x);
	int py = find(y);
	//cout <<x<<' '<< px <<' '<<y<<' ' << py <<endl;
	if( px == py)
		cout << "SUCCESS" <<endl;
	else
		cout << "FAIL" << endl;
}

void op(int x)
{
	node[x].flag = true;
	int fx = find(x);
	rep(i, 1, n)
	{
		//cout<<"wty";
		
		cal( node[i], node[x]);
		
		if(node[i].flag && i!= x && cal(node[i], node[x]) <= d )
		{ 
			//cout << "aaaaa";
			int fi = find (i);
			pre[fi] = fx;
		}
	}
}

int main()
{
	while( cin >> n >> d )
	{
	
	rep(i, 1, n)
	{
		pre[i] = i ;
		cin >> node[i].x >> node[i].y ;
		node[i].flag = false;
		
	}	
	
	string line;
	while( getline ( cin, line) != 0 )
	{
		//cout << line[0] <<' '<<line[2] <<endl;
		if( line[0] == 'O')
			op( line[2] - '0' );
			//cout << line[2];
		else //if( line[0] == 'S')
			//cout << line[2] << line[4];
			join(line[2] - '0', line[4] -'0') ; // cin lind string 字符 都是字符！！！-‘0’ 
		line = "0";
		
	}		
	
	/*
	char c;
        while (cin >> c) {
            if (c == 'O') {
                int x;
                scanf("%d", &x);
                op(x);
            } else {
                int a, b;
                scanf("%d%d", &a, &b);
                int fa = find(a);
                int fb = find(b);
                //printf("%d %d\n",fa,fb);
                if (fa == fb) printf("SUCCESS\n");
                else printf("FAIL\n");
            }
        }
    */
	
	}
	return 0;
}
