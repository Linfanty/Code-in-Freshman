#include "iostream"
using namespace std;
char p[26],l='a';string s;
char x, y;int i,n,m,j;

int main(){
    cin >> n >> m >> s;
    for (i = 0; i < 26; i++)
        p[i] = l++;

    for (i = 0; i < m; i++){
        cin >> x >> y;
        for (j = 0; j < 26; j++){
            if (p[j] == x)
                p[j] = y;
            else  if (p[j] == y)
                p[j] = x;
        }
    }
    for (i = 0; i < n; i++)
        cout<<p[s[i]-'a'];
}



