#include<stdio.h>
main()
{   int i,j;
     int f[100],n,m,v,w;
FILE * in;
 FILE * out;
 in=fopen("d:\\in.txt","r");
 out=fopen("d:\\out.txt","w"); 
    
    fscanf(in,"%d%d",&n,&m);//n表示个数，m表示背包容量 
    for(i=1;i<=n;++i){
        fscanf(in,"%d%d",&v,&w);//v=价值，w=重量
        for(j=m;j>=w;--j)
            if(f[j]<f[j-w]+v)
                f[j]=f[j-w]+v;
    }
    fprintf(out,"%d\n",f[m]);

    fclose(in);
     fclose(out);
    return 0;
    }
/*

#include<stdlib.h>
#define MAX 1111
    int f[MAX],n,m,v,w;
int main(){
    int i,j;
    scanf("%d%d",&n,&m);//n表示个数，m表示背包容量 
    for(i=1;i<=n;++i){
        scanf("%d%d",&v,&w);//v=价值，w=重量
        for(j=m;j>=w;--j)
            if(f[j]<f[j-w]+v)
                f[j]=f[j-w]+v;
    }
    printf("%d\n",f[m]);
    return 0;
}

*/
