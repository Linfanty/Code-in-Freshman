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
//sprintf(s,"%d",a);//sprintf()����������ʽ��������д���ַ���
printf("%lld %lld",INF,INFF);
}
/*

���0x3f3f3f3f���ܸ����Ǵ���һ�����벻���Ķ���ô������������Ҫ��ĳ���������㣬
����ͨ����ʹ�� memset(a,0,sizeof(a))�����Ĵ�����ʵ�֣��������Ч����
���ǵ������뽫ĳ������ȫ����ֵΪ�����ʱ��������ͼ������ʱ�ڽӾ���� ��ʼ������
�Ͳ���ʹ��memset���������Լ�дѭ���ˣ�д��Щ����Ҫ�Ĵ�����ĺ�ʹ�ࣩ��
����֪��������Ϊmemset�ǰ��ֽڲ����ģ�
���ܹ��������� ������Ϊ0��ÿ���ֽڶ���0�����ں��ˣ�������ǽ��������Ϊ0x3f3f3f3f��
��ô�漣�ͷ����ˣ�0x3f3f3f3f��ÿ���ֽڶ���0x3f���� ��Ҫ��һ���ڴ�ȫ����Ϊ�����
����ֻ��Ҫmemset(a,0x3f,sizeof(a))��
*/

