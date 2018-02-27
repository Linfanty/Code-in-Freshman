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
	//fin;
	int n, m;
	cin >> n >> m ;
	char s[55][55];
	
	for(int i = 0; i < n ; i++)
		cin >> s[i];
	
	for(int i = 0; i < m ; i++)
		s[n][i] = '#';
	
	int flag[55] = {0};
	int zhangai[55] = {0};
	int vit[55] = {0};
	
	for(int k = 0; k < m ; k++)	
	{
		for(int i = n; i >= 0 ; i--)
		{	
			if(s[i][k] == '#')
			{
				int n1 = i-1;
				flag[k] = 0;
				while( s[n1][k] != '#' && n1 >= 0)
				{
					if( s[n1][k] == 'o')
					{
						++flag[k];
						s[n1][k] = '.';
					}
					--n1;
				}
				
				   //cout<<n1<<' ';
				   int n2 = n1;
				   n1 = i-1;
				   //cout<< n1<<' '<<flag[k] <<' ';
				   
				   i = n2+1;
				   //cout<<n2<<endl;
				while( flag[k] --)
				{
					s[n1][k] = 'o';
					--n1;	
				}
				
				///////////
				/*	for(int i = 0; i < n ; i++)
					{
						for(int j = 0; j < m ; j++)		
						{
							cout << s[i][j] ;
						}
						cout<<endl;
					}
				*/
				////////
			}
			

		}
	}
	
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
