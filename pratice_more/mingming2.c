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
int main()
{FILE * in;
FILE * out;
long int a[100000],n,i,j;
in=fopen("D:\\in.txt","r");
out=fopen("D:\\out.txt","w");
fscanf(in,"%d",&a[0]);
n=a[0];

for(i=0;i<n;i++)
{fscanf(in,"%d",&a[i]);}
fclose(in);
quick_sort(a,0,n-1);

int sum,w;

 for (i=sum=0;i<n;i++)     //统计不同数字的个数 
 if (a[i+1]!=a[i]) sum++;
  for (w=1,i=0,j=0;i<sum;i++,j++) //边统计边输出 
   {
       while (a[j+1]==a[j]) {w++; j++;}
       fprintf(out,"%d%s",a[j],(j!=n-1? " ":""));
       w=1;
   }
   //fprintf(out,"\n%d",21%10);
 ///////////////////////////////////////////////////  
 /*      if (a[i+1]!=a[i]) sum++;
for(i=0;i<n;i++)
{
 while(a[i]==a[i+1])
 {w++;}
 fprintf(out,"%d",a[i]);
if(i+1!=n)
fprintf(out," ");
}
*/
fclose(out);
    }



