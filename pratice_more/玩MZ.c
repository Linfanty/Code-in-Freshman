//ÍæÃÃ×Ó
#include <stdio.h>
int a[1000001];
 int gcd(int a, int b)
{
	int t;
	if(a < b)
	{
		t = a;
		a = b;
		b = t;
	}
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

int main()
{  long n,m,i,q,w,j;
 int data[100001],g;
 int k;
   scanf("%d%d",&n,&m);
   memset(a,0,sizeof(a));
   for(i=0;i<=m;i++)
   {scanf("%d",&k);
    if(k==1)
            {scanf("%d %d %d",&q,&w,&k);
            if(q==w)
            a[q]=a[q]+k;
            else for(j=q;j<=w;j++)
            a[j]=a[j]+k;
            }
    else 
    {scanf("%d %d",&q,&w);
    k=w-q+1;
    for(j=q,i=0;j<=w;j++,i++)
    data[i]=a[j];
	g = data[0];
	for(i=0;i<k;i++)
		g=gcd(g,data[i]);
	printf("%d\n",g);
//	system("pause");
   }
    
 }
   
   //printf("%d",y);
  // system("pause");
    return 0;
} 
