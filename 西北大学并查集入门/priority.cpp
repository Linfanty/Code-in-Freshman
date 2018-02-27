#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i = a;i <= b;++ i)
#define per(i,a,b) for(int i = a;i >= b;-- i)
#define mem(a,b) memset((a),(b),sizeof((a)))
#define FIN freopen("in.txt","r",stdin)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define pb push_back
typedef long long LL;
typedef pair<int, LL> PIR;
const int N = 1e6+5;

int n, k, a[305];
priority_queue<int, vector<int>, greater<int> > Q;

int main()
{
    //FIN;
    cin >> n >> k;
    rep(i, 1, n)    cin >> a[i];  // n = 4
    
    LL ans = 0, pre = 0, tol = 0;
    
    rep(i, 1, k)    Q.push(a[i]); // k = 3

    int id = k+1; 				 // id = 3+1 = 4
    
    while(!Q.empty())
	{
        ans = pre+Q.top(); // min
		
		 Q.pop(); //chu
		 
        pre = ans; //qianyige
        tol += ans; // zong he
        
        if(id <= n)  // 4 <= 4
		{ Q.push(a[id]); id++; } //CONTINUE
    }
    
    cout << tol << endl;
    return 0;
}


