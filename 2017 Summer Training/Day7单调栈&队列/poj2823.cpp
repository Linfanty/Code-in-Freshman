//poj-2823--��������
#include<iostream>
#include<cstdio>
using namespace std;

const int MAX = 1000001;
//������������
int dq1[MAX];    //һ���浥������
int dq2[MAX];    //һ���浥���ݼ�
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
            while(front1 <= tail1 && a[ dq1[tail1] ] <= a[i])   //��ǰԪ�ش��ڵ����������еĶ�βԪ�ص�ʱ�򣬶�β��Ԫ�����ε������У�ֱ����βԪ�ش��ڵ�ǰ��ǰԪ�ص�ʱ�򣬽���ǰԪ�ز����β
                --tail1;
            dq1[ ++tail1 ] = i;    //ֻ��Ҫ��¼�±꼴��

            while(front2 <= tail2 && a[ dq2[tail2] ] >= a[i])   //��ǰԪ��С�ڵ����ݼ����еĶ�βԪ�ص�ʱ�򣬶�β��Ԫ�����ε������У�ֱ����βԪ��С�ڵ�ǰ��ǰԪ�ص�ʱ�򣬽���ǰԪ�ز����β
                --tail2;
            dq2[ ++tail2 ] = i;    //ֻ��Ҫ��¼�±꼴��
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

        //������ֵ
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

