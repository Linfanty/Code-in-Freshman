#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf=1e9+7;
const int N=1000005;
char s1[N],s2[N];
ll sum[N];
int next_t[N];
int len1,len2;

void get_next()//nextÊý×éÄ£°å
{
    int i=0,j=-1;
    next_t[0]=-1;
    while(i<len2)
    {
        while(j!=-1 && s2[i]!=s2[j])
            j=next_t[j];
        i++;
        j++;
        next_t[i]=j;
    }
}

void e_kmp()
{
    int i=0,j=0;
    memset(sum,0,sizeof(sum));
    while(i<len1)
    {
        if(j==-1||s1[i] == s2[j]) i++,j++;
        else j=next_t[j];
        sum[j]++;
        if(j==len2)  j=next_t[j];
    }
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s%s",s1,s2);
        len1=strlen(s1);
        len2=strlen(s2);
        reverse(s1,s1+len1);
        reverse(s2,s2+len2);
        get_next();
        e_kmp();
        ll ans=0;
        for(int i=len2;i>0;--i)
        {
            sum[next_t[i]] += sum[i];
            ans=(ans+sum[i]*i)%inf;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
