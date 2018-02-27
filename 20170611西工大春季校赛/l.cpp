#include <bits/stdc++.h>
#include <iostream>
typedef long long ll;
#define maxn 100005
using namespace std;
string s;
/*
struct Node{
    char root;
    char zuoshang;
    char youshang;
    char zuoxia;
    char youxia;
}node[maxn];


void storage(int id, string s)
{
    if(s[id] == 'x')
    {
        node[id].root = s[i];
        node[id].zuoshang = s[i+1];
        if( node[id].zuoshang == 'x')
            storage(++id,s)
        node[id].youshang = s[i+2];
        node[id].zuoxia = s[i+3];
        node[id].youxia = s[i+4];
    }
    else
    {
        node[id].zuoshang = s[i];
        node[id].youshang = s[i+1];
        node[id].zuoxia = s[i+2];
        node[id].youxia = s[i+3];
    }
}

    x // root
    b w w b

*/

void digui(int x)
{
    if(s[i] != 'x')
        return;
    swap(上左 , 下左);
    swap(上右 , 下右);
    digui( x + 1 );
}

int main()
{
    ll n;
    cin >> n;
    while( n-- )
    {
        cin >> s;
        digui(s);

    }

}
