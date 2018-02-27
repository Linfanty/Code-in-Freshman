#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

const int maxn=10;

char board[maxn][maxn];     //记录棋盘状态  
int place[maxn];        //记录一列是否已经放过棋子
int n,k;
int cnt,num;    //cnt 是放棋子的方案数 ，num是已放棋子数目  

void DFS(int i){
    if(k==num){
        cnt++;
        return ;
    }
    if(i>=n)
        return ;
    for(int j=0;j<n;j++)
        if(!place[j] && board[i][j]=='#'){
            place[j]=1;
            num++;
            DFS(i+1);
            place[j]=0;
            num--;
        }
    DFS(i+1);   //i行不放棋子
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);	
    int i,j;
    while(scanf("%d%d",&n,&k)){
        getchar();
        if(n==-1 && k==-1)
            break;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++)
                scanf("%c",&board[i][j]);
            getchar();
        }
        memset(place,0,sizeof(place));
        cnt=0;
        num=0;
        DFS(0);
        printf("%d\n",cnt);
    }
    return 0;
}
