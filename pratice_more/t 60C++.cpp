/*题解：

该题的t的范围一开始吓到我了，不过将t/60就可以了。

代码实现：
*/
#include<iostream>
#include<cstring>
using namespace std;

int f[18001],n,t;

int main()
{
    int i,j;
    cin>>n>>t;t=t/60;
    
    memset(f,0,sizeof(f));
    for(i=1;i<=n;i++)
    {
    int t1,w1,t2,w2;
    cin>>w1>>t1>>w2>>t2;
    t1=t1/60;t2=t2/60;
    
    //for(i=1;i<=m;i++) 
    //for(j=0;j<=t;j++)
    
     for(j=t;j>=min(t1,t2);j--)
     {
     if(j-t1>=0&&f[j]<f[j-t1]+w1) f[j]=f[j-t1]+w1;
     if(j-t2>=0&&f[j]<f[j-t2]+w2) f[j]=f[j-t2]+w2;
     }
    }
    
    cout<<f[t]<<endl;
    system("pause");
    return 0;
    
    }
