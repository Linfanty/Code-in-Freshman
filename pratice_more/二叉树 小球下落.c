//������ С������ ��������ҹ��� 
#include<stdio.h>
const int MAXD=20;
int s[1<<20];//���ڵ����Ϊ2��20�η�-1�� 
int main()
{int D,I;
    //printf("%d",s[1048575]);
 while(scanf("%d""%d",&D,&I)==2)
 {
                                int i,k=1;
                                for(i=0;i<D-1;i++)
                                if(I%2)
                                {k=k*2;
                                I=(I+1)/2;
                                }
                                else {k=k*2+1;
                                     I=I/2;
                                     }
 printf("%d\n",k);
 }  
 
 
 
 
 
 
 
 
 system("pause");   
 } 
