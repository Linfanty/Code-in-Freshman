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

int n, t, p;
int a[10005];
int save[1000][2];

void digui(int n)
{
    int t = 0;
    if( n == 1) {
        cout << a[1] << endl;
    }
    else if(n == 2) {
        cout <<a[1] << ' ' << a[2] << endl;
    }
    else if(n == 3) {
        cout << a[1] << ' ' << a[3] << endl;
        cout << a[1] <<endl;
        cout << a[1] << ' ' << a[2] << endl;
    }
    else{
        int mid = a[1] + a[n-1];

        if( mid < 2 * a[2]){
            cout << a[1] << ' ' << a[n] << endl;
            cout << a[1] << endl;
            cout << a[1] << ' ' << a[n-1] << endl;
            cout << a[1] << endl;
            }
        else{
            cout << a[1] << ' ' << a[2] << endl;
            cout << a[1] << endl;
            cout << a[n-1] << ' ' << a[n] << endl;
            cout << a[2] << endl;
        }
        digui(n-2);
    }
}

int digui1(int n)
{
    int t = 0;
    if( n == 1) t = a[1];
    else if(n == 2) t = a[2];
    else if(n == 3) t = a[1] + a[2] + a[3];
    else{
        int mid = a[1] + a[n-1];

        if( mid < 2 * a[2])
            t = a[n] + 2*a[1] + a[n-1];
        else t = a[1] + 2*a[2] + a[n];
        t += digui1(n-2);
    }
    return t;
}


int main(){

    int m;
    while(cin >> m)
    {
        for(int i = 1; i <= m; i++)
            cin >> a[i];

        sort(a+1, a+m+1);
        cout << digui1(m) << endl;
        digui(m);

    }
}

