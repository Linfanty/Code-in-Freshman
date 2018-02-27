#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
const double PI = acos(-1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
using namespace std;

char s[200010];
char *t[12000];
char *io = s;
char *qw;

int main()
{
    int a[] = {1,2,3,4,5, 1,2,3,4,5};
    int b[] = {2,3,4,5,1};
    for(int j = 0; j <= 5; j ++)
    {
        int sum = 0;
        for(int i = 0; i <= 4; i++)
            sum += a[i+j] * b[i];
        cout << sum << endl;
    }
}
/*
1 2 3 4 5
2 3 4 5 1
55
45  (1
40
40
45

A[i] 1 2 3 4 5 1 2 3 4 5
B[i] 1 5 4 3 2

*/
