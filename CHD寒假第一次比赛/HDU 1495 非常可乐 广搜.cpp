#include <queue>
#include <cstring>
#include<iostream> //用来给数组赋初值为0的，memset；
using namespace std;
/*
总结：1，深刻理解广搜，以前总是局限于地图，迷宫的问题，这题也可以用广搜，
以后求最短，最快，最少的问题（等权）都可以往广搜上面想想。。。
理解每个”step“的含义，这里每一个step就是在正确的倒水路径上的每一次倒水，
一共有6次倒水的方法，让每个“step”做这6个“动作”，
然后一直这样往下”各个方向弥漫“，就一定会找到答案。

2.以前总是做一些地图迷宫的问题，思想拘束在”走一步这个动作“就是一个step，
把思维打开，一个step可以有”n个动作“（一定是所有可能性都包含），而且这n个动作是平行的。这也是这题的关键。

3.自己还是刷题太少了，接触的太少了，思维太局限，
而且还有一些输出的小细节自己可能也注意不到，
感谢”斌大腿“的指教与点播，发现自己与他的差距还是很大。。*/
int b[3],book[101][101][101],half;
struct node
{
    int cur[3],s;          //cur表示现在瓶子里的水，b表示水的容量
}p,temp;          //p获取当前的“head”，temp用于6个动作的记录。
void bfs()
{
    queue<node> q;         //声明一个队列，由于经常做pat乙  只有一组数据习惯声明全局变量，如果把这句放在bfs（）外边，因为有多组
    p.cur[0]=b[0];          //测试数据，如果不把之前队列里的数据清空就会带到下一组测试中（做题考虑下这个机制会不会对某些题目有用）
    p.cur[1]=p.cur[2]=p.s=0;  //放到bfs里面  每次队列都是新的。
    q.push(p);                  //将最开始状态初始化 加入队列q中；
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        for(int i=0;i<3;i++)     //控制哪个杯子往外倒水
        {
            if(p.cur[i]>0)      //如果有水才可以给别的倒水。
            {
                for(int j=0;j<3;j++)   //接受水的杯子
                {
                    temp=p;            //这很重要！之前没加这句一直wa，因为这6个动作是”平行“的，即都是从前一步状态开始的，如果没有
                    if(i==j)  continue ;   //这一句，就不是平行的，相互叠加的。这个很重要！
                    if(temp.cur[i]>b[j]-temp.cur[j])   //判断能不能倒满了，这是可以倒满的情况
                    {
                        temp.cur[i]-=b[j]-temp.cur[j];      //这两句话一定不要颠倒，之前因为这个一直不出答案，先运算后赋值。。。
                        temp.cur[j]=b[j];
                    }
                    else     // 不可以倒满的情况
                    {
                        temp.cur[j]+=temp.cur[i];
                        temp.cur[i]=0;
                    }
                    if(!book[temp.cur[0]][temp.cur[1]][temp.cur[2]])  //判断这种情况是否出现过
                    {
                        book[temp.cur[0]][temp.cur[1]][temp.cur[2]]=1;  //标记为出现过，说明这一步“有效”，step+1；
                        temp.s++;
                        if((temp.cur[0]==half&&temp.cur[1]==half)||(temp.cur[0]==half&&temp.cur[2]==half)||(temp.cur[1]==half&&temp.cur[2]==half))
                            {
                                cout << temp.s << endl;  // step里的每一个“动作”都要判断是否符合条件，因为这动作是平行的 所以放在内循环里面！
                                return ;             //直接跳出bfs
                            }
                            q.push(temp);// 如果不是所求，就把他加到队列里。之后在从每一个“动作调用”
                    }
                }
            }
        }


    }
      cout <<"NO"<<endl;  //如果整个循环结束还是没有找到说明不可以平分；
}
int main()
{
    while(cin >> b[0]>>b[1]>>b[2],b[0]+b[1]+b[2])   //如果相加都等于0 即000 用于结束
    {
        memset(book,0,sizeof(book));  //多组数据每一组都要赋初值，想用book【】【】=｛0｝，必须要在声明book数组时候用；
        book[b[0]][b[1]][b[2]]=1;   //把初始点标记来过，这一点在调用bfs之前做 很多题都要注意这一点。
        if(b[0]%2)  cout << "NO"<<endl;
        else {half=b[0]/2;bfs();}
    }
    return 0;
}

