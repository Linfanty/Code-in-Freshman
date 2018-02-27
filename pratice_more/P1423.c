#include<stdio.h>
  int main()
   {
     int i,j,sum=1;
     float length,power=2.0;
     scanf("%f",&length);
     length=length-2.0;
     while(length>0.0)
      {
        power=power*0.98;
        length=length-power;
        sum++;
      }
     printf("%d",sum);
   
 
  system("pause");
   return 0;
}
