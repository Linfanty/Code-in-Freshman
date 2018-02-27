#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<vector>
const double PI = acos(-1.0);
template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<class T> T lcm(T a, T b) { return a / gcd(a, b) * b; }
using namespace std;

const int maxn=100010;   //�ַ����������ֵ
int next[maxn],ex[maxn]; //ex���鼴Ϊextend����
//Ԥ�������next����

void GETNEXT(char *str)
{
    int i=0,j,po,len=strlen(str);
    next[0]=len;//��ʼ��next[0]
    while(str[i]==str[i+1]&&i+1<len)//����next[1]
    i++;
    next[1]=i;
    po=1;//��ʼ��po��λ��
    for(i=2;i<len;i++)
    {
        if(next[i-po]+i<next[po]+po)//��һ�����������ֱ�ӵõ�next[i]��ֵ
        next[i]=next[i-po];
        else//�ڶ��������Ҫ����ƥ����ܵõ�next[i]��ֵ
        {
            j=next[po]+po-i;
            if(j<0)j=0;//���i>po+next[po],��Ҫ��ͷ��ʼƥ��
            while(i+j<len&&str[j]==str[j+i])//����next[i]
            j++;
            next[i]=j;
            po=i;//����po��λ��
        }
    }
}
//����extend����
void EXKMP(char *s1,char *s2)
{
    int i=0,j,po,len=strlen(s1),l2=strlen(s2);
    GETNEXT(s2);//�����Ӵ���next����
    while(s1[i]==s2[i]&&i<l2&&i<len)//����ex[0]
    i++;
    ex[0]=i;
    po=0;//��ʼ��po��λ��
    for(i=1;i<len;i++)
    {
        if(next[i-po]+i<ex[po]+po)//��һ�������ֱ�ӿ��Եõ�ex[i]��ֵ
        ex[i]=next[i-po];
        else//�ڶ��������Ҫ����ƥ����ܵõ�ex[i]��ֵ
        {
            j=ex[po]+po-i;
            if(j<0)j=0;//���i>ex[po]+po��Ҫ��ͷ��ʼƥ��
            while(i+j<len&&j<l2&&s1[j+i]==s2[j])//����ex[i]
            j++;
            ex[i]=j;
            po=i;//����po��λ��
        }
    }
}

//int main()
{
    char s1[105], s2[105];
    scanf("%s", s1);
    scanf("%s", s2);
    EXKMP(s1, s2);
    for(int i = 0; i <= 10; i++)
        cout << ex[i] << ' ' ;

    extend[i] ��ʾ T �� S[i,n-1]�������ǰ׺
    Ҫ���������extend[i] (0 <= i < n)

    S : aaaabaa
    T : aaaaa
    4 3 2 1 0 2 1 0 0 0 0
}

