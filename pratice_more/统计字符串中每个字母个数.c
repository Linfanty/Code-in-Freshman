#include"stdio.h"
main()
{
int a[100]={0},i;
char c;
while((c=getchar())!='\n')   /*获取字符并统计每个字母出现次数*/
for (i=65;i<=90;i++)
if(c==i||c==i+32) a[i]++ ;
for (i=65;i<=90;i++)  /*输出统计信息*/
if (a[i]>0) printf("%c:%d\n",i,a[i]);//源程序为printf("%c:%-3d\n",i,a[i]);
getch();  /*保持命令提示窗口不被自动关闭*/
}
