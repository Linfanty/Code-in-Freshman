//链表 
#include<stdio.h>
int left[100],right[100];//全局变量///////////////////////////////// 
int link(int x,int y)
{  //int left[100], right[100];////////非全局变量////////////////// 
    /*left[x]=x-1; 
    left[y]=y-1;
    right[x]=x+1;
    right[y]=y+1;
    */
   return right[x]=y;
   return left[y]=x;    
    }
    
int main()
{   FILE * in;
    FILE * out;
    in=fopen("d:\\in.txt","r");
    out=fopen("d:\\out.txt","w"); 
    
    //int left[100],right[100];////////非全局变量//////////////////
    int i,type,x,y,n,m;
    fscanf(in,"%d %d",&n,&m);
    //printf("\n%d %d",n,m);
    for(i=1;i<=n;i++)
    {left[i]=i-1;right[i]=i+1;}    
    
    for(i=1;i<=m;i++)
    { fscanf(in,"%s%d%d",&type,&x,&y);
      link(left[x],right[x]);
      if(type=='A')
      {
       link(left[y],x);
       link(x,y);
       }
      else
      {
        link(x,right[y]);
        link(y,x);
      }  
    
}
    
    for(x=right[0];x!=n+1;x=right[x])////////输出方法x=right[0];x=right[x]
    fprintf(out,"%d ",x);
    fclose(in);
    fclose(out);
    //system("pause");
    return 0;
    }

/*
#include<stdio.h>
int n, left[1000], right[1000];
void link(int X, int Y) {
right[X] = Y; left[Y] = X;
}
int main() {
int m, X, Y,i;
char type[9];
scanf("%d%d", &n, &m);
for(i = 1; i <= n; i++) 
{
    left[i] = i-1; right[i] = i+1;
}
for(i = 0; i < m; i++) {
    scanf("%s%d%d", &type, &X, &Y);
    link(left[X], right[X]);
    if(type[0] == 'A') {
      link(left[Y], X);
      link(X, Y);
    } else {
      link(X, right[Y]);
      link(Y, X);
    }
}
for(X = right[0]; X != n+1; X = right[X])
    printf("%d ", X);
printf("\n");system("pause");
return 0;
}
*/
