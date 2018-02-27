#include <iostream>
#include <cstdio>
using namespace std;

int bait , fish , remain , sum;
string execute;

void initial(){
	bait = 0;
	fish = 0;
	remain = 0;
	sum = 0;
}

void readcase(){
	while(getline(cin , execute) && execute.length() != 0){
		if(execute == "fish"){
			if(bait >= 2 && ((remain >= 7 && fish >= 2) || sum == 0)){
				sum++;
				fish = 0;
				remain = 0;
				bait -= 2;
			}else{
				fish++;
			}
			remain++;
		}
		if(execute == "bait"){
			if(bait < 6) bait++;
			remain++;
		}
		if(execute == "lunch") remain++;
	}
	printf("%d\n" , sum);
}

int main(){
	int t;
	//	freopen("in.txt","r",stdin);
   // freopen("out.txt","w",stdout);
    initial();
	while(getline(cin , execute))
		readcase();

	
	return 0;
}
