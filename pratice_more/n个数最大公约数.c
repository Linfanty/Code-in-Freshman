#include <stdio.h> 
#include <stdarg.h> 

// 求2个数的最大公约数，辗转相除法 
int GCD(int lhs, int rhs) 
{ 
return rhs % lhs ? GCD(rhs % lhs, lhs) : lhs; 
} 

// n个数的最大公约数 
int NGCD(int n, ...) 
{ int i; 
va_list argPtr; 
va_start(argPtr, n); 
int gcd = va_arg(argPtr, int); 

for(i = 1; i < n; ++i) 
gcd = GCD(gcd, va_arg(argPtr, int)); 
va_end(argPtr); 
return gcd; 
} 
/*
// n个数的积 
int NProduct(int n, ...) 
{ int i;
int pdt = 1; 

va_list argPtr; 
va_start(argPtr, n); 
for(i = 0; i < n; ++i) 
pdt *= va_arg(argPtr, int); 
va_end(argPtr); 
return pdt; 
} 
*/
// n个数的最小公倍数 
//#define NLCM(n, ...) NProduct(n, __VA_ARGS__) / NGCD(n, __VA_ARGS__) 

int main() 
{int a1,a2,a3,a4,a5,a6,a7,a8; 
printf("%d\n",NGCD(5,15,20,25,30,35,45));
//printf("LCM of 3,6,9: %d\n", NLCM(3, 3, 6, 9)); 
system("pause");
return 0; 
}
