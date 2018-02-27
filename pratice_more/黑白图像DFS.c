#include<stdio.h>  
#define MAXN 30  
int mat[MAXN][MAXN], vis[MAXN][MAXN];  

void dfs(int x, int y)  
{  
    if(!mat[x][y] || vis[x][y])//�����ʹ���Ϊ��ɫ  
        return;  
      
    vis[x][y] = 1; //���(x,y)�ѷ��ʹ�   
      
    dfs(x-1, y-1);  dfs(x-1, y);  dfs(x-1, y+1);  
    dfs(x, y-1);                  dfs(x, y+1);  
    dfs(x+1, y-1);  dfs(x+1, y);  dfs(x+1, y+1); //�ݹ������Χ8������     
}  
  
int main()  
{  FILE * in;
    FILE * out;
    in=fopen("d:\\in.txt","r");
    out=fopen("d:\\out.txt","w"); 
    
    memset(mat, 0, sizeof(mat));  
    memset(vis, 0, sizeof(vis));  
    char s[MAXN];  
    int n,i,j;  
    fscanf(in,"%d",&n);  
    for(i=0; i<n; i++)  
    {  
        fscanf(in,"%s",&s);  
        for(j=0; j<n; j++)  
            {
                 mat[i+1][j+1] = s[j]-'0';  //��˴�ӡ�ַ����и������֣�j��0��n ��ӡs[j]-'0'  
                 //fprintf(out,"%d",s[j]-'0');
            }  
    }  
      
    int count = 0;  
    for(i=1; i<=n; i++)  
        for(j=1; j<=n; j++)  
            if(mat[i][j] && !vis[i][j]){  
                count++;  
                dfs(i,j);  
            }  
      
    fprintf(out,"%d\n",count);  
    //system("pause");
    fclose(in);
    fclose(out);
    return 0;  
}  
