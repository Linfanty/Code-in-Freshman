//������Ϸ 
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
    queue[i]=i+1;      //��ʼ������ 
    front=0;           //����Ԫ��λ�� 
    rear=n;            //��βԪ�غ�һ��λ�� 
    while(front<rear)  //�����зǿ� 
    {
                     //fprintf(out,"%d ",queue[front++]);
                     printf("%d ",queue[front++]);
                     
                     queue[rear++]=queue[front++];                     
                     }

//�Ƿ��ڴ� 
                     system("pause");





    //fclose(in);
    //fclose(out);
    
    return 0;
}

