#include<cstdio>
#include<cmath>
#include<algorithm>
#include<sstream> 
#include<iostream>
#include<string.h>
typedef long long ll;
using namespace std;

struct node
{
	char name[15];
	int time;
	int ac_num;
}p[1000];

int cmp(node x,node y)
{
	return x.ac_num > y.ac_num ;
	if(x.ac_num == y.ac_num ) return x.time < y.time;
	else return strcmp(x.name , y.name )<0;
}
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n,m;
	scanf("%d %d%",&n,&m);
	
	int i,j=0;
	
	while(scanf("%s",p[j].name )!=EOF)
	{
		char mid[15];
		p[j].ac_num = p[j].time = 0 ;
		for(int i=0;i<n;i++)
		{
			
			scanf("%s",mid);
			
			if( mid[0]=='0' || mid[0] == '-')
			continue;  
			
			p[j].ac_num ++;
			
			int wa=0,res=0;
			bool flag=false;
			for(int k=0;k<strlen(mid);k++)
			{
				if(mid[k]=='(')
				{
					p[j].time += res;
					flag = true;
					k++;
					while( mid[k] !=')')
					{
						wa = wa*10 + mid[k] -'0' ;	
						k++;
					} 	
				}
				
				if(mid[k]==')')	
				{
					p[j].time +=(wa*m);
					break;	
				}
				
				if(!flag)
					res = res*10 + mid[k]-'0';	
			}
			
			if(!flag)
				p[j].time += res;
		}	
		j++;		
	}	
	sort(p,p+j,cmp);
	for(int i=0;i<j;i++)
		printf("%-10s%3d%5d\n",p[i].name ,p[i].ac_num, p[i].time  );
	return 0;
}
