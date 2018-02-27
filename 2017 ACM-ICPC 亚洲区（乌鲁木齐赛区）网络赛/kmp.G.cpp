#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#define MAX_LEN 150000
using namespace std;


int Next[MAX_LEN];
int c[MAX_LEN];
int flag[MAX_LEN];
string s1, s2;

int min(int a, int b){
    if(a < b) return a;
    return b;
}

int max(int a, int b){
    if(a > b) return a;
    return b;
}

int lowbit(int x) {
    return x & (-x);
}

void add(int pos, int num) {
    while(pos <= MAX_LEN) {
        c[pos] += num;
        pos += lowbit(pos);
    }
}

int query(int pos) {
    int ans = 0;
    while(pos > 0) {
        ans += c[pos];
        pos -= lowbit(pos);
    }
    return ans;
}


void get_next(string str){
    int len = str.length();
    int j = 0;

    Next[0] = Next[1] = 0;

    for(int i = 1; i < len; ++i){
        while(j > 0 && str[i] != str[j]) j = Next[j];
        if(str[i] == str[j]) ++j;
        Next[i + 1] = j;
    }
}
void KMP(string pattern_str, string target_str, int pianyi){ // pianyi Æ«ÒÆÁ¿
    int res = 0;
    int j = 0;
    int pattern_len = pattern_str.length();
    int target_len = target_str.length();
    get_next(pattern_str);
    for(int i = 0; i < pattern_len; ++i){
        while(j > 0 && pattern_str[i] != target_str[j])
            j = Next[j];
        if(pattern_str[i] == target_str[j]) ++j;
        if(j == target_len){
            flag[i + 1 + pianyi] = true;
            add(i + 1 + pianyi, 1);
            j = Next[j] + 1;
        }
    }
    return;
}

void update(int pos, char c){
    int len = s2.length() + 1;
    int left = max(pos - len, 0);
    int right = min(pos + len, s1.length() - 1);
    for(int i = left; i <= right; ++i){
        if(flag[i + 1]){
            flag[i + 1] = false;
            add(i + 1, -1);
        }
    }
    s1[pos] = c;
    string temp = s1.substr(left, right - left + 1);
    int pianyi = left;
    KMP(temp, s2, pianyi);
}
int main(int argc, char const *argv[]){
    int kase, num;
    char op;
    scanf("%d", &kase);
    while(kase--){
        memset(c, 0, sizeof c);
        memset(flag, false, sizeof flag);
       scanf("%d", &num);
        cin >> s1 >> s2;
      KMP(s1, s2, 0);
      while(num--){
        getchar();
        scanf("%c", &op);
        if(op == 'Q'){
            int a, b;
            scanf("%d %d", &a, &b);
            int len = s2.length();
            if(b - a + 1 < len) printf("0\n");
            else{
                printf("%d\n", query(b) - query(a + len - 2));
            }
        }
        if(op == 'C'){
            int a;
            char b;
            scanf("%d %c", &a, &b);
            update(a - 1, b);
        }
      }
        printf("\n");
    }

    return 0;
}
