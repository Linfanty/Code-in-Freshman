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
int c[10005];
int main()
{
    int n;
    int t;
    cin >> t;
    while( t )
    {
        --t;
        cin >> n;
        int cnt = 0, sum = 0;
        for(int i = 1; i <= n; i++)
            cin >> a[i];

        sort(a+1, a+n+1);

        if(n == 1)
            cout << a[1] <<  endl << a[1]  << endl;
        else
        {
            for(int i = n ; i >= 3; )
            {
                int mid = a[i-1] + a[1];
                if(mid > 2*a[2])
                {
                    c[cnt++] = a[1]; c[cnt++] = a[2];
                    c[cnt++] = a[1];
                    c[cnt++] = a[i-1]; c[cnt++] = a[i];
                    c[cnt++] = a[2];

                    sum += 2*a[2] + a[1] + a[i];
                    i -= 2;
                }
                else
                {
                    c[cnt++] = a[1]; c[cnt++] = a[i--];
                    c[cnt++] = a[1];
                    sum += a[i+1] + a[1];
                 //   cout << "sum000:" << sum <<endl;
                }
                //cout << "sum001:" << sum <<endl;
            }

            //cout << "sum:" << sum <<endl;
                c[cnt++] = a[1]; c[cnt++] = a[2];
                sum += a[2];

                cout << sum << endl;
                for(int i = 0, j = 0; i < cnt; j++)
                {
                    if(j%2)
                        cout << c[i++] << endl;
                    else {
                        cout <<  c[i] <<' ' << c[i+1] << endl;
                        i  += 2;
                    }
                }
        }
        if(t)
            cout << endl;
    }
}
