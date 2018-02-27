#include<cstdio>
#include<cstring>
#include<queue>
#include<vector>
#include<algorithm>
#include<iostream>
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
using namespace std;
typedef long long LL;

char s[15][15];
int n,a[105],b[10],top,L[15];
int mp[26],ans;
bool first[26];
LL sum[26],mul[15];

void init(){
    top = ans = 0;
    mul[0] = 1;
    for(int i = 1;i <= 10;i++) mul[i] = mul[i-1]*10;//分别为1 10 100 1000 10000multiple 数乘
}

void dfs(int i){
    if(i == top){
        LL res = 0;
        for(int ii = 0;ii < top;ii++){
            res += mp[a[ii]]*sum[a[ii]];
        }
        if(res==0) ans++;
        return;
    }
    if(!first[a[i]]&&b[0]==0){
        b[0] = 1;
        mp[a[i]] = 0;
        dfs(i+1);
        b[0] = 0;
    }
    for(int j = 1;j < 10;j++){
        if(b[j]) continue;
        b[j] = 1;
        mp[a[i]] = j;
        dfs(i+1);
        b[j] = 0;
    }
}

int main(){
    int i,j;
    scanf("%d",&n);
    init();
    for(i = 1;i <= n;i++){
        scanf("%s",s[i]);
        L[i] = strlen(s[i]);
        for(j = 0;j < L[i];j++){
            if(j==0&&L[i]!=1) first[s[i][0]-'A'] = true;//标记首字母为true 不能为0
            sum[s[i][j]-'A'] += (i!=n?1:-1)*mul[L[i]-j-1];
            cout << s[i][j]-'A' << ' ' << sum[s[i][j]-'A'] << endl;
            a[top++] = s[i][j]-'A';
        }
    }
    sort(a,a+top);
    top = unique(a,a+top)-a;

//printf("%d\n",top);
    dfs(0);
    printf("%d\n",ans);

    return 0;
}
