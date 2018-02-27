//高精度加法 
#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<cstring>
using namespace std;
char sa[1000],sb[10000];
int a[1000],b[1000],c[1000];
int la,lb,lc;
int main()
{
    scanf("%s %s",sa,sb);
   // for(int i=0;i<5;i++)
   //printf("%c %c\n",sa[i],sb[i]);
    
    la=strlen(sa);
    lb=strlen(sb);
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    
    for (int i=0;i<la;i++)
    a[la-i-1]=sa[i]-'0';  //将操作数放入a数组 　 
	 
    for (int i=0;i<lb;i++)
    b[lb-i-1]=sb[i]-'0';  //将操作数放入b数组   
    
    lc=la>lb?la:lb;   ////比如说s ="123"，那么s依次为3、2、1  
    
    // 	for(int i=0;i<5;i++)
	//	printf("%d %d\n",a[i],b[i]);
    // if (la>lb) lc=la;else lc=lb;
    
    memset(c,0,sizeof(c));
    for (int i=0;i<lc;i++)
    {
        c[i]=a[i]+b[i]+c[i];
        if (c[i]>=10) {c[i+1]=1;c[i]-=10;}
    }
    if (c[lc]>0) lc++;
    for (int i=lc-1;i>=0;i--)
    printf("%d",c[i]);
    return 0;
}
