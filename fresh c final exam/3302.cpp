#include<stdio.h> 
struct student     
{          
int num;
char name[20];
int score[3];
}stu[5];
int main()
{
  void print(struct student stu[]); 
   int i,j;      
   for(i=0;i<5;i++)
    {     
printf("������ѧ��%d��ѧ��:",i+1);
scanf("%d",&stu[i].num);      
printf("����������");
scanf("%s",stu[i].name);    
printf("�������ѧ����3�Ƴɼ���");      
for(j=0;j<3;j++)      
scanf("%d",&stu[i].score[j]);
}     
print(stu);  
return 0; 
} 
				  
void print(struct student stu[])
{
int i,j;
for(i=0;i<5;i++)
{printf("ѧ�ţ�%d\t������%s\t",stu[i].num,stu[i].name);
printf("3�Ƴɼ���");
for(j=0;j<3;j++)
printf("%d\t",stu[i].score[j]);
printf("\n");
}				
}

