#include<stdio.h>

/*void quick_sort(long int s[], int l, int r)
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
 
*/
/*int abc(long int k)
{
if(k==1)
return '';
else if(k==-1)
return '-'; 
else return k;  
    }

*/
main()
{ char ch;
  long long int i=0,j,t,r,b,k,n;
  long int x[10000],y[10000];
  FILE * in;
  FILE * out;
  in=fopen("Math.in","r");
  out=fopen("Math.ans","w");                    
  
 //for(i=0;(ch=fgetc(in))!=EOF;i++)
  while(!feof(in))
{fscanf(in,"%d%d",&x[i],&y[i]);
//fscanf(in,"%d%d",&x[i+1],&y[i+1]);
//fscanf(in,"%d%d",&x[i+2],&y[i+2]);
//fscanf(in,"%d%d",&x[i+3],&y[i+3]);
++i;
}

n=i;
i=0;
for(i=0;i<n;i++) 
{
/*if(x[i]!=0)
{t=x[i];
 x[i]=x[i+1];
 x[i]=t;
 
 r=y[i];
 y[i]=y[i+1];
 y[i]=r;
 }
  */               
if(x[i]==0)               
{b=y[i];
k=((y[i+1])-b)/(x[i+1]);}
if(x[i]!=0)
{b=y[i+1];
k=((y[i])-b)/(x[i]);}

if(x[i]==y[i] || x[i+1]==y[i+1])
{fprintf(out,"Error\n");
//return 0;
++i; 
continue;
}

if(k==1&&b>0)
fprintf(out,"y=x+%d\n",b);
else if(k==-1&&b>0)
fprintf(out,"y=-x+%d\n",b);
else if(k==1&&b<0)
fprintf(out,"y=x%d\n",b);
else if(k==-1&&b<0)
fprintf(out,"y=-x%d\n",b);
else if(b<0)
fprintf(out,"y=%dx%d\n",k,b);
else if(k!=-1&&k!=1&&b>0)
fprintf(out,"y=%dx+%d\n",k,b);
++i;


}
fclose(in);
fclose(out);
return 0;
}
