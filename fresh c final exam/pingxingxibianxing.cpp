#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,line,row;
    char n;
    printf("line and row plz\n");
    scanf("%d%d",&line,&row);
    printf("fuhao plz");
    scanf("%c",&n);
scanf("%c",&n);
    for(i=1;i<line+1;i++)
    {
        for(j=1;j<line-i+1;j++) printf(" ");
        for(k=1;k<row+1;k++) printf("%c",n);
        printf("\n");
    }
   // char [100]="\ÍõÌìÑô";
   // printf("%d %s",strlen(s),s);
    return 0;
}
