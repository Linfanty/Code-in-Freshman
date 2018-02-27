#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
#define LL __int64
const int maxn = 50000 + 5;
const int sigma_size = 26;
struct Trie {
    int ch[maxn][sigma_size];
    bool isEnd[maxn];
    int size;
    void init() {
        size = 1;
        memset(ch[0] , 0 , sizeof(ch[0]));
        memset(isEnd , 0 , sizeof(isEnd));
    }
    int index(char c) {    return c - 'a';    }
    void insert(char *s) {
        int i , rt;
        for(i = rt = 0 ; s[i] != '\0' ; i++) {
            int c = index(s[i]);
            if(!ch[rt][c]) {
                memset(ch[size] , 0 , sizeof(ch[size]));
                ch[rt][c] = size++;
            }
            rt = ch[rt][c];
        }
        isEnd[rt] = 1;
    }
    bool find(char *s) {
        int i , rt;
        for(i = rt = 0 ; s[i] != '\0' ; i++) {
            int c = index(s[i]);
            if(!ch[rt][c])    
                return false;
            rt = ch[rt][c];
        }
        return isEnd[rt];
    }
} trie;
char s[maxn][50];
char str[50];
int main() 
{
    int n;
    trie.init();
    for(n = 0 ; scanf("%s" , s[n]) != EOF ; n++) {
        trie.insert(s[n]);
    }
    for(int i = 0 ; i <= n ; i++) {
        int len = strlen(s[i]);
        for(int j = 1 ; j < len ; j++) {
            memset(str , 0 , sizeof(str));
            strncpy(str , s[i] , j);
            if(trie.find(str) && trie.find(s[i] + j)) {
                printf("%s\n" , s[i]);
                break;
            }
        }
    }
    return 0;
}