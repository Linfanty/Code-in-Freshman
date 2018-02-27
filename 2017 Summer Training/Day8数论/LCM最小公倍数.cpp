#include <stdio.h>

//int gcd(int a, int b); //两个数的最大公约数
//int ngcd(int *pa, int n) //N个数的最大公约数
//int lcm(int a, int b) //两个数的最小公倍数
//int nlcm(int *pa, int n) //N个数的最小公倍数

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

int lcm(int a, int b) //最小公倍数 ＝ 两数乘积 / 最大公约数
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
    printf("最大公约数是：%d/n",rgcd);
    printf("最小公倍数是：%d/n",rlcm);
    printf("please input the n:");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        scanf("%d",&pa[i]);
    rngcd=ngcd(pa,n);
    rnlcm=nlcm(pa,n);
    printf("最大公约数是：%d/n",rngcd);
    printf("最小公倍数是：%d/n",rnlcm);
    return 0;
}
