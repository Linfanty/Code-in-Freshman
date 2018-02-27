#include <bits/stdc++.h>
#include <algorithm>
#define lid (id << 1)
#define rid (id << 1 | 1)
#define inf 0x3f3f3f3f
#define maxn 2005
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);

//const int N = 2e5 + 5;
using namespace std;

int main(){

    fin;
    fout;
    for(int i = 1; i <= 50000; i++)
    {
        cin >>  i ;
        if( i % 11 == 0)
            cout << "is" << endl;
        else cout << "not" << endl;
    }

}
