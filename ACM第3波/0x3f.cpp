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
#define ls (id<<1)
#define rs ((id<<1)|1)
#define mid ((l+r)>>1)
#define INF 0x3f3f3f3f
#define INFF 0x3f3f3f3f3f3f3f
#define N 200000+5
int main()
{//IO;
//sprintf(s,"%d",a);//sprintf()函数：将格式化的数据写入字符串
printf("%lld %lld",INF,INFF);
}
/*

最后，0x3f3f3f3f还能给我们带来一个意想不到的额外好处：如果我们想要将某个数组清零，
我们通常会使用 memset(a,0,sizeof(a))这样的代码来实现（方便而高效），
但是当我们想将某个数组全部赋值为无穷大时（例如解决图论问题时邻接矩阵的 初始化），
就不能使用memset函数而得自己写循环了（写这些不重要的代码真的很痛苦），
我们知道这是因为memset是按字节操作的，
它能够对数组清 零是因为0的每个字节都是0，现在好了，如果我们将无穷大设为0x3f3f3f3f，
那么奇迹就发生了，0x3f3f3f3f的每个字节都是0x3f！所 以要把一段内存全部置为无穷大，
我们只需要memset(a,0x3f,sizeof(a))。
*/

