#include<bits/stdc++.h>
using namespace std;
int f[20][20];
vector<int>p[20];
vector<int>q[20];
int main(){
     int t;
     scanf("%d", &t);
     while(t--){
          int n;
          scanf("%d", &n);
          memset(f, 0, sizeof(f));
          for(int i = 1; i < n; i++){
               for(int j = i + 1; j <= n; j++){
                    int x;
                    scanf("%d", &x);
                    if(n <= 15){
                         if(x)
                              f[i][j] = 1;
                    }
               }
          }
          if(n >= 15)
               printf("Bad Team!\n");
          else{
               for(int i = 1; i <= n; i++){
                    p[i].clear();
                    q[i].clear();
               }
               for(int i = 1; i <= n; i++){
                    for(int j = i + 1; j <= n; j++){
                         if(f[i][j])
                              p[i].push_back(j);
                         else
                              q[i].push_back(j);
                    }
               }
               bool flag = false;
               for(int i = 1; i <= n; i++){
                    int len1 = p[i].size();
                    int len2 = q[i].size();
                    if(flag)
                         break;
                    for(int j = 0; j < len1; j++){
                         if(flag)
                              break;
                         for(int k = j + 1; k < len1; k++){
                              if(f[p[i][j]][p[i][k]]){
                                   flag = true;
                                   break;
                              }
                         }
                    }
                    for(int j = 0; j < len2; j++){
                         if(flag)
                              break;
                         for(int k = j + 1; k < len2; k++){
                              if(!f[q[i][j]][q[i][k]]){
                                   flag = true;
                                   break;
                              }
                         }
                    }
               }
               if(flag)
                    printf("Bad Team!\n");
               else
                    printf("Great Team!\n");
          }
     }
     return 0;
}
