#include<stdio.h>
//ÁíÒ»ÖÖÐ´·¨ 
int main() {
	int n,t;
	int a[10010][10];
	for(int i=1; i<10010; i++) 
	{
		for(int j=i; j; j/=10)
		{
			a[i][j%10]++;
		}
	}
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&t);
		for(int i=0; i<10; i++)
			printf("%d ",a[t][i]);
		printf("\n");
	}
	return 0;
}
