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

      scanf("%d", &target[i]);   //���복���վ��˳��

    int ok = 1;

    while(B <= n) {

      if(A == target[B]){ A++; B++; }          //�жϽ�վ����ı�����վ����ı���ǲ�����ͬ
 
      else if(!s.empty() && s.top() == target[B]) //�����ͬ���ж�ջ�����վ�������Ƿ���ͬ
	  { s.pop(); B++; } 
	  //top--;        ��վ����ջ��
	  //B++;  ��һ���������

      else if(A <= n)  s.push(A++);  //�����жϳ����Ƿ�ȫ����վ   //��վ����ջ��

      else { ok = 0; break; }   //����ȫ����վ���Բ�����

    }

    printf("%s\n", ok ? "Yes" : "No");

  }

  return 0;
} 
