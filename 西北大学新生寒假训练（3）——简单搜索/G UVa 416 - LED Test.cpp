/*
UVa 416 - LED Test
題目：用LED燈作為微波爐的倒計時工具，每個LED燈有7個顯示管，顯示途中顯示管可能壞掉；

            問給出的數據是否能表示一個倒計時。

分析：搜索，位運算。利用位狀態表示燈的顯示管的亮和暗，處理起來會方便。

            枚舉所有可能的連續數字倒敘串，並且枚舉燈壞掉的情況判斷即可；

            燈壞的狀態的后續狀態是剩下好的燈管組成的子集；

            轉移如下：（當前數字，換掉燈管）->（當前數字-1，換掉燈的後續狀態）；

說明：注意壞的顯示管不會變好，好的顯示管可能壞掉。
*/

#include <cstring>
#include <cstdlib>
#include <cstdio>
 
int  led[10], value[10], maps[10][10];
char buf[10][8];
char LED[10][8] = {
	"YYYYYYN","NYYNNNN","YYNYYNY","YYYYNNY","NYYNNYY",
	"YNYYNYY","YNYYYYY","YYYNNNN","YYYYYYY","YYYYNYY"};

int led2number(char buf[])
{
	int value = 0;
	for (int i = 6; i >= 0; -- i)
		value = value*2 + (buf[i]=='Y');
	return value;
}

int dfs(int v, int n, int s)
{
	if (n < 0) return 1;
	for (int i = 0; i <= s; ++ i)
		if ((i&s) == i && (led[v]&i) == value[n])
			if(dfs(v-1, n-1, i))
				return 1;
	return 0;
}

int main()
{
	int  n;
	for (int i = 0; i < 10; ++ i)
		led[i] = led2number(LED[i]);
	
	while (~scanf("%d",&n) && n) {
		
		for (int i = 0; i < n; ++ i) {
			scanf("%s",buf[i]);
			value[n-1-i] = led2number(buf[i]);
		}
		
		int match = 0;
		for (int i = n-1; i < 10; ++ i)
			if (dfs(i, n-1, 127))
				match = 1;
		
		if (match)
			printf("MATCH\n");
		else printf("MISMATCH\n");
	}
    return 0;
}

