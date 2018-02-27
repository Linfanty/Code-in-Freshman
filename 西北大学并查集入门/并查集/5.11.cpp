#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define maxn 10005

int pre[maxn];
int totalpeople[maxn] = {1} ;
int vit[maxn]={0};
/*
struct Node
{
	int id;
	double area, roomnum;
	int totalnum;
} node[maxn], people[maxn], ans[maxn], p2[maxn];
*/

int find( int x)
{
	int r = x;
	while( r != pre[r] )
		r = pre[r] ;
		
	int i = x,j;
	while( i!= j)
	{
		j = pre[i];
		pre[i] = r;
		i = j;
	}
	//cout<< endl << x <<"     "<<r<< endl;
	return r ;
}

void join(int x, int y)
{
	int px = find(x);
	int py = find(y);
	vit[x] = 0;
	vit[y] = 0;
	//cout<<"px: "<<px<<" py: "<<py<<endl;
	if( px != py )
		{
			if( px > py)
			{
				//cout<<"px: "<<px<<" py: "<<py<<endl;
				pre[px] = py ;
				++totalpeople[py] ;
				vit[py] = 1;  	
			}
			//peo[py] ++ ;
			else 
			{
				//cout<<"px: "<<px<<" py: "<<py<<endl;
				pre[py] = px ;
				++totalpeople[px] ;
				vit[px] = 1; 
			}
		}
}

int main()
{
	int n, home, father, mother;
	cin>> n;
	int N = n;

	for(int i = 1 ;i <= 10000 ;i++)
	pre[i] = i;
	
	while(N--)
	{                                                 
		cin >> home >> father >> mother;
		vit[home] = 1;vit[father] = 1;vit[mother] = 1;
		//cout<<mother<<endl;
		
		if( father != -1 )
	 	join( home, father);
	 	if(mother != -1 )
	 	join( home, mother);
	 	
		//cout<<mother<<endl;
		
		int kids, kid, house, area;
		cin >> kids ;

		if( kids != 0 )
		for(int i =1 ;i <= kids ;i++)
		{
			cin >> kid;
			join( home, kid);
			vit[kid] = 1;
		}
		
		cin >> house >> area;
	 	
		//cout<< home << peo << 
	}
	
	for( int i = 0; i<=maxn ;i++)
	{
		if( totalpeople[i]!=1 &&  vit[i] == 1 )
		{
			cout <<i<<' '<< totalpeople[i] <<endl;
		}
	}
	
}
