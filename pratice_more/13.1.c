#include<stdio.h>
main()
{ char ch,file[10];
  FILE * out;
  FILE * in;
  if((in=fopen("D:\\in.txt","r"))==NULL)
		{printf("NO!");}
      {while((ch=getc(in))!=EOF)
      putchar(ch);
     // fclose(in);
      }
	  else{printf("ERROR!");}
  //scanf("%s",file);
  
  if((out=fopen("D:\\out.txt","w"))==NULL)
         {printf("NO!"); }
                  
  
          //     fclose(out);
 while(!feoe(in))
 puc(getc(in),out);
 fclose(in);
 fclose(out);
   

   
   
    /*    {while((ch=fgetc(fp))!=EOF)
		putchar(ch);
		fclose(fp);
		}
	else{printf("ERROR!");}
 getchar();
*/

//system("pause");
}

