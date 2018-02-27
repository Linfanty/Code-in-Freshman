#include<stdio.h>
#include<string.h>
int main()
{
char c1[100],c2;
int i,n=0;
memset(c1,0,sizeof(c1));
//memset(c1,0,sizeof(c1));


scanf("%s ",c1);

while((c2=getchar())!='\n')
{c1[n]=c2;
n++;}

/*for(i=0;i<n;i++)
printf("%c",c1[i]);
*/
printf("%s",c1);

system("pause");
return 0;
}
