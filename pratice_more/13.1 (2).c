#include<stdio.h>
main()
{ char ch,file[10];
  FILE * fp;
  //scanf("%s",file);
  
 	if((fp=fopen("D:\\test.txt","w"))==NULL)
	{	printf("NO!");
       // exit(0);
     }
        //ch=getchar();
       // ch=getchar();
        while(ch!='#') 
        {
                     putc(ch,fp);
                     putchar(ch);
                     ch=getchar();
                     
                     }
 fclose(fp);
 
    /*    {while((ch=fgetc(fp))!=EOF)
		putchar(ch);
		fclose(fp);
		}
	else{printf("ERROR!");}
 getchar();
*/

//system("pause");
}

