#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#define ll long long
using namespace std;

int f[1000010];
int T,n;
char s[2000010];
char *t[120000];

void getfail(char p[]) //字符串p自我匹配
{
    int len=strlen(p);
    f[0]=f[1]=0;
    for(int i=1;i<len;i++)
    {
        int j=f[i];
        while(j&&p[i]!=p[j])
            j=f[j];
        if(p[i]==p[j])
            f[i+1]=j+1;//多匹配到了一个字符
        else
            f[i+1]=0;//该字符配不上
    }
}
int find(char* T, char*P)//p去匹配字符串T
{
    int n = strlen(T), m = strlen(P);
    getfail(P);  //得出部分匹配表
    int j = 0;  //短串的下标
    for(int i = 0; i < n; i++) //长串下标
    {
        while(j && P[j] != T[i])//突然失配了
        {
            j = f[j];  //j往回退，直到0或者上一个字符相等的位置
        }
        if(P[j] == T[i])
        {
            j++;  //匹配了一个字符，j++
        }
        if(j == m)  //短串匹配到头了
        {
            return 1;//i - m + 1;//返回成功匹配的起点字符位置
        }
    }
    return -1;
}



int main(){


	int max_len;
	scanf("%d",&T);

	while(T--){
		scanf("%d",&n);
		max_len=0;
		int tmp;
		char *qw;
		char *io=s;
		for(int i=1 ;i <= n;i++){ 
			scanf("%s",io);
			tmp=strlen(io);
			if( tmp > max_len ){
				max_len=tmp;
				qw=io;
			}
			t[i]=io;
			io+=strlen(io)+2;
		}

		int flag=1;

		for(int j=1;j<=n;j++){

			if( find(qw,t[j]) != 1 ){
				flag=0;
				break ;
			}
		}

		if(flag){
			printf("%s\n",qw);
		}
		else{
			printf("No\n");
		}

	}


	return 0;
}
