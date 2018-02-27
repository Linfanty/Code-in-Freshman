#include<stdio.h>
#include<string.h>
int main()
{
char c1[100],c2;
int i,n;
memset(c1,0,sizeof(c1));
//memset(c1,0,sizeof(c1));


scanf("%s ",c1);
n=strlen(c1);
 
//c2=getchar();
while((c2=getchar())!='\n')//'\0' ' \n' EOF!='\0'
{c1[n]=c2;
n++;}

printf("%s",c1);

system("pause");
return 0;
}
/*for(i=0;i<n;i++)
printf("%c",c1[i]);
*/
