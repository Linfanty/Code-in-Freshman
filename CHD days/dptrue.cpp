/*
        解题思路：
        应该求最长 不降 子序列。这样的长度才是 最少需要的 套数，
		因为这个序列中的任何两个导弹都不能共用一个拦截系统   ，
		而且其余的导弹 都能和这个最长序列中的某个导弹分为同一组。

*/

#include<cstdio>

int main()
{
    int n,i,j,num,h[1000],max[1000];
    while(~scanf("%d",&n))
    {
        num=0;
        for(i=0;i<n;++i)
        {
            scanf("%d",&h[i]);
            max[i]=1;
        }
        for(i=1;i<n;++i)
            for(j=0;j<i;++j)
            {
                if(h[j]<=h[i]&&max[j]+1>max[i])
                    max[i]=max[j]+1;
                if(num<max[i])
                    num=max[i];
            }
        printf("%d\n",num);
    }
    return 0;
}
