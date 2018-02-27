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

void getfail(char p[]) //�ַ���p����ƥ��
{
    int len=strlen(p);
    f[0]=f[1]=0;
    for(int i=1;i<len;i++)
    {
        int j=f[i];
        while(j&&p[i]!=p[j])
            j=f[j];
        if(p[i]==p[j])
            f[i+1]=j+1;//��ƥ�䵽��һ���ַ�
        else
            f[i+1]=0;//���ַ��䲻��
    }
}
int find(char* T, char*P)//pȥƥ���ַ���T
{
    int n = strlen(T), m = strlen(P);
    getfail(P);  //�ó�����ƥ���
    int j = 0;  //�̴����±�
    for(int i = 0; i < n; i++) //�����±�
    {
        while(j && P[j] != T[i])//ͻȻʧ����
        {
            j = f[j];  //j�����ˣ�ֱ��0������һ���ַ���ȵ�λ��
        }
        if(P[j] == T[i])
        {
            j++;  //ƥ����һ���ַ���j++
        }
        if(j == m)  //�̴�ƥ�䵽ͷ��
        {
            return 1;//i - m + 1;//���سɹ�ƥ�������ַ�λ��
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