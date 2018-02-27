#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int a[15];
    int t,n;
    cin>>t;
    while(t--)
    {
        memset(a,0,sizeof(a));
        cin>>n;
        for(int i=1;i<=n;i++)
        {
            int t=i;
            while(t)
            {
                int num=t%10;
                a[num]++;
                //	printf("%d %d %d\n",t,num,a[num]);
                t/=10;
            }

        }
        for(int i=0;i<10;i++)
        {
            if(i)
                cout<<" ";
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
