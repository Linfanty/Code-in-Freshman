#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char s[60];
    cin>>s;
    double res=1.0;
    int i=0;
    int len=strlen(s);
    int er=0,wei=len;
    if(s[i]=='-')
    {
        i++;
        res*=1.5;
        wei--;
    }
    for(;i<len;i++)
    {
        if(s[i]=='2')
            er++;
    }
    if((s[len-1]-'0')%2==0)
        res*=2.0;
        
        cout<<s[len-1]<<endl<<res<<' '<<er<<' '<<wei<<' ';
        
    res*=(double)er/(double)wei;
    printf("%.2lf%%",res*100);
    
    return 0;
}
