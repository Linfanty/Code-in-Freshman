//高精度乘法 
#include<stdio.h>
#include<string.h>
const int maxn = 10;//n=1000时的阶乘大概有3000位个元素 
int f[maxn];
int main()
{
	int i,j,n;
	scanf("%d",&n);
	memset(f,0,sizeof(f));
	f[0]=1;

	for(i=2;i<=n;i++)
	//乘以 i  
	{
	    //算法的关键  
		int c=0;//初始进位数为0  2 6 24 120 720 5040 40320 362880 3628800 
		for(j=0;j<maxn;j++)
		{					// 运算后数字s必定小于100 为两位数  
			int s=f[j]*i+c;	//运算后数字=当前数字 乘以 当前要乘的阶乘数 + 进位数  
			f[j]=s%10;//末尾的数 求数组中应得的位数  运算后数字 取余 s%10  
			c=s/10;  //c为进位数 进几 则c为几    运算后数字  取整 s/10   
		printf("%d %d %d \n",s,f[j],c);
		}
	}
	for(j=maxn-1;j>=0;j--)
		if(f[j]) break;  //忽略f[]数组的前导0  4
	for(i=j;i>=0;i--)
			printf("%d",f[i]);	
	return 0;
}
/*maxn=4 n=4时的
s fj c 
2 2 0
0 0 0
0 0 0
0 0 0
6 6 0
0 0 0
0 0 0
0 0 0
***24 4 2
***2 2 0
0 0 0
0 0 0
24
*/
