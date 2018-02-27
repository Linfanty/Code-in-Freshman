#include <cstdlib>
#include <climits>
#include <queue>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <iostream>
#define maxn 100005
#define fin(i,a,b) for(int i=a ; i<b ;i++)
#define mem(a,b) memset(a,b,sizeof(a)) 
#define fre freopen("in.txt","r",stdin)
#define  atoi atof
typedef long long ll;
typedef unsigned long long ull;
using namespace std; 

int main()
{
	//fre;
	string s;
	int n , k;
	int q[maxn] ;
	while( cin>> n >> k >> s)
	{
		int ans , head , tail , state , status ;
		ans = state = status = 0 ;
		tail = 1 ;
		head = 0 ;
		
		q[0] = 0 ;s[s.size()] = 'b' ;
		//cout << s[s.size()] <<endl;
		for(int i = 0 ; i <= s.size()  ; i ++ )
		{
			if(s[i] == 'b' )
			{
				q[tail] = i ;
				++tail;
			}
			if(tail - head == k + 2  )
			{
				if(head==0)
				state = q[tail-1]  - q[head]  ;
				else 
				state = q[tail-1]  - q[head]  -1 ; 
				++ head ;
				//cout << tail << ' ' << q[tail-1] << ' '<<  state <<endl;
			}
			ans = max ( ans , state );
		}  
		
		//cout << ans<<endl;	
		state = status = 0 ;
		tail = 1 ;
		head = 0 ;
		s[s.size()]='a';
		
		for(int i = 0 ; i <= s.size()  ; i ++ )
		{
			if(s[i] == 'a' )
			{
				q[tail] = i ;
				++tail;
			}
			if(tail - head == k + 2  )
			{
				if(head==0)
				state = q[tail-1]  - q[head]  ;
				else 
				state = q[tail-1]  - q[head]  -1 ; 
				
				++ head ;
			}
			ans = max ( ans , state );
		}  
		
		
		
		cout << ans << endl; 
		
	}	
	return 0;
}



