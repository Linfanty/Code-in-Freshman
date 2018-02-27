//PID40 / Web‰Ø¿¿
#include<stdio.h>
#include<string.h>
main()
{int i=0,t1,t2,t3,t4,t5,point=0;
char ch[500][500];
char ch1[100];
strcpy(ch[0],"http://www.acm.org/");
FILE * in;
FILE * out;
in=fopen("d:\\in.txt","r");
out=fopen("d:\\out.txt","w"); 
while(strcmp(ch1,"QUIT"))
{
fscanf(in,"%s",ch1);
t1=strcmp(ch1,"VISIT");
t2=strcmp(ch1,"BACK");
t3=strcmp(ch1,"FORWARD");
if(t1==0)
{++i;
fscanf(in," %s",ch[i]);
point=i;
fprintf(out,"%s\n",ch[point]);
}
if(t2==0&&i>=1)
{--i;
fprintf(out,"%s\n",ch[i]);
continue;}
if(t2==0&&i==0)
 fprintf(out,"Ignored\n");

if(t3==0&&i<point)
{++i;
fprintf(out,"%s\n",ch[i]);
continue;}

if(t3==0&&i>=point)
 fprintf(out,"Ignored\n");

}
//fprintf(out,"\n\n\n\n\n\n\n\n%s",ch[0]);
    fclose(in);
    fclose(out);
    return 0;
}

/*
int main()
{
char command[100];
char URL[500][200];
int tot=1;
int point=1;
strcpy(URL[1],"http://www.acm.org/");
do{
scanf("%s",command);
if (strcmp(command,"VISIT")==0)
{
scanf("%s",URL[++point]);
tot=point;
printf("%s\n",URL[tot]);
}
if (strcmp(command,"BACK")==0)
if (point > 1)
printf("%s\n",URL[--point]);
else printf("Ignored\n");
if (strcmp(command,"FORWARD") == 0)
if (point < tot)
printf("%s\n",URL[++point]);
else printf("Ignored\n");
}while (strcmp(command,"QUIT"));
return 0;
}
*/
