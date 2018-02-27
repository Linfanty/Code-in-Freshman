#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int cmp1(char a,char b)   //升序
{
    return a<b;
}

int cmp2(char a,char b)   //降序
{
    return a>b;
}

int main()
{
    char a[300005],b[300005],map[300005];
    int n,i,alen1,alen2,blen1,blen2,s,e;

    while(cin>>a>>b)
    {
        n=strlen(a);

        sort(a,a+n,cmp1);
        sort(b,b+n,cmp2);

        alen1=0;alen2=n%2==0?n/2:n/2+1;alen2--;   //a先放，如果a是单数，则a多放一个
        blen1=0;blen2=n/2-1;
        s=0,e=n-1;

        for(i=0;i<n;i++)
        {
            if(i%2==0)    //a放
            {
                if(a[alen1]<b[blen1])    //a字符大于b的字符
                {
                    map[s++]=a[alen1++]; //按顺序排放
                }
                else
                {
                    map[e--]=a[alen2--];  //放在新字符串的最尾部
                }
            }
            else    //b放
            {
                if(b[blen1]>a[alen1])   //b字符大于a字符
                {
                    map[s++]=b[blen1++];  //按顺序排放
                }
                else
                {
                    map[e--]=b[blen2--];  //放在新字符串最尾部，即a放字符的前一个位置
                }
            }
        }

        map[n]='\0';
        cout<<map<<endl;
    }
    return 0;
}
