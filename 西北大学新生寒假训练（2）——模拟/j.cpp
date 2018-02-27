#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<stdlib.h>
typedef long long ll;
using namespace std;

int main()
{
	char s[10001];
	while(gets(s))
	{
		
		for(int i=0;i<strlen(s);i++)
		{
			int j;
			if(s[i] == '1'&&strlen(s)==1 )
			printf("1111");
			else if(strlen(s)==1)
			{
				printf("1%c1",s[i]);
			}
			else if(s[i] == s[i+1])
			{
				j = i+1 ;
				while(s[i] == s[j] )
				{
					j++;
					if(j-i==9)
					break;
				}
				//if(s[i]!=1)
				printf("%d%c",j-i,s[i]);
				//else printf("%d1",j-i);
				i = j-1  ;
				continue;
			}
			else if(s[i] !=  s[i+1]  )
			{
				j= i ;
				while(s[j] != s[j+1] )
				{
					j++;
				}
				--j ;
			
				if(s[i]!='1' && s[j]!='1')
				{
				
					printf("1");
					for(int k = i; k<=j ;k++ )
					printf("%c",s[k]);
					printf("1");
					i = j  ; 
					continue;
				}
				else if(s[i]=='1' && s[j]== '1')
				{
					printf("11");
					
					for(int k = i; k<=j ;k++ )
					printf("%c",s[k]);
					printf("11");
					i = j  ; 
					continue;
				}
				else if(s[i]=='1')
				{
					printf("11");
					
					for(int k = i; k<=j ;k++ )
					printf("%c",s[k]);
					printf("1");
					i = j  ; 
					continue;
				}
				else if(s[j]=='1')
				{
					printf("1");
					for(int k = i; k<j ;k++ )
					printf("%c",s[k]);
					printf("1");
					printf("11");
					i = j  ;
					continue;
				}
			}
			
		}
		printf("\n");
		memset(s,0,sizeof(s));
	}
return 	0;
}
