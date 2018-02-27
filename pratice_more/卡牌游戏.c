//卡牌游戏 
#include<stdio.h>
//const int MAXN=50;
main()
{     int queue[50];
    int i,n,front,rear;
    /*FILE * in;
    FILE * out;
    in=fopen("d:\\in.txt","r");
    out=fopen("d:\\out.txt","w"); 
    fscanf(in,"&d",&n);
    */
    scanf("%d",&n);
    for(i=0;i<n;i++)
    queue[i]=i+1;      //初始化队列 
    front=0;           //队首元素位置 
    rear=n;            //队尾元素后一个位置 
    while(front<rear)  //当队列非空 
    {
                     //fprintf(out,"%d ",queue[front++]);
                     printf("%d ",queue[front++]);
                     
                     queue[rear++]=queue[front++];                     
                     }

//非法内存 
                     system("pause");





    //fclose(in);
    //fclose(out);
    
    return 0;
}

