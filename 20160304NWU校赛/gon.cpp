#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <bitset>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <list>
#include <set>
#include <map>
#define rep(i,a,b) for(int i = a;i <= b;++ i)
#define per(i,a,b) for(int i = a;i >= b;-- i)
#define mem(a,b) memset((a),(b),sizeof((a)))
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define mid ((l+r)>>1)
#define ls (id<<1)
#define rs ((id<<1)|1)
#define N 100005
#define INF 0x3f3f3f3f
#define INFF ((1LL<<62)-1)
using namespace std;
typedef long long LL;
typedef pair<int, int> PIR;
const double eps = 1e-8;

int n, k, q[N];     //[l, r)
string s;
int main()
{IO;
    FIN;
    //FOUT;
    while(cin >> n >> k){
        cin >> s;
        int ans, head, tail, st = 0;
        ans = head = tail = 0;
        rep(i, 0, (int)s.size()-1)
		{
            if(s[i] == 'b') 
			q[tail++] = i;
            if(tail-head > k)
			
			{
                st = q[head++]+1;
            }
            ans = max(ans, i-st+1);
            cout << "i: "<< i <<" s[i]:" << s[i] << " tail:" << tail << " head:"<<head 
			<<" st:"<< st << " i-st+1:" <<i-st+1 << " ans:" << ans <<endl;
        }
         
        cout <<endl ;
        
        head = tail = st = 0;
        
        rep(i, 0, (int)s.size()-1)
		{
            if(s[i] == 'a')
			 q[tail++] = i;
            
            
            if(tail-head > k)
			
			{
                st = q[head++]+1;
            }
            ans = max(ans, i-st+1);
            
            cout << "i: "<< i <<" s[i]:" << s[i] << " tail:" << tail << " head:"<<head 
			<<" st:"<< st << " i-st+1:" <<i-st+1 << " ans:" << ans <<endl;
            
        }
        
        cout << ans << endl;
    }
    return 0;
}
