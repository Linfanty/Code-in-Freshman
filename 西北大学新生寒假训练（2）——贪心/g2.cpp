#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    //freopen("a.txt","r",stdin);
    int king[1005],tianji[1005];
    int n;
    while(cin>>n&&n)
    {
        int t1,t2,k1,k2,cnt=0; //cnt������¼ ���Ӯ�˶��ٴ�
        int i;
        for(i=0;i<n;i++) cin>>tianji[i];
        for(i=0;i<n;i++) cin>>king[i];
        sort(tianji,tianji+n,cmp);//�Ӵ�С����
        sort(king,king+n,cmp);
        t1=k1=0;t2=k2=n-1;
        for(i=0;i<n;i++)
        {
            if(tianji[t1]>king[k1]) //������������ȹ����������
            {
                cnt++;
                t1++;
                k1++;
                continue;
            }
            if(tianji[t1]<king[k1]) //������������ȹ�����������ô���������������������������
            {
                cnt--; //���� �������һ��
                k1++;  //�����������õ���
                t2--; //������������õ���
                continue;
            }
            if(tianji[t1]==king[k1]) //�����ɵ�������������ٶ����
            {
                if(tianji[t2]>king[k2]) //�Ƚ�������  ͬ��
                {
                    cnt++;
                    t2--;
                    k2--;
                    continue;
                }
                if(tianji[t2]<king[k2]) //ͬ�� ������������ȹ���������������ô����� �Ŀ����������
                {
                    cnt--;
                    t2--;
                    k1++;
                    continue;
                }
                if(tianji[t2]==king[k2]) //���������������ȣ���ô�����������͹�����������
                {
                    if(tianji[t2]<king[k1])
                    {
                        cnt--;
                        t2--;
                        k1++;
                        continue;
                    }
                }
            }
        }
        cout<<cnt*200<<endl;

    }
    return 0;
}


