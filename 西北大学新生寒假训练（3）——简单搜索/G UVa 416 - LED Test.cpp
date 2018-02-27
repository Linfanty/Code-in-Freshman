/*
UVa 416 - LED Test
�}Ŀ����LED������΢���t�ĵ�Ӌ�r���ߣ�ÿ��LED����7���@ʾ�ܣ��@ʾ;���@ʾ�ܿ��܉ĵ���

            ���o���Ĕ����Ƿ��ܱ�ʾһ����Ӌ�r��

������������λ�\�㡣����λ��B��ʾ�����@ʾ�ܵ����Ͱ���̎����������㡣

            ö�e���п��ܵ��B�m���ֵ��������K��ö�e��ĵ�����r�Д༴�ɣ�

            ��ĵĠ�B�ĺ��m��B��ʣ�ºõğ��ܽM�ɵ��Ӽ���

            �D�����£�����ǰ���֣��Q�����ܣ�->����ǰ����-1���Q���������m��B����

�f����ע��ĵ��@ʾ�ܲ���׃�ã��õ��@ʾ�ܿ��܉ĵ���
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

