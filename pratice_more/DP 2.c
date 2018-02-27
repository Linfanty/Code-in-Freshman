#include<stdlib.h>
#include<stdio.h>
#define MAX 10000000
/*
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
 
*/






int main()
{   int f[1000],n,m,v[1000],w[1000],p[1000];
    int i,j,k;
    scanf("%d%d",&m,&n);//m表示背包容量，n表示个数 
    for(i=0;i<n;++i)
    {
    scanf("%d%d",&w[i],&p[i]);//w=重量, p=重要性 
    v[i]=w[i]*p[i];   
      //  scanf("%d%d",&v,&w);//v=价值，w=重量   
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
//C++和C应该都差不多吧。。这个最简洁了 。顺便一句，如果要能无限放的话
//for(int j=m;j>=w;--j)这一句变成for(int j=w;j<=m;++j)就行了。
/*

#include<stdlib.h>
#define MAX 1111
    int f[MAX],n,m,v,w;
int main(){
    int i,j;
    scanf("%d%d",&n,&m);//n表示个数，m表示背包容量 
    for(i=1;i<=n;++i){
        scanf("%d%d",&v,&w);//v=价值，w=重量
        for(j=m;j>=w;--j)
            if(f[j]<f[j-w]+v)
                f[j]=f[j-w]+v;
    }
    printf("%d\n",f[m]);
    return 0;
}

*/
