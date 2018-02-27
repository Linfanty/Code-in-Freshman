#include <iostream>
#include <cstring>
using namespace std;

int a[5][4005];
int main()
{
    int t;
    cin >> t;
    while( t-- )
    {
        memset(a, -1, sizeof(a));
        int n;
        cin >> n; // 4
        int m = n - 1;
        int flag = 0;

        for(int i = 1; i < n; ++i )
        {
            for(int j = 1; j <= m; ++j)
            {
                cin >> a[i%2][j];
                cout << a[(i-1)%2][j] << ' ' << a[(i-1)%2][j+1] << ' ' << a[i%2][j] << endl;
                if( a[(i-1)%2][j] == 1 && a[(i-1)%2][j+1] == 1 && a[i%2][j] == 1)
                    flag = 1;
                else if( a[(i-1)%2][j] == 0 && a[(i-1)%2][j+1] == 0 && a[i%2][j] == 0 )
                    flag = 1;

            }
            --m;
        }


        if( flag == 1)
            cout << "Bad Team!" << endl;
        else cout << "Great Team!" << endl;
    }
}
