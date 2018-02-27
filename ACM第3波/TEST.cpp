#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <map>
#include <vector>
#include <queue>
#define rep(i,a,b) for(int (i) = (a);(i) <= (b);++ (i))
#define per(i,a,b) for(int (i) = (a);(i) >= (b);-- (i))
#define mem(a,b) memset((a),(b),sizeof((a)))
//#define IO ios_base::sync_with_stdio(0),cin.tie(0)
#define INF 0x3f3f3f3f
#define INFF 0x3f3f3f3f3f3f3f
#define N 200000+5
int main()
{//IO;
int a=12,b=45;
char s[100]="100";//不能使用类似str="asdf";的方式进行赋值。

int c=6;
sprintf(s,"%d",a);//sprintf()函数：将格式化的数据写入字符串

printf("%d %s",s,s);
}
