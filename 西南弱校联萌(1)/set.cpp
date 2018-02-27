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
#define max1 100005
#define maxn 50005
#define fin freopen("in.txt","r",stdin);
#define fout freopen("out.txt","w",stdout)
typedef long long ll;
typedef unsigned long long ull;
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)



struct cmp  
{  
    bool operator()(const int &a,const int &b)  
    {  
        return a>b;  
    }  
};  

int main()
{
    ll n;
    /*for(ll i =1; i <= 100; i = i*2)
    {
        s.insert(i);
        if( i%3 == 1)
        {
            ll m = i;
            while( m%3 == 1 )
            {
                m = (m-1)/3 ;
                s.insert(m);
                cout <<i<<' ' << m << endl;
            }
        }
    }
    cin >>n;
    */
    set<int,cmp> s;  // 默认从小到大
	//<int,cmp>    cmp从大到小 
    s.insert(100);
    s.insert(50);
    s.insert(150);
    //set<int>::iterator it;
    
    for(set<int>::iterator it = s.begin(); it!=s.end(); it++)
    	cout << *it << ' ';
    
	 for(set<int>::iterator it = s.begin(); it!=s.end(); it++)
    	cout << *it << ' ';
    	
	/*
    if( s.find(n) == s.end() ) // 查找是否存在 
        cout <<"NO" <<endl;
    else cout <<"YES" <<endl;


    if( s.count(n)!=0 ) 		// 查找是否存在 
        cout << "YES" <<endl;
    else cout <<"NO" <<endl;
	*/
}
