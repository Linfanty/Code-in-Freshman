#include<stdio.h>
#include<string.h>
#define N 20
main()
{
	int i,j;
	char str1[6][N];
	for(i=1;i<=3;i++)
	gets(str1[i]);
	for(i=1;i<=3;i++)
	{
		for(j=i+1;j<=3;j++)
	
	if(strcmp(str1[i],str1[j])>0)
	{
		strcpy(str1[0],str1[i]);
		strcpy(str1[i],str1[j]);
		strcpy(str1[j],str1[0]);
	}







	for(i=1;i<=3;i++)
{
		puts(str1[i]);
		printf("\n");}
}
system("pause"); 
}
