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
int bear[1003],i,n,Limak,sum=0;
scanf("%d",&n);
scanf("%d",&Limak);
memset(bear,-1,sizeof(bear));
    for(i=0;i<n-1;i++)
    scanf("%d",&bear[i]);


    quick_sort(bear,0,n-2);

    /*for(i=0;i<n-1;i++)
    printf("%d",bear[i]);
    */
    if(Limak>bear[n-2])
    printf("0");
            else 
            {
               while(Limak<=bear[n-2])
                  {   
                          bear[n-2]--;
                          Limak++;
                          sum++;
                          quick_sort(bear,0,n-2);
                  }
                  printf("%d",sum);
            }


system("pause");
return 0;    
}
/*
if(n==2);
{scanf("%d",&bear[0]);
    if(Limak>bear[0])
    printf("0");
    else while(Limak<=bear[0])
    {   
    bear[0]--;
    Limak++;
    sum++;
    } 
    printf("%d",sum);
}
*/




