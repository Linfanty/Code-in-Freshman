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
#define maxn 100005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	fin;
	int n, m;
	cin >> n >> m ;
	char s[55][55];
	
	for(int i = 0; i < n ; i++)
		cin >> s[i];
	
	int flag[55] = {0};
	int zhangai[55] = {0};
	int vit[55] = {0};
	
	for(int k = 0; k < m ; k++)	
	{
		for(int i = 0; i < n ; i++)
		{
			if( s[i][k] == 'o' && vit[k] == 0)
			{
				++flag[k];
				s[i][k] = '.';
			}	
			if( s[i][k] == '#' && vit[k] == 0 )
			{
				zhangai[k] = i;
				vit[k] = 1 ;
			}
		}
	}
	
	//for(int k = 0 ; k < m ; k++)
	//	cout << flag[k]<<endl;
	//cout << vit[1] << endl; 
	//cout << s[2][1]<<endl;
	
	for(int k = 0; k < m ; k++)	
	{
		
			if( vit[k] != 0)
			{
				while( flag[k]-- )
				{
					s[ zhangai[k] - 1 ][ k ] = 'o';
					--zhangai[k];
				}
			}
			else
			{
				int n1 = n;
				while( flag[k]-- )
				{
					s[n1 - 1][ k ] = 'o';
					--n1;
				}
			}
			
	}
	//cout << endl << s[2][1] <<endl;
	
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < m ; j++)		
		{
			cout << s[i][j] ;
		}
		cout<<endl;
	}
	
	return 0;		
}



