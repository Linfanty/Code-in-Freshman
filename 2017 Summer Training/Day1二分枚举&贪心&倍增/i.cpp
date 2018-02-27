#include<bits/stdc++.h>  
using namespace std;  
const int max_n =4005;  
int n,T;  
long long A[max_n],B[max_n],C[max_n],D[max_n],CD[max_n*max_n];  
void solve(){  
    for(int i=0;i<n;i++)  
        for(int j=0;j<n;j++)  
        CD[i*n+j] = C[i] + D[j];  
    sort(CD,CD+n*n);

    long long res = 0;  
    for(int i=0;i<n;i++)  
    for(int j=0;j<n;j++){  
        int cd = -(A[i]+B[j]); 
         
        res+=upper_bound(CD,CD+n*n,cd) - lower_bound(CD,CD+n*n,cd);  
    }  
    printf("%lld\n",res);  
}  
int main(){  
    scanf("%d",&T);  
    while(T--){  
        scanf("%d",&n);  
        for(int i=0;i<n;i++){  
            scanf("%lld",&A[i]);  
            scanf("%lld",&B[i]);  
            scanf("%lld",&C[i]);  
            scanf("%lld",&D[i]);  
        }  
        solve();  
        if(T) printf("\n");  
    }  
    return 0;  
}  