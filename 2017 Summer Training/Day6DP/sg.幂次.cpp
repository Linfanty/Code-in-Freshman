
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int n;
int save[300][300];

int sg(int n)
{
    if( n == 0)
        return 0;
    bool a[20] = {0};
    for(int i = 0; i <= 40; i ++)
    {
        if( (1<<i) > n )
            break;

        a[ sg( n - (1<<i)   ) ] = 1;
    }
    int ans;
    for(ans = 0;ans < 20 ; ans++)
        if( ! a[ans] )
            break;
    return ans;
}

int main()
{
    int n;
    //scanf("%d", &n);
    for(int i = 0; i < 20; i++ )
        printf("%d ", sg(i));

}
