#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long int64;
const int MOD = 9973;
const int MAXN = 11;

int n;
struct Matrix{
    int mat[MAXN][MAXN];
    Matrix operator*(const Matrix& m)const{
        Matrix tmp;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                tmp.mat[i][j] = 0;
                for(int k = 0 ; k < n ; k++){
                    tmp.mat[i][j] += mat[i][k] * m.mat[k][j] % MOD;
                    tmp.mat[i][j] %= MOD;
                }
            }
        }
        return tmp;
    }
};

int Pow(Matrix &m , int k){
    Matrix ans;
    memset(ans.mat , 0 , sizeof(ans.mat));
    for(int i = 0 ; i < n ; i++)
        ans.mat[i][i] = 1;
    while(k){
        if(k&1)
            ans = ans*m;
        k >>= 1;
        m = m*m;
    }
    int sum = 0;
    for(int i = 0 ; i < n ; i++)
        sum += ans.mat[i][i];
    return sum%MOD;
}

int main(){
    int cas , k;
    Matrix m;
    scanf("%d" , &cas);
    while(cas--){
         scanf("%d%d" , &n , &k);
         for(int i = 0 ; i < n ; i++){
             for(int j = 0 ; j < n ; j++){
                 scanf("%d" , &m.mat[i][j]);
                 m.mat[i][j] %= MOD;
             }
         }
         printf("%d\n" , Pow(m , k));
    }
    return 0;
}
