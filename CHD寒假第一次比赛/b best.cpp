#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
#define INF 0x7fffffff

int a[105], b[105];       //boy��girl
/*����˼·��̰�ġ�
���������鶼��С��������
�������õ�ǰ��С��ȥ���Է��ȣ�
��������������˫���±궼++��
���Լ�̫�ͣ����Լ��±�++����
��Է��±�++��
*/
int main()
{
    #ifdef sxk
        freopen("in.txt","r",stdin);
    #endif
    int n, m;
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0; i<n; i++)
            scanf("%d", &a[i]);
        scanf("%d",&m);
        for(int i=0; i<m; i++)
            scanf("%d", &b[i]);
        sort(a, a+n);              //����
        sort(b, b+m);
        int ans = 0;
        for(int i=0, j=0; i<n && j<m;){
            if(abs(a[i]-b[j])<=1) {     //��������
                ans++;
                i++;
                j++;
            }
            else if(a[i] > b[j]){        //�Է�̫��
                j++;
            }
            else  i++;                   //�Լ�̫��
        }
        printf("%d\n", ans);
    }
    return 0;
}
