#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int main()
{
    int i,cs,testnum;
    int n,number,sum,start,end,temp,max;
    scanf("%d",&testnum);
    for(cs=1;cs<=testnum;cs++)
    {
        max=-1010;
        sum=0;
        temp=1;
        scanf("%d",&n);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&number);
            sum+=number;
            if(sum>max)
            {
                max=sum;
                start=temp;
                end=i;
            }
            if(sum<0)
            {
                sum=0;
                temp=i+1;
            }
        }
        printf("Case %d:\n%d %d %d\n",cs,max,start,end);
        if(cs!=testnum)
        printf("\n");
    }
    return 0;
}
