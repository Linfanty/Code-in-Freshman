#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
typedef long long ll;
const int maxn = 105;
using namespace std;
/*����������ǽ�������
��� ai > bj + 1����ôai ����Ŀ϶�Ҳ��bj 
��Բ��ɹ������   ai �� bj ��Գɹ���
ai+1 �� bj  Ҳ����Գɹ���
��ô��ʱ�����ǰ�bj  �� ai ����һ��
��ai+1�л���� bj+1 ��ԡ�
*/
int an[maxn],bn[maxn];
 int n,m;
 int main()
 {
     while (scanf("%d",&n)!=EOF)
     {
         for (int i=0 ;i<n ;i++) scanf("%d",&an[i]);
         scanf("%d",&m);
         for (int i=0 ;i<m ;i++) scanf("%d",&bn[i]);
         int cnt=0;
         sort(an,an+n);
         sort(bn,bn+m);
         int j=0;
         for (int i=0 ;i<n ;i++)
         {
             while (j<m && an[i]-bn[j]>1) j++;
             if (j==m) break;
             if (abs(an[i]-bn[j])==1 || an[i]==bn[j]) {cnt++;j++; }
         }
         printf("%d\n",cnt);
     }
     return 0;
 }
