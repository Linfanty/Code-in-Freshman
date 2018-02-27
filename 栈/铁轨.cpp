#include <cstdio>
#include <stack>
using namespace std;
const int MAXN = 1000 + 10;
int n, target[MAXN];
 

int main() {

  while(scanf("%d", &n) == 1) {

    stack<int> s;

    int A = 1, B = 1;

    for(int i = 1; i <= n; i++)

      scanf("%d", &target[i]);   //输入车厢出站的顺序

    int ok = 1;

    while(B <= n) {

      if(A == target[B]){ A++; B++; }          //判断进站车厢的编号与出站车厢的编号是不是相同
 
      else if(!s.empty() && s.top() == target[B]) //如果不同，判断栈顶与出站车厢编号是否相同
	  { s.pop(); B++; } 
	  //top--;        出站（出栈）
	  //B++;  下一个车厢进入

      else if(A <= n)  s.push(A++);  //否则判断车辆是否全部进站   //进站（进栈）

      else { ok = 0; break; }   //车厢全部进站后仍不符合

    }

    printf("%s\n", ok ? "Yes" : "No");

  }

  return 0;
} 
