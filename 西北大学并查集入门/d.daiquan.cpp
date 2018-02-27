    #include<cstdio>  
    #include<cstring>  
    #include<algorithm>  
    #include<vector>  
    #include<string>  
    #include<iostream>  
    #include<queue>  
    #include<cmath>  
    #include<map>  
    #include<stack>  
    #include<bitset>  
    using namespace std;  
    #define REPF( i , a , b ) for ( int i = a ; i <= b ; ++ i )  
    #define REP( i , n ) for ( int i = 0 ; i < n ; ++ i )  
    #define CLEAR( a , x ) memset ( a , x , sizeof a )  
    typedef long long LL;  
    typedef pair<int,int>pil;  
    const int mod = 1000000007;  
    const int maxn=200000+10;  
    int pre[maxn],sum[maxn];//sum[i]��ʾ�����ڵ���ܺ�  
    int n,m;  
    int find(int x)  
    {  
         if(x!=pre[x])  
         {  
             int f=pre[x];  
             pre[x]=find(pre[x]);  
             sum[x]+=sum[f];//��x��x�����и��ڵ�ľ���.  
         }  
         return pre[x];  
    }  
    int main()  
    {  
        int l,r,s;  
        while(~scanf("%d%d",&n,&m))  
        {  
            REPF(i,0,n)  pre[i]=i;  
            CLEAR(sum,0);  
            int ans=0;  
            while(m--)  
            {  
                scanf("%d%d%d",&l,&r,&s);  
                l--;  
                
                int ra=find(l),rb=find(r);  
                cout << ra << ' ' << rb << endl;
                if(ra!=rb)  
                {  
                   pre[ra]=rb;//��rb��Ϊ���ڵ�  
                   sum[ra]=sum[r]-sum[l]+s;//sum[r]:r->rb;s:l->r;sum[l]:l->ra��Ҫ��ra->rb������  
                }  
                else if(ra==rb)  
                {  
                    if(sum[l]-sum[r]!=s)  ans++;  
                }  
            }  
            printf("%d\n",ans);  
        }  
        return 0;  
    }  
