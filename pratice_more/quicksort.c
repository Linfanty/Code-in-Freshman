#include<stdio.h>
#include<string.h>
void quick_sort(int s[], int l, int r)

{
    if (l<r)
    {
             //Swap(s[l], s[(l + r) / 2]); //���м��������͵�һ�������� �μ�ע1
        int i=l,j=r,x=s[l];
        while(i<j)
        {
            while(i<j&&s[j]>=x) // ���������ҵ�һ��С��x����
                                        j--; 
            if(i<j)
                            s[i++]=s[j];                    
            while(i<j&&s[i]<x) // ���������ҵ�һ�����ڵ���x����
                            i++; 
            if(i<j)
                            s[j--]=s[i];
        }
        s[i]=x;
        quick_sort(s,l,i-1); // �ݹ����
        quick_sort(s,i+1,r);
    }
} 
int main()
{
int n,c[100],i;
//memset(c,0,sizeof(c));
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&c[i]);

quick_sort(c,0,n);
for(i=0;i<n;i++)
printf("%d ",c[i]);
system("pause");
return 0;
}




