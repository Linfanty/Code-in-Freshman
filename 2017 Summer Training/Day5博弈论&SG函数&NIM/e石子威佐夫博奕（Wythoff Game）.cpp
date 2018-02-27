#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
int a,b;

int main(){
    while(~scanf("%d%d",&a,&b)){
        if(a<b){
            a^=b;
            b^=a;
            a^=b;
        }/// a b swap
        ///cout << a << ' ' << b  << ' ' << a - b  << endl;
        int k=a-b;
        a=(int)(k*(1+sqrt(5))/2.0);
        if(a==b)
            printf("0\n");
        else
            printf("1\n");
    }
    return 0;
}
