#include<stdlib.h>
#include<stdio.h>
#define MAX 10000000
/*
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
 
*/






int main()
{   int f[1000],n,m,v[1000],w[1000],p[1000];
    int i,j,k;
    scanf("%d%d",&m,&n);//m��ʾ����������n��ʾ���� 
    for(i=0;i<n;++i)
    {
    scanf("%d%d",&w[i],&p[i]);//w=����, p=��Ҫ�� 
    v[i]=w[i]*p[i];   
      //  scanf("%d%d",&v,&w);//v=��ֵ��w=����   
    }
    
    
    
    //quick_sort(p,0,n)
    
    
    
    
     for(i=0;i<n;++i)
    {
          for(j=m;j>=w[i];--j)
                            //for(j=w;j<=m;++j)
         if(f[j]<f[j-w[i]]+v[i])
            f[j]=f[j-w[i]]+v[i];
    }
   
     printf("%d\n",f[m]);
     //return 0;
    system("pause");
}
//C++��CӦ�ö����ɡ������������ ��˳��һ�䣬���Ҫ�����޷ŵĻ�
//for(int j=m;j>=w;--j)��һ����for(int j=w;j<=m;++j)�����ˡ�
/*

#include<stdlib.h>
#define MAX 1111
    int f[MAX],n,m,v,w;
int main(){
    int i,j;
    scanf("%d%d",&n,&m);//n��ʾ������m��ʾ�������� 
    for(i=1;i<=n;++i){
        scanf("%d%d",&v,&w);//v=��ֵ��w=����
        for(j=m;j>=w;--j)
            if(f[j]<f[j-w]+v)
                f[j]=f[j-w]+v;
    }
    printf("%d\n",f[m]);
    return 0;
}

*/
