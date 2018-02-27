#include<stdio.h>
typedef long long ll;
ll C[26][26];
int main()
{
	C[1][0] = C[1][1] = 1;
    for (int i = 1; i <= 25; i++)
        C[i][0] = 1;
    for (ll i = 2; i <= 25; i++)
        for (ll j = 1; j <= i; j++)
            {
            	C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
			}
}
