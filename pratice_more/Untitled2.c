#include<stdio.h>
main()
{ char ch;
  FILE *fp;
 	if(fp=fopen("D:\\test.txt","r"))
		{while((ch=fgetc(fp))!=EOF)
		putchar(ch);
		fclose(fp);
		}
	else{printf("ERROR!");}
 getchar();
}
