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

int main() {
    int n;
    while(~scanf("%d", &n)) {
        int len, st;
        int flag = 0;
        for(len = 12; len >= 1; len--){
            int k = ceil(sqrt(n));
            cout<<k<<endl;
            
            for(st = 2; st <= k; st++) 
			{
                long long sum = 1;
                for(int i = st, j = 0; j < len; i++, j++) 
				{
                    sum *= i;
                    
                }
            	    cout<<"st: "<<st<<endl;
					cout<< "sum: "<<sum<<endl;
				if(n%sum == 0) 
				{
                    flag = 1;
                    break;
                }
            }
            
            if(flag) break;
        }
        if(flag) {
            printf("%d\n", len);
            for(int i = st, j = 0; j < len; i++, j++) {
                printf("%d%c", i, j == len-1 ? '\n' : '*');
            }
        }
        else {
            printf("1\n%d\n", n);
        }
    }
    return 0;
}

