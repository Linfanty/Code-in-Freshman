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
printf("请输入学生%d的学号:",i+1);
scanf("%d",&stu[i].num);      
printf("输入姓名：");
scanf("%s",stu[i].name);    
printf("请输入该学生的3科成绩：");      
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
{printf("学号：%d\t姓名：%s\t",stu[i].num,stu[i].name);
printf("3科成绩：");
for(j=0;j<3;j++)
printf("%d\t",stu[i].score[j]);
printf("\n");
}				
}

