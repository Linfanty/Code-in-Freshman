    #include <stdio.h>
    #include <iostream>
    #include <string.h>
    using namespace std ;
    #define M 1001
    int p[M], pNum, phi[M];
    bool f[M];
    //求M以内的素数以及欧拉函数（线性）
    void Prime()
    {
        int i, j;
        for(i = 2; i < M; i++) {
            if(!f[i]) { p[pNum++] = i; phi[i] = i-1;}
            for(j = 0; j < pNum && p[j] * i < M; j++ ) {
                f[p[j]*i] = 1;
                if(i % p[j] == 0){
                    phi[i*p[j]] = phi[i] * p[j];
                    break;
                }
                else phi[i*p[j]] = phi[i] *(p[j] - 1);
            }
        }
    }
    int main()
    {
        int T ;
        Prime() ;
        phi[1] = 1;
        cin >> T ;
        for(int cas = 1 ; cas <= T ; cas ++)
        {
            long long ans = 0 ;
            int n ;
            cin >> n ;
            for(int i = 1 ; i <= n  ; i ++) ans += phi[i] ;
            cout << cas <<' ' << n <<' '<< ans*2 +1 <<endl ;
        }
        return 0 ;
    }
