#include <stdio.h>
#define PI 3.1416
int main()
{
	float r,h,c,s1,s2,v1,v2;
	printf("������뾶�͸ߣ�\n");
	scanf("%f,%f",&r,&h);
	c=2*PI*r,s1=PI*r*r,s2=4*PI*r*r,v1=4*PI*r*r*r/3,v2=PI*r*r*h;
	printf("Բ�ܳ���%.2f;Բ�����%.2f;Բ��������%.2f;Բ�������%.2f;Բ���������%.2f\n",c,s1,s2,v1,v2);
	return 0;
}
 