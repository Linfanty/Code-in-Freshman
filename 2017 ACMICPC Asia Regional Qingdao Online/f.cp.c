#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <sstream>
#include <climits>
#include <bitset>
#include <ctime>
#define mem(a, b) memset(a, b, sizeof(a))
using namespace std;

#define ll long long
#define ull unsigned long long
#define ui unsigned int
#define maxn 1000005
#define inf 0x3f3f3f3f




int main() {
	int t;

    freopen("out.txt", "w", stdout);
	for(ll i = 0;i < 100; ++i)
    {
        for(ll j = i+1; j < 100; ++j)
            if( check( a[j] - a[i] ) )
                cout << a[j] - a[i] << ',' ;
    }

}

