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
#define maxn 10000
#define fin(i,a,b) for(int i=a ; i<b ;i++)
#define mem(a,b) memset(a,b,sizeof(a)) 
#define fre freopen("in.txt","r",stdin)
#define  atoi atof
typedef long long ll;
typedef unsigned long long ull;
using namespace std; 


//递归  
int recursion(ll m , ll i ,int stu )
{
	if(m == 0 )
	{
		if(i == 0 )
		return stu;
		else return !stu;
		//break;
	}
	ll ii = pow( 2 , m-1 ); // 预处理 否则会超时 两次变一次 
	if(i >=  ii )
		recursion ( m-1 , i - ii, stu );
	else recursion ( m-1 , i , !stu );
}

int main()
{
	
	ll n , k ;
	while( cin >> n >> k )
	{
		int stu = 0 ;  //0 : up
		int solve = recursion ( n , k , stu );
		if(solve == 0)
		cout<<"up"<<endl;
		else cout<<"down"<<endl;
	}
	
return 0;
}


