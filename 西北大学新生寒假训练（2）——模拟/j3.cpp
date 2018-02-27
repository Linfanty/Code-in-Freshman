//#include "stdafx.h"     
#include <stdio.h>
int main()
{
	char inp[20], outp[20];
	enum{MANY, SINGLE} state;
	while(1)
	{
		printf("input:");
		gets(inp);
		int i = 0, j = 0;
		state = MANY;
		while(inp[i]!='\0')
		{
			int cnt = 1;
			// find successive identical characters,
			//Ñ°ÕÒÁ¬ÐøµÄ×Ö·û´®
			while((inp[i+1]!='\0') && (inp[i]==inp[i+1]))
			{
				i ++;
				cnt ++;
			}
			//
			if(cnt>1) // there exist successive identical characters
			{
				if(state == SINGLE) // if the previous state is SINGLE, '1' should be added to terminate
					outp[j++] = '1';
				outp[j++] = cnt+'0'; // add "cnt"+"symbol"
				outp[j++] = inp[i++]; // i pointing to a new data
				state = MANY; // state transformed to MANY
			}
			else // no successive identical characters
			{
				if(state == MANY) // '1' should be added to start 
					outp[j++] = '1';
				if(inp[i] == '1') // if inp[i] == '1', then an extra '1' should be added 
					outp[j++] = '1';
				outp[j++] = inp[i++]; // i pointing to a new data
				state = SINGLE; // state transformed to SINGLE
			}
		}
		if(state == SINGLE)
			outp[j++] = '1';
		outp[j] = '\0';
		printf("output: %s\n", outp);
	}
}
