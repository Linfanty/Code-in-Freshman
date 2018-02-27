//黑白图像 栈
#include <stdio.h>  
#include <string.h>  
#define MAX 2000  
  
int mat[MAX][MAX];  
int visit[MAX][MAX];  
/*由于递归有栈溢出的危险！所以在此使用了显示栈来代替递归调用，写程序时应注意分析，避免出现栈溢出的危险*/  
void dfs(int x,int y,int n)  
{  
    int stack[n*n],top=0;  
    stack[++top]=x;  
    stack[++top]=y;  
    int i,j;  
    while(top!=0)  
    {     
        visit[stack[top-1]][stack[top]]=1;  
        x=stack[top-1];  
        y=stack[top];  
        top-=2;  
        for(i=-1;i<=1;i++)  
            for(j=-1;j<=1;j++)  
            {  
                if(mat[x+i][y+j] && !visit[x+i][y+j])  
                {  
                    stack[++top]=x+i;  
                    stack[++top]=y+j;  
                }  
            }         
    }     
}  
  
int main()  
{  
    int n,count=0;  
    char s[MAX];  
    memset(mat,0,sizeof(mat));  
    memset(visit,0,sizeof(visit));  
    scanf("%d",&n);  
    int i,j;  
    for(i=0;i<n;i++)  
    {  
        scanf("%s",s);  
        for(j=0;j<n;j++)  
        mat[i+1][j+1]=s[j]-'0';  
    }  
    for(i=1;i<=n;i++)  
        for(j=1;j<=n;j++)  
        if(!visit[i][j] && mat[i][j])  
        {  
            count++;  
            dfs(i,j,n);   
        }  
    printf("%d\n",count);  
    return 0;     
}  
