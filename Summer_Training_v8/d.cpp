#include <stdio.h>
#include <memory.h>
int min(int a,int b){
    if (a > b) return b;
    return a;
}
int max(int a,int b){
    if (a > b) return a;
    return b;
}
//¡¡dp[i][j] = min{max{dp[i-w][j],dp[w-1][j-1]}+1, dp[i][j]};
int main(){
    int n,k;
    while (scanf("%d %d",&n,&k) != EOF){
        int dp[1005][20];
        memset(dp,0x3f,sizeof(dp));
        if (n > 10) n = 10;
        int i,j,w;
        for (i=0;i<=n;i++){
            dp[0][i] = 0;
            dp[1][i] = 1;
        }
        for (i=0;i<=k;i++){
            dp[i][1] = i;
        }
        for (i=2;i<=k;i++){
            for (j=2;j<=n;j++){
                for (w=1;w<=i;w++){
                    dp[i][j] = min(dp[i][j],max(dp[w-1][j-1],dp[i-w][j]) + 1);
                }
            }
        }
        printf("%d\n",dp[k][n]);
    }

    return 0;
}
