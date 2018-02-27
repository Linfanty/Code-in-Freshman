#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int s[1000005];
char str[8],a[2]="4",b[5]="62";
int main()
{
    int n,m,i;
 	for(i=1;i<=1000000;i++)
	{
    	itoa(i,str,10); //itoa 函数 
        //sprintf(str,"%d",i);
		if(strstr(str,a)!=NULL||strstr(str,b)!=NULL) //strstr字符串中的查找  
        s[i]=0;
        else
        s[i]=1;
    }
   
    while(scanf("%d%d",&m,&n)!=EOF&&n)
	{
        int sum=0;
        for(int i=m;i<=n;i++){
           sum+=s[i];
        }
        printf("%d\n",sum);
    }
    return 0;
}
