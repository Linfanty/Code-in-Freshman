#include<bits/stdc++.h>

using namespace std;
const double eps = 1e-8;
int n;
double p, a[100010], b[100010];
/*
�ж� n ̨�����Ƿ��ܼ������ t �룺�� t ��ʱ�������ܹ���������ֵΪ p*t ��
ö���ж� n ̨�����ܷ��� t �룬������������Ļ�����
�� p*t ����ֵ�п۳����㲿�֡�
������ p*t ����ʣ�࣬˵�������ܼ�� t �룬�����ܡ�
*/

bool jug(double t)
{
    double ext = p * 1.0 * t;
    double sub;

    for(int i=1;i<=n;i++)
    {
        sub = a[i] * t - b[i]; 
        
        if(sub > 0)    // ���� ���� ʣ�� 
            ext -= sub;  //�ܲ��������ü�ȥ��Щ 
        if(ext < 0) return false; // ������С��0 
    }

    return true;
}


int main()
{
    double sum = 0;
    scanf("%d %lf",&n,&p);
    for(int i=1;i<=n;i++)
        scanf("%lf %lf",&a[i],&b[i]),   sum += a[i];
    
	if((p - sum) >= -eps){  //���ҽ��� ��ai��p ʱ���ܹ����޹�����
        printf("-1\n");
        return 0;
    }
    
	double l = 0, r = 1e12, mid, ans;
    
	while((r-l) > eps)  
	//���ֽ���ö���ܹ�ͬʱ���� t �룬�ٶ� t ���ж�ÿ̨�����Ƿ��ܹ���� t ���ӡ�
    {
        mid = (l+r)/2;
        
		if(jug(mid))    
            l = mid,  ans = mid;  //�������ص� 
        
		else
            r = mid;
    }
    
    printf("%.8lf\n", ans);
}

/*
�����δ�����ܳ����� 32 λ��������������������������ѭ������������Կ��ǽ� eps ��Ϊ 1e-6������ 64 λ�����������С�
ԭ�� 32 λ�������� double ����Ч���ֽ��� 15 λ���ҡ�
Sample��
25000 49999
2 99999
2 99999
2 99999
...
2 99999

��ͳ���������� double ����Чλ�������Լ�����𰸽ϴ��� 1e-4 ����Ծ����£����ƶ��ִ��� 100 �����ҿ��Ա�֤�ﵽ����Ҫ����ʱ��϶̡�
*/
