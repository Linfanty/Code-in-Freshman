//poj-2823--单调队列
#include<iostream>
#include<cstdio>
using namespace std;

const int MAX = 1000001;
//两个单调队列
int dq1[MAX];    //一个存单调递增
int dq2[MAX];    //一个存单调递减
int a[MAX];

int main(void)
{
    int i,n,k,front1,front2,tail1,tail2,start,ans;

    while(scanf("%d %d",&n,&k)!=EOF)
    {
        for(i = 0 ; i < n ; ++i)
            scan_d(a[i]);
        front1 = 0, tail1 = -1;
        front2 = 0, tail2 = -1;
        ans = start = 0;

        for(i = 0 ; i < k ; ++i)
        {
            while(front1 <= tail1 && a[ dq1[tail1] ] <= a[i])   //当前元素大于单调递增队列的队尾元素的时候，队尾的元素依次弹出队列，直到队尾元素大于当前当前元素的时候，将当前元素插入队尾
                --tail1;
            dq1[ ++tail1 ] = i;    //只需要记录下标即可

            while(front2 <= tail2 && a[ dq2[tail2] ] >= a[i])   //当前元素小于单调递减队列的队尾元素的时候，队尾的元素依次弹出队列，直到队尾元素小于当前当前元素的时候，将当前元素插入队尾
                --tail2;
            dq2[ ++tail2 ] = i;    //只需要记录下标即可
        }
        printf("%d ",a[ dq2[ front2 ] ]);

        for( ; i < n ; ++i)
        {
            while(front2 <= tail2 && a[ dq2[tail2] ] >= a[i])
                --tail2;
            dq2[ ++tail2 ] = i;
            while(dq2[ front2 ] <= i - k)
                ++front2;
            if(i != n-1)
                printf("%d ",a[ dq2[ front2 ] ]);
        }
        printf("%d\n",a[ dq2[ front2 ] ]);

        //输出最大值
        printf("%d ",a[ dq1[ front1 ] ]);
        for(i=k ; i < n ; ++i)
        {
            while(front1 <= tail1 && a[ dq1[tail1] ] <= a[i])
                --tail1;
            dq1[ ++tail1 ] = i;
            while(dq1[ front1 ] <= i - k)
                ++front1;
            if(i != n-1)
                printf("%d ",a[ dq1[ front1 ] ]);
        }
        printf("%d\n",a[ dq1[ front1 ] ]);
    }
    return 0;
}

