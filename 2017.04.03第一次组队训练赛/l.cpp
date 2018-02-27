#include<bits/stdc++.h>
#define  IO ios_base::sync_with_stadio(0);cin.tie(0);
using namespace std;
int a[55][55];
/*
只有三种矩形，那么无论怎么拼，
其中的最长边才有可能是最后正方形的边长的，
基于这一点，可以分类讨论一下。
*/
int main()
{
    int a1, b1, a2, b2, a3, b3;
    while(cin >> a1 >> b1 >> a2 >> b2 >> a3 >> b3){
        int a = max(a1, b1);
        int b = max(a2, b2);
        int c = max(a3, b3);
        int d = a, flag = 1;
        if(b > d){d = b; flag = 2;}
        if(c > d){d = c; flag = 3;}
        if(flag == 1){
            int e = a2 + a3;
            int f = a2 + b3;
            int g = b2 + a3;
            int h = b2 + b3;
            if(e == d){
                if(b2 == b3 && (b2 + a1 == d || b2 + b1 == d)){ cout << "YES" << endl; continue;}
            }
            if(f == d){
                if(b2 == a3 && (b2 + a1 == d || b2 + b1 == d)) { cout << "YES" << endl; continue;}
            }
             if(g == d){
                if(a2 == b3 && (a2 + a1 == d || a2 + b1 == d)) { cout << "YES" << endl; continue;}
            }
             if(h == d){
                if(a2 == a3 && (a2 + a1 == d || a2 + b1 == d)) { cout << "YES" << endl; continue;}
            }
        }
        else if(flag == 2){
            int e = a1 + a3;
            int f = a1 + b3;
            int g = b1 + a3;
            int h = b1 + b3;
            if(e == d){
                if(b1 == b3 && (b1 + a2 == d || b1 + b2 == d)){ cout << "YES" << endl; continue;}
            }
            if(f == d){
                if(b1 == a3 && (b1 + a2 == d || b1 + b2 == d)) { cout << "YES" << endl; continue;}
            }
             if(g == d){
                if(a1 == b3 && (a1 + a2 == d || a1 + b2 == d)) { cout << "YES" << endl; continue;}
            }
             if(h == d){
                if(a1 == a3 && (a1 + a2 == d || a1 + b2 == d)) { cout << "YES" << endl; continue;}
            }
        }
        else if(flag == 3){
            int e = a2 + a1;
            int f = a2 + b1;
            int g = b2 + a1;
            int h = b2 + b1;
            if(e == d){
                if(b2 == b1 && (b1 + a3 == d || b1 + b3 == d)){ cout << "YES" << endl; continue;}
            }
            if(f == d){
                if(b2 == a1 && (b2 + a3 == d || b2 + b3 == d)) { cout << "YES" << endl; continue;}
            }
             if(g == d){
                if(a2 == b1 && (b1 + a3 == d || b1 + b3 == d)) { cout << "YES" << endl; continue;}
            }
             if(h == d){
                if(a2 == a1 && (a1 + a3 == d || a1 + b3 == d)) { cout << "YES" << endl; continue;}
            }
        }
        cout << "NO" << endl;
    }
}
