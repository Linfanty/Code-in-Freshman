#include<stdio.h>

main()
{
      char ch;
      FILE *fp;
      if(fp=fopen("D:\\test.txt","r"))
      {
           for(;;)
           {
                 ch=fgetc(fp);
                 if(ch == EOF)
                      break; 
                 putchar(ch);
           }                           
           // printf("open file:\n");
           // while((ch=fgetc(fp))!=EOF)
           //       putchar(ch);      
            fclose(fp);                
      }
      else
      {printf("ERROR!");}
      
      getchar();
}
