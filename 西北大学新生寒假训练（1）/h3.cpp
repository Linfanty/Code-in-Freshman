#include<stdio.h>
#include<string.h>
int main()
{	
	char s[1][4];
	sprintf(s[0],"%d",1234);
	char array[5];
	int count=0;
	sprintf(array,"%d",4430);
	printf("%c\n",array[0]);//array 0=4
	int isy[100];
	
			memset(isy,1,sizeof(isy));
				
			for(int j=0;j<4;j++)
			for(int num=0;num<4;num++)
			{
					printf("%c %c\n",s[0][num],array[j]);
				if(s[0][num]==array[j]&&isy[num])
				{
						count++;
						isy[num]=0;
						break;		
				}
			}	
			printf("%d",count);
}
