/*这道题需要的信息比较多
第一次使用并查集是合并输入id的父母及子女信息
第二次是计算一个大家族的房产总数
第三次通过一个visit数组及查询函数统计家庭总人数
第四次进行运算，完善调整排序后得到最终答案。*/

//Asimple
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std ;
#define MAX 10005
int p[MAX],visit[MAX]={0},la[MAX]={0};
struct node
{
    int id , people ;
    double sum , num ;
};
node person[MAX] ,ans[MAX],p2[MAX];
bool comp(const struct node&a,const struct node&b)
{
    if(a.sum == b.sum)
        return a.id < b.id;
    return a.sum > b.sum;
}
int Find(int x)
{
    int temp = x ;
    while(p[temp]!=temp)
        temp = p[temp] ; 
    return temp;
}
void join(int x , int y)
{
    int t1 , t2 ;
    t1 = Find(x) ;
    t2 = Find(y) ;
    if(t1 != t2)
    {
        if(t1 > t2)
        {
            p[t1] = t2 ;
        }
        else p[t2] = t1 ;
    }
}
int main()
{
    int n ,id, nm , nf , k , nk;
    double hn , hs;
    scanf("%d" , &n);
    for(int i = 0 ; i <MAX ; i ++)
    {
        p[i] = i ;
    }
    for(int i = 0 ; i <n ; i ++)
    {
        scanf("%d%d%d",&id,&nf,&nm) ;
        visit[id] = 1 ;
        if(nm!=-1) {join(id,nm);visit[nm]=1;}
        if(nf!=-1) {join(id,nf);visit[nf]=1;}
        scanf("%d",&k);
        for(int j = 0 ; j < k ; j ++)
        {
            scanf("%d" , &nk);
            if(nk!=-1)
            {
                join(id,nk);
                visit[nk] = 1;
            }
        }
        scanf("%lf%lf",&person[i].num,&person[i].sum);
        person[i].id = id;
    }
    for(int i = 0 ; i < n ; i ++)
    {
        int tid = Find(person[i].id);
        p2[tid].id = tid;
        p2[tid].num += person[i].num;
        p2[tid].sum += person[i].sum;
        //cout << p2[tid].sum<<endl;
    }
    int ren = 0 ;
    for(int i = 0 ; i < MAX ; i ++)
    {
        if(visit[i])
            p2[Find(i)].people++;
    }
    for(int i = 0 ; i <MAX ; i ++)
    {
        if(visit[i])
        {
            int ttt = Find(i) ;
            if(!la[ttt])
            {
                la[ttt] = 1 ;
                //cout <<p2[ttt].num<<endl;
                double xx = double(p2[ttt].people);
                ans[ren].id = ttt;
                ans[ren].num = p2[ttt].num*1.0/xx;
                ans[ren].sum = p2[ttt].sum*1.0/xx;
                ans[ren++].people = int(xx) ;
            }
        }
    }
    
    printf("%d\n" , ren) ;
    sort(ans,ans+ren,comp);
    
    for(int i = 0 ; i < ren ; i ++)
        printf("%04d %d %.3f %.3f\n" , ans[i].id,ans[i].people,ans[i].num,ans[i].sum);
        
    return 0 ;
}
