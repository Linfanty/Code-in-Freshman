#include<stdio.h>

main()
{
      int i  = 1;
      printf("%d\n",i);
      char ch;
      FILE *fp;
      fp=fopen("I:\test.txt","r");
      ch = getchar();
      printf("%s",ch);
}
