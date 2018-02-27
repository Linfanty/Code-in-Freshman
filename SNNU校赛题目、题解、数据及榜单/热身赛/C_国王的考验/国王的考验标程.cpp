#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
 
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        int ans=0;
        int temp;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            ans=ans^temp;
        }
        printf("%d\n",ans);
    }
    return 0;
}