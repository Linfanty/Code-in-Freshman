#include<iostream>
#include<cstring>
#include<algorithm>

using namespace std;

int cmp1(char a,char b)   //����
{
    return a<b;
}

int cmp2(char a,char b)   //����
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

        alen1=0;alen2=n%2==0?n/2:n/2+1;alen2--;   //a�ȷţ����a�ǵ�������a���һ��
        blen1=0;blen2=n/2-1;
        s=0,e=n-1;

        for(i=0;i<n;i++)
        {
            if(i%2==0)    //a��
            {
                if(a[alen1]<b[blen1])    //a�ַ�����b���ַ�
                {
                    map[s++]=a[alen1++]; //��˳���ŷ�
                }
                else
                {
                    map[e--]=a[alen2--];  //�������ַ�������β��
                }
            }
            else    //b��
            {
                if(b[blen1]>a[alen1])   //b�ַ�����a�ַ�
                {
                    map[s++]=b[blen1++];  //��˳���ŷ�
                }
                else
                {
                    map[e--]=b[blen2--];  //�������ַ�����β������a���ַ���ǰһ��λ��
                }
            }
        }

        map[n]='\0';
        cout<<map<<endl;
    }
    return 0;
}
