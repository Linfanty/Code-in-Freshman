#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

vector<int> pe[3005];
int flag;

int main()
{
    int t;
    scanf("%d", &t);
    while( t-- )
    {
        int n, a;
        scanf("%d", &n);
        for(int i = 0; i <= n; i++)
            pe[i].clear();
        if( n >= 15 )
        {
             cout << "Bad Team!" << endl;
             continue;
        }

        flag = 0;

        for(int i = 1; i < n; ++i )
        {
            for(int j = i+1; j <= n; ++j)
            {
                scanf("%d", &a);

                if( flag == 1)
                    continue;
                if( a == 1)
                    pe[i].push_back(j);


                for(int k = 0; k < pe[i].size(); ++k )
                {
                    for(int p = 0; p < pe[k].size(); ++p )
                    {
                        if( p == j)
                        {
                            //cout << p << endl;
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }


        if( flag == 1)
            cout << "Bad Team!" << endl;
        else cout << "Great Team!" << endl;
    }
}
