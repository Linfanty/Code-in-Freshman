/*初识dp，大问题是求出总序列的最大和，
而每个数都有加到前面作为前面已经加好的和的增量和自己独立成为一个“最大和”的选择，
在这两个选择中的最大和就是局部的最大和，
而保存好第一个最大和，将整个序列的所有局部最大和都求解出来，就能得到全列的最大和*/
#include<stdio.h>
int main()
{
    int i,ca=1,t,s,e,n,x,now,before,max;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       for(i=1;i<=n;i++)
       {
         scanf("%d",&now);
         if(i==1)//初始化 
         {
            max=before=now;//max保留之前算出来的最大和，before存储目前在读入数据前保留的和，now保留读入数据  
            x=s=e=1;//x用来暂时存储before保留的和的起始位置，当before>max时将赋在s位置，s，e保留最大和的start和end位置 
         }
         else {
             if(now>now+before)//如果之前存储的和加上现在的数据比现在的数据小，就把存储的和换成现在的数据，反之就说明数据在递增，可以直接加上 
             {
                before=now;
                x=i;//预存的位置要重置 
             }       
             else before+=now;
              }
         if(before>max)//跟之前算出来的最大和进行比较，如果大于，位置和数据就要重置 
           max=before,s=x,e=i;
       }
       printf("Case %d:\n%d %d %d\n",ca++,max,s,e);
       if(t)printf("\n"); 
    }
    return 0;
}
