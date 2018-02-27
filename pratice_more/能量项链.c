#include<stdio.h>
void quick_sort(long int s[], int l, int r)
{
    if (l < r)
    {
              //Swap(s[l], s[(l + r) / 2]); //将中间的这个数和第一个数交换 参见注1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // 从右向左找第一个小于x的数
                            j--; 
            if(i < j)
                            s[i++] = s[j];
                    
            while(i < j && s[i] < x) // 从左向右找第一个大于等于x的数
                            i++; 
            if(i < j)
                            s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // 递归调用
        quick_sort(s, i + 1, r);
    }
}
main()
{   long int a[1000];
    long int i,j,k;
    long int sum=0;
    int n;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    scanf("%d",&a[i]);
    
    quick_sort(a,0,n);
    
    for(i=0;i<n-1;i++)
    {sum+=a[i]*a[i+1];
    
                    }
    printf("%d\n",a[n-1]*sum);
//return 0;
for(;;)
;
}
/*
通过上面的分析，可以知道，暴力枚举是行不通的。这题就是要用你提到的DP（动态规划来做的）。
用DP（动态规划）的做法是：

1)设有 N 颗珠子，信息保存在 pearls[N]中
 
2)energy[i][j] 表示从第 i 颗珠子到第 j 颗珠子能获得的最大能量，
  初始设置为-1，表示还没有计算出来。 

3)当 i==j ，是同一颗珠子，energy[i][j]=0

  当 (i+1)%N==j，表示的是两颗相邻的珠子，能获得能量为： 
  energy[i][j] = pearls[i]*pearls[(i+1)%N]*pearls[(i+2)%N]
  
  其他情况，在 i,j 之间任意选一个位置 k(i<=k<j)断开，计算：
  	a) 第 i 颗珠子到第 k 颗珠子的最大能量：energy[i,k]，
	   也就是第 k 颗珠子左边所有珠子的最大能量;
  	b) 第 k+1 颗珠子到第 j 颗珠子的最大能量：energy[k+1,j]，
	   也就是第 k 颗珠子右边所有珠子的最大能量;
　　c) 第k可珠子左边和右边计算能量后，各剩下一颗珠子，这两颗珠子获得的能量为： 
       pearls[i]*pearls[k]*pearls[(j+1)%N]
  a,b,c三部分的能量相加，就是当选择 k 位置断开后，在珠子 i,j直接能获得的最大能量。
  如果这个能量比原来的 energy[i][j] 要大，energy[i][j] 就更新为这个能量值。
  
4) energy[0][N-1]就是题目要求的，使用N颗珠子能获得的最大能量。
*/
