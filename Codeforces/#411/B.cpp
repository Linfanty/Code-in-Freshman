#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    int n;
    cin >>n;
    /*if(n == 2)
        cout << "aa" <<endl;
    else if( n == 3)
        cout << "aab" <<endl;
    else if( n == 4)
        cout << "aabb" <<endl;
    else if( n == 5)
        cout << "aabba" <<endl;
    else
*/
    int flag = 0, flag1 = 0;
    if(n%2 == 1)
    {
        n--;
        flag1 = 1;
    }
    for(int i = 1; i <= n; i = i+2)
    {
        if(flag == 0)
        {
            cout << "aa";
            flag = 1;
        }
        else if(flag == 1)
        {
            cout <<"bb";
            flag = 0;
        }
    }
    if(flag1 == 1)
    {
        if(flag == 1)
            cout << "b";
        else cout <<"a";
    }


}
