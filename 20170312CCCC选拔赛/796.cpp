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
#define maxn 10005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

int main()
{
	int n;
	cin>>n;
	int a[4]={n,n+1,n+2,n+3};
	

		
			cout<<n<<n+1<<n+2<<' ';
			cout<<n<<n+1<<n+3<<' ';
			cout<<n<<n+2<<n+1<<' ';
			cout<<n<<n+2<<n+3<<' ';
			cout<<n<<n+3<<n+1<<' ';
			cout<<n<<n+3<<n+2;
			cout<<endl;
			
			cout<<n+1<<n<<n+2<<' ';
			cout<<n+1<<n<<n+3<<' ';
			cout<<n+1<<n+2<<n<<' ';
			cout<<n+1<<n+2<<n+3<<' ';
			cout<<n+1<<n+3<<n<<' ';
			cout<<n+1<<n+3<<n+2;
			cout<<endl;
			
			cout<<n+2<<n<<n+1<<' ';
			cout<<n+2<<n<<n+3<<' ';
			cout<<n+2<<n+1<<n<<' ';
			cout<<n+2<<n+1<<n+3<<' ';
			cout<<n+2<<n+3<<n<<' ';
			cout<<n+2<<n+3<<n+1;
			cout<<endl;
			
			cout<<n+3<<n<<n+1<<' ';
			cout<<n+3<<n<<n+2<<' ';
			cout<<n+3<<n+1<<n<<' ';
			cout<<n+3<<n+1<<n+2<<' ';
			cout<<n+3<<n+2<<n<<' ';
			cout<<n+3<<n+2<<n+1;
			cout<<endl;
			
		
	

}
