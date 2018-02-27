#include <cstdlib>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
unsigned long long answer;

int dfs(unsigned long long prenum,unsigned long long lev,int n)
{
   if(prenum>=lev)
   return 0;
    
    if(lev%n==0)
    {answer=lev;return 1;}
    
    if(dfs(lev,lev*10,n))
    {return 1;}
    
    return dfs(lev,lev*10+1,n);
    
}
int main(int argc, char *argv[])
{
    int n;
    int i,j,k;
 
    while(scanf("%d",&n)!=EOF)
    {
      if(!n)
  	  break;
  	if(dfs(0,1,n))
    	cout<<answer<<endl;
    }
    return 0;
}
