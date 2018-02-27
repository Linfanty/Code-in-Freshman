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
int a[11],b[11];

int main()
{
    
    for(int i=0; i<6;i++)
        cin >> a[i];
    for(int i=0; i<6;i++)
        cin >> b[i];

    
    double flag = 0;
    double sum = 36;
    for(int i=0;i<6;i++)
	{
    	for(int j = 0 ;j < 6; j++ )
    	{
    		if( a[i] > b[j]) 
				++flag;
			if( a[i] == b[j])
				--sum;
		}
    }
    
    printf("%.5lf",flag/sum);
    
    return 0;
    
}
