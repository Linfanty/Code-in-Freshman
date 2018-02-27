/*Sampled Input
2
3
13
Sample Output
0 1 1 1 0 0 0 0 0 0
1 6 2 2 1 1 1 1 1 
*/
#include<iostream>
#include<algorithm>
#include<cmath>
#include<map>
#include<vector>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
int s[10005][10];
int main()
{
	memset(s,0,sizeof(s));
	for(int i=1;i<=10005;i++)
	{
		
		int t = i;
		
			while( t )
				{
					int last = t % 10;
					s[i][last]++;
					t = t /10 ;	
				}	
	
	}
	
	int n,N;
	scanf("%d",&N);
	while(N--)
	{
		scanf("%d",&n);
		
		for(int i=0;i<10;i++)
        {
            if(i)
                cout<<" ";
            cout<<s[n][i];
        }
        cout<<endl;

	}


return 0;
}
