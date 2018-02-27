#include<stdio.h>
int deep=0;
char s[100]={0};
void convert(int n)
{
if(n==0)return ;
convert(n/10);
s[deep]=n%10+'0';
deep++;
}
int main()
{

int n;
scanf("%d",&n);
if(n==0)
{
s[0]='0';
puts(s);
return 0;
}
convert(n);
s[deep]=0;
puts(s);
system("pause");
return 0;
}
