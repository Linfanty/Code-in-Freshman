#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<map>

using namespace std;
const int block=50003;
int fa[100100];

int find(int x){
    return fa[x]= (fa[x]==x) ? x : find(fa[x]);
}

int merge(int x, int y){
    int fx=find(x), fy=find(y);
    if (fx!=fy) fa[fx]=fy;
}

char c[10];
int x, y;
int main()
{
    int len, n;
    while (scanf("%d", &len)!=EOF && len!=-1)
    {
        scanf("%d", &n);
        for (int i=1; i<=block*2; i++) fa[i]=i;
        fa[0]=1;
        int ans=-1;
        for (int i=1; i<=n; i++){

            scanf("%d%d", &x, &y);
            scanf("%s", c);
            if (ans!=-1) continue;
            x=(x-1)%block; y=y%block;
            if (c[0]=='e'){
                if (find(x)==find(y+block)) ans=i-1; else{
                merge(x, y);
                merge(x+block, y+block);}
            }else{
                if (find(x)==find(y+block)) ans=i-1;else{
                merge(x, y+block);
                merge(x+block, y);}
            }
        }
        if (ans==-1) ans=n;
        printf("%d\n", ans);
    }
    return 0;
}

