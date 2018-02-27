#include<stdio.h>
#include<math.h>
int a[30001],b[30001];
int main()
{
 int n,i,j,k;
 while(scanf("%d",&n)!=EOF)
 {
  b[0]=0;k=0;
  for(i=0;i<n;i++)
  {
   scanf("%d",&a[i]);
   for(j=0;j<=k;j++)
   {
    if(a[i]<b[j])
    {
     b[j]=a[i];
     break;//如果后面的高度比前面的小，则把后面的代替前面的。
    }
    else if(j==k)
    {
     k++;//当后面的高度比前面各系统的最小高度都大时，则系统增加1，此时此系统的最小高度为当前值。
     b[k]=a[i];
     break;
    }
   }
  }
  printf("%d\n",k);
 }
 return 0;
}
/*总结：
动态规划题基本上都少不了双循环。此题的关键在于只能拦截比上一高度小的导弹，故把最小值存进一数组，再把后面的高度和这些最小值进行比较。
比最小值小则换，比最小值大则系统增加。
*/
