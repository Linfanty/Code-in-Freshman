#include <stdio.h>
#include<iostream>
int main()
{
char *p[12]={"January","February","March","April","May","June","July","August","September","October","November","December"};
int i;

scanf("%d",&i);
printf("%s \n",p[i-1]);
    system("pause");
    return 0;
}
