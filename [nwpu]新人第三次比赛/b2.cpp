/*Sampled Input
2
3
13
Sample Output
0 1 1 1 0 0 0 0 0 0
1 6 2 2 1 1 1 1 1 
*/
#include<stdio.h>
int a[10010][10];
int main() {
	int n,t;
//	int a[10010][10]; 放到这里在数据大的时候会WA
	for(int i=1; i<10010; i++) 
	{
		for(int j=i; j; j/=10)
		{
			for(int k=i; k<10010; k++)
				{
					a[k][j%10]++;
					//printf("%d %d %d\n",j,k,a[k][j%10]);
					}
		}
	}
	scanf("%d",&n);
	while(n--) {
		scanf("%d",&t);
		for(int i=0; i<9; i++)
			printf("%d ",a[t][i]);
		printf("%d\n",a[t][9]);
	}
	return 0;
}
