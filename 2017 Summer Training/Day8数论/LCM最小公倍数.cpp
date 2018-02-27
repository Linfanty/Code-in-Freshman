#include <stdio.h>

//int gcd(int a, int b); //�����������Լ��
//int ngcd(int *pa, int n) //N���������Լ��
//int lcm(int a, int b) //����������С������
//int nlcm(int *pa, int n) //N��������С������

int gcd (int a,int b)
{
    if (b==0)
        return a;
    return gcd(b,a%b);
}

int ngcd(int *pa, int n)
{
    if(n == 1)
        return *pa;
    return (gcd(pa[n-1], ngcd(pa, n-1)));
}

int lcm(int a, int b) //��С������ �� �����˻� / ���Լ��
{
    return a*b/gcd(a, b);
}

int nlcm(int *pa, int n)
{
    if(n == 1)
        return *pa;
    return lcm(pa[n-1], nlcm(pa, n-1));
}


int main()
{
    int a,b,n,rgcd,rlcm,rngcd,rnlcm;
    int pa[10];
    printf("please input tow number:");
    scanf("%d %d",&a,&b);
    rgcd=gcd(a,b);
    rlcm=lcm(a,b);
    printf("���Լ���ǣ�%d/n",rgcd);
    printf("��С�������ǣ�%d/n",rlcm);
    printf("please input the n:");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&pa[i]);
    rngcd=ngcd(pa,n);
    rnlcm=nlcm(pa,n);
    printf("���Լ���ǣ�%d/n",rngcd);
    printf("��С�������ǣ�%d/n",rnlcm);
    return 0;
}
