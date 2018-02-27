//PID16 / 谁拿了最多奖学 
#include<stdio.h>
struct stu
{char name[20];
int qm;
int bj;
char gb;
char xb;
int lw;
}s[101];
main()
{int i,k,n;
long sum =0,count=0,sum1=0;
FILE * in;
FILE * out;
in=fopen("d:\\in.txt","r");
out=fopen("d:\\out.txt","w"); 
fscanf(in,"%d",&n);
for(i=0;i<n;i++)
{fscanf(in,"%s %d %d %c %c %d",s[i].name,&s[i].qm,&s[i].bj,&s[i].gb,&s[i].xb,&s[i].lw);
if(s[i].qm>80&&s[i].lw>=1)
sum+=8000;
if(s[i].qm>85&&s[i].bj>80)
sum+=4000;
if(s[i].qm>90)
sum+=2000;
if(s[i].xb=='Y'&&s[i].qm>85)
sum+=1000;
if(s[i].gb=='Y'&&s[i].bj>80)
sum+=850;

count+=sum;
if(sum>sum1)
{sum1=sum;  
k=i;}
sum=0;
}




fprintf(out,"%s\n",s[k].name);
fprintf(out,"%d\n",sum1);
fprintf(out,"%d",count);
    fclose(in);
    fclose(out);
    return 0;
}
