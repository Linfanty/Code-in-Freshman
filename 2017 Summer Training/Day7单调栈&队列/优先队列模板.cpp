#include<stdio.h>
#define M 2000005
int a[M],Q[M],I[M];
int i,n,k;

void getMax(){
    int head=1,tail=0;
    for(i=1;i<k;i++){
        while(head<=tail&&Q[tail]<=a[i])tail--;
        tail++;
        Q[tail]=a[i];I[tail]=i;
    }
    for(i=k;i<=n;i++){
        while(head<=tail&&Q[tail]<=a[i])tail--;
        tail++;
        Q[tail]=a[i];I[tail]=i;
        while(I[head]<=i-k)head++;
        printf("%d ",Q[head]);
    }
}

void getMin(){
    int head=1,tail=0;
    for(i=1;i<k;i++)
    {
        while(head<=tail&&Q[tail]>=a[i])
            tail--;

        tail++;

        Q[tail]=a[i];
        I[tail]=i;
    }

    for(i=k;i<=n;i++)
    {
        while(head<=tail&&Q[tail]>=a[i])
            tail--;
        tail++;

        Q[tail]=a[i];
        I[tail]=i;

        while(I[head]<=i-k)
            head++;
        printf("%d ",Q[head]);
    }
}

int main(){
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    getMin();
    printf("\n");
    getMax();
    return 0;
}
