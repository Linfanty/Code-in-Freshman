#include<stdio.h>
void quick_sort(long int s[], int l, int r)
{
    if (l < r)
    {
              //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
        int i = l, j = r, x = s[l];
        while (i < j)
        {
            while(i < j && s[j] >= x) // ���������ҵ�һ��С��x����
                            j--; 
            if(i < j)
                            s[i++] = s[j];
                    
            while(i < j && s[i] < x) // ���������ҵ�һ�����ڵ���x����
                            i++; 
            if(i < j)
                            s[j--] = s[i];
        }
        s[i] = x;
        quick_sort(s, l, i - 1); // �ݹ����
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

 for (i=sum=0;i<n;i++)     //ͳ�Ʋ�ͬ���ֵĸ��� 
 if (a[i+1]!=a[i]) sum++;
  for (w=1,i=0,j=0;i<sum;i++,j++) //��ͳ�Ʊ���� 
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



