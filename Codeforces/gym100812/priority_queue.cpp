/*���ȶ��еĻ���ʹ��    2010/7/24    dooder*/
/*http://www.cnblogs.com/heqinghui/archive/2013/07/30/3225407.html*/
#include<stdio.h>
#include<functional>
#include<queue>
#include<vector>
using namespace std;
//����ṹ��ʹ�����������,�Զ������ȼ�1
struct cmp1{
    bool operator ()(int &a,int &b){
        return a>b;//��Сֵ����
    }
};
struct cmp2{
    bool operator ()(int &a,int &b){
        return a<b;//���ֵ����
    }
};
//����ṹ��ʹ�����������,�Զ������ȼ�2
struct number1{
    int x;
    bool operator < (const number1 &a) const {
        return x>a.x;//��Сֵ����
    }
};
struct number2{
    int x;
    bool operator < (const number2 &a) const {
        return x<a.x;//���ֵ����
    }
};
int a[]={14,10,56,7,83,22,36,91,3,47,72,0};
number1 num1[]={14,10,56,7,83,22,36,91,3,47,72,0};
number2 num2[]={14,10,56,7,83,22,36,91,3,47,72,0};

int main()
{   priority_queue<int>que;//����Ĭ�����ȼ��������

    priority_queue<int,vector<int>,cmp1>que1;//��Сֵ����
    priority_queue<int,vector<int>,cmp2>que2;//���ֵ����

    priority_queue<int,vector<int>,greater<int> >que3;//ע�⡰>>���ᱻ��Ϊ����
                                                      //������������������������ÿո�Ÿ���
    priority_queue<int,vector<int>,less<int> >que4;////���ֵ����

    priority_queue<number1>que5;
    priority_queue<number2>que6;

    int i;
    for(i=0;a[i];i++){
        que.push(a[i]);
        que1.push(a[i]);
        que2.push(a[i]);
        que3.push(a[i]);
        que4.push(a[i]);
    }
    for(i=0;num1[i].x;i++)
        que5.push(num1[i]);
    for(i=0;num2[i].x;i++)
        que6.push(num2[i]);


    printf("����Ĭ�����ȹ�ϵ:\n(priority_queue<int>que;)\n");
    printf("Queue 0:\n");
    while(!que.empty()){
        printf("%3d",que.top());
        que.pop();
    }
    puts("");
    puts("");

    printf("���ýṹ���Զ������ȼ���ʽһ:\n(priority_queue<int,vector<int>,cmp>que;)\n");
    printf("Queue 1:\n");
    while(!que1.empty()){
        printf("%3d",que1.top());
        que1.pop();
    }
    puts("");
    printf("Queue 2:\n");
    while(!que2.empty()){
        printf("%3d",que2.top());
        que2.pop();
    }
    puts("");
    puts("");
    printf("����ͷ�ļ�\"functional\"�ڶ������ȼ�:\n(priority_queue<int,vector<int>,greater<int>/less<int> >que;)\n");
    printf("Queue 3:\n");
    while(!que3.empty()){
        printf("%3d",que3.top());
        que3.pop();
    }
    puts("");
    printf("Queue 4:\n");
    while(!que4.empty()){
        printf("%3d",que4.top());
        que4.pop();
    }
    puts("");
    puts("");
    printf("���ýṹ���Զ������ȼ���ʽ��:\n(priority_queue<number>que)\n");
    printf("Queue 5:\n");
    while(!que5.empty()){
        printf("%3d",que5.top());
        que5.pop();
    }
    puts("");
    printf("Queue 6:\n");
    while(!que6.empty()){
        printf("%3d",que6.top());
        que6.pop();
    }
    puts("");
    return 0;
}
/*
���н�� ��
����Ĭ�����ȹ�ϵ:
(priority_queue<int>que;)
Queue 0:
 91 83 72 56 47 36 22 14 10  7  3

���ýṹ���Զ������ȼ���ʽһ:
(priority_queue<int,vector<int>,cmp>que;)
Queue 1:
  3  7 10 14 22 36 47 56 72 83 91
Queue 2:
 91 83 72 56 47 36 22 14 10  7  3

����ͷ�ļ�"functional"�ڶ������ȼ�:
(priority_queue<int,vector<int>,greater<int>/less<int> >que;)
Queue 3:
  3  7 10 14 22 36 47 56 72 83 91
Queue 4:
 91 83 72 56 47 36 22 14 10  7  3

���ýṹ���Զ������ȼ���ʽ��:
(priority_queue<number>que)
Queue 5:
  3  7 10 14 22 36 47 56 72 83 91
Queue 6:
 91 83 72 56 47 36 22 14 10  7  3
*/