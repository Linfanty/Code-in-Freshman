#include<bits/stdc++.h>
#include <algorithm>
#include <vector>
#define inf 0x3f3f3f3f
const int  maxn = 2e5 + 5;
#define fin freopen("out.txt","r",stdin);
#define fout freopen("outtest.txt","w",stdout);
#define mem(a) memset(a,true,sizeof(a))
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define mod 1000000007
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long int ll;

bool isprime[maxn];
int prime[maxn], cnt = 0;

void prim()
{
    mem(isprime);
    for(int i = 2; i <= maxn; i++)
        if( isprime )
        {
            prime[cnt++] = i;
            for(int j = i*2; j <maxn; j += i)
                isprime[i] = 0;
        }
}

void foo()
{
    mem(isprime);
    for(int i = 2; i < maxn; i++)
    {
        if( isprime[i])
            prime[cnt++] = i;//cnt����С��n�������ĸ���
        for(int j = 0; j < cnt; j++) //j < cnt
        {
             if( i*prime[j] >= maxn ) break;
             isprime[ i*prime[j] ] = false;//�ҵ��������ı���������
             if( i%prime[j] == 0 ) break;//�ؼ�
             //prime���� �е������ǵ�����,�� i ������ prime[j]����ô i*prime[j+1]
             //��������϶��� prime[j] ����ĳ����ɸ��
             //prime[j]�ض���prime[j]*i����С����

        }
    }
}

/*����ɸO(n)ʱ�临�Ӷ���ɸ��maxn��ŷ������ֵ*/
int m[maxn],phi[maxn],p[maxn],pt;//m[i]��i����С��������p��������pt����������

//��phiŷ������
void getphi()
{
    for(int i=1;i<N;i++)
        phi[i]=i;

    for(int i=2;i<N;i++)
        if(phi[i]==i)
            for(int j=i;j<N;j+=i)
                phi[j]=phi[j]-phi[j]/i;
}

int make()
{
    phi[1]=1;
    int N=maxn;
    int k;
    for(int i=2;i<N;i++)
    {
        if(!m[i])//i������
            p[pt++]=m[i]=i,phi[i]=i-1;
        for(int j=0;j<pt&&(k=p[j]*i)<N;j++)
        {
            m[k]=p[j];
            if(m[i]==p[j])//Ϊ�˱�֤�Ժ����������ɸ��Ҫbreak
            {
                phi[k]=phi[i]*p[j];
/*�����phi[k]��phi[i]����ġ�(p[i]-1)/p[i]��һ����m[i]==p[j]��ֻ��һ��p[j]���Ϳ��Ա�֤��(p[i]-1)/p[i]ǰ��Ҳһ����*/
                break;
            }
            else
                phi[k]=phi[i]*(p[j]-1);//���Ժ������ʣ�f(i*k)=f(i)*f(k)
        }
    }
}

int main()
{
    foo();
    make();
    rep(i,1,50)
    cout << phi[i] << ' ';

}
