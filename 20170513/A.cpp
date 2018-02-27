#include  <bits/stdc++.h>
using namespace std;

int a(int j)
{
    for(int i = 2; i<=sqrt(j); i++)
    {
        if( j%i == 0 )
        {
            return 0;
        }
    }
    return 1;
}

int main()
{

    int b[1000];
    /*
    for(int i = 0; i<=50;i++)
    {
        for(int j = i+1; j<=50; j++)
        {
            for(int k = j+1;k <= 50; k++)
                cout << a[i] * a[j] *a[k] << ',';
                cout <<endl <<endl;
        }
        cout <<endl <<endl;
    }
    */
    for(int i = 2; i <= 10467397; i++)
    {
        if( a(i) == 1)
                cout << i <<',';
    }
}
