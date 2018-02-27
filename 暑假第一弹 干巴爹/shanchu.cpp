#include<bits/stdc++.h>
#include <algorithm>
#include<stdio.h>
#include<iostream>
#include<cmath>
#include<stdlib.h>
#include<cstring>
using namespace std;

int main(){
    //freopen("out.txt","w",stdout);
	int N;
	string a;
	int b[100],c[100],count[100];
	int times = 1;
	scanf("%d",&N);

		while(times <= N){
			cin >> a;
			//memset(count,0,55);
			int len = a.size();
			if(a.at(0) == 'R') b[0] = 1;
			else if(a.at(0) == 'F') b[0] = -1;
			else b[0] = 0;
			int high = 1,low = 1;
			c[0] = 1;
			for(int i = 1; i < len; i++){
			    if(a.at(i) == 'R') b[i] = 1;
				else if(a.at(i) == 'F') b[i] = -1;
				else b[i] = 0;

				if(b[i-1] == 1 && (b[i] == 0 || b[i] == 1)) c[i] = c[i-1] + 1;
				else if((b[i-1] == -1 && b[i] == -1) || (b[i-1] == 0 && b[i] == -1)) c[i] = c[i-1] - 1;
				else c[i] = c[i-1];

				high = max(c[i],high);
				low = min(c[i],low);
			}

		    for(int i = 0; i < len; i++) {
		    	c[i] = c[i] + 1 - low;
		    	count[c[i]]++;
			}

			printf("Case #%d:\n",times);
			int level = high -low + 1,gg;
			while(level){
				printf("| ");
				gg = 0;
				for(int p = 0; p < len; p++){
					if(c[p] == level){
						if(b[p] == 1) printf("/");
					    else if(b[p] == -1) printf("\\");
					    else printf("_");
					    if((++gg) == count[level]) {
					    	break;
						}
				    }
				    else printf(" ");
				}
			   printf("\n");
			   level--;
			}

			printf("+");
			for(int w = 0; w <= len + 1; w++){
				printf("-");
			}
			if( times != N)
			printf("\n\n");
			times++;
		}
return 0;
}
