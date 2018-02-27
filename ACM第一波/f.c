#include<stdio.h>
#include<string.h>
int main()
{
int n,i,j=0;
//int c[11],d[11],e[11];
//memset(c,0,sizeof(c)); 
//memset(d,0,sizeof(d));
//memset(e,0,sizeof(e)); 
scanf("%d",&n);
if(n<10)
printf("%d",n);
if(n<=189&&n>=10)
{
if(n%2==0)
          {
          if(n>=10&&n<30)printf("1");
           if(n>=30&&n<50)printf("2");
           if(n>=50&&n<70)printf("3");
           if(n>=70&&n<90)printf("4");
           if(n>=90&&n<110)printf("5");
           if(n>=110&&n<130)printf("6");
           if(n>=130&&n<150)printf("7");
           if(n>=150&&n<170)printf("8");
           if(n>=170&&n<190)printf("9");       
          }
else      {
           if((n/10)%2!=0&&n%10==1)printf("0");
           if((n/10)%2==0&&n%10==1)printf("5");
           if((n/10)%2!=0&&n%10==3)printf("1");
           if((n/10)%2==0&&n%10==3)printf("6");
           
           if((n/10)%2!=0&&n%10==5)printf("2");
           if((n/10)%2==0&&n%10==5)printf("7");
           if((n/10)%2!=0&&n%10==7)printf("3");
           if((n/10)%2==0&&n%10==7)printf("8");
           if((n/10)%2!=0&&n%10==9)printf("4");
           if((n/10)%2==0&&n%10==9)printf("9"); 
           }
}
if(n>189)
{
if(n%3==0&&n%10==2)printf("0");
if(n%3==0&&n%10==5)printf("1");
if(n%3==0&&n%10==8)printf("2");
if(n%3==0&&n%10==1)printf("3");
if(n%3==0&&n%10==4)printf("4");
if(n%3==0&&n%10==7)printf("5");
if(n%3==0&&n%10==0)printf("6");
if(n%3==0&&n%10==3)printf("7");
if(n%3==0&&n%10==6)printf("8");
if(n%3==0&&n%10==9)printf("9");

if(n%3==2&&n>=191&&n<221)printf("0");
if(n%3==2&&n>=221&&n<251)printf("1");
if(n%3==2&&n>=251&&n<281)printf("2");
if(n%3==2&&n>=281&&n<311)printf("3");
if(n%3==2&&n>=311&&n<341)printf("4");
if(n%3==2&&n>=341&&n<371)printf("5");
if(n%3==2&&n>=371&&n<401)printf("6");
if(n%3==2&&n>=401&&n<431)printf("7");
if(n%3==2&&n>=431&&n<461)printf("8");
if(n%3==2&&n>=461&&n<491)printf("9");

if(n%3==2&&n>=491&&n<521)printf("0");
if(n%3==2&&n>=521&&n<551)printf("1");
if(n%3==2&&n>=551&&n<581)printf("2");
if(n%3==2&&n>=581&&n<611)printf("3");
if(n%3==2&&n>=611&&n<641)printf("4");
if(n%3==2&&n>=641&&n<671)printf("5");
if(n%3==2&&n>=771&&n<801)printf("6");
if(n%3==2&&n>=801&&n<831)printf("7");
if(n%3==2&&n>=831&&n<861)printf("8");
if(n%3==2&&n>=861&&n<891)printf("9");

if(n%3==2&&n>=891&&n<921)printf("0");
if(n%3==2&&n>=921&&n<951)printf("1");
if(n%3==2&&n>=951&&n<981)printf("2");
if(n%3==2&&n>=981&&n<1011)printf("3");

if(n%3==1&&n>=190&&n<493)printf("1");
if(n%3==1&&n>=493&&n<796)printf("2");
if(n%3==1&&n>=796&&n<1011)printf("3");

}
/*for(i=0;i<n;i++)
{
if(j%2==0)
a++;
if(j%2!=0)
j++;
if(a==10)
{b++;
j++;
a=0;
}



if(b==10)
{c++;
b=0;
}
}*/
/*
if(j>0&&j%2==0)
printf("%d",b);
else
printf("%d",a);
    
   */
system("pause");    
return 0;    
}
