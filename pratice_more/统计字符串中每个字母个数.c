#include"stdio.h"
main()
{
int a[100]={0},i;
char c;
while((c=getchar())!='\n')   /*��ȡ�ַ���ͳ��ÿ����ĸ���ִ���*/
for (i=65;i<=90;i++)
if(c==i||c==i+32) a[i]++ ;
for (i=65;i<=90;i++)  /*���ͳ����Ϣ*/
if (a[i]>0) printf("%c:%d\n",i,a[i]);//Դ����Ϊprintf("%c:%-3d\n",i,a[i]);
getch();  /*����������ʾ���ڲ����Զ��ر�*/
}
