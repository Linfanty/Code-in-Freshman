#include<bits/stdc++.h>
#include <iostream>
#include <algorithm>
typedef long long ll;
typedef unsigned long long ull;
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
#define rep(i,a,b) for(ll i = a; i<=b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define N 400
#define maxn 100100
/*
Stairway to Heaven
给出n个比赛开始时间，结束时间，志愿者人数及名单，
输出参加的比赛时间有重合的志愿者名字，按字母序输出

很朴素的想法，先把队伍映射成标号，然后vis区间标记它的开始时间和结束时间，如果发生冲突则放入set里面，
因为set本身就是按字典排序，因此最后直接输出就行。
*/
map<string, int> mp;//map 志愿者人名与人名编号的 映射
set<string> ans;//ans 志愿者人名答案 集合
int vis[maxn][N];// 志愿者人名在某段时间内是否存在的 二维数组
string name, contest;

int main()
{IO;
    int t, n, v, sta, ed;// 开始、 结束时间
    cin >> t;
    while ( t-- )
    {
        mp.clear();
        ans.clear();
        memset(vis, 0, sizeof(vis) );

        cin >> n;
        int cnt = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> contest >> sta >> ed >> v;
            for(int j = 0; j < v; j++)
            {
                cin >> name; // 输入志愿者名字
                // 先用map 将字符串 与 标号 对应
                if( !mp.count( name )) // 如果志愿者名字不存在mp中
                    mp[ name ] = ++cnt;  //将name添加入mp中 并且从++cnt
                //map.conut 返回1 或 0
                //map.find 返回 地址 或 map.end()

                // 再用 int&　m 取map中的编号
                // 字符串 整型编号 双边对应 进行枚举
                int& m = mp[ name ]; // m 为 name 在 mp 中的地址 或者 int m 没关系
                cout << m << ' ' << &m << ' ' << endl;
                // int&  &&&
                for( int k = sta; k <= ed; k++) // 枚举k的时间变量 从sta到ed
                {
                    if( vis[m][k] )  // 如果m这个人 在k的时间内已存在， 则冲突
                        ans.insert( name ); //将name插入到ans答案集合中
                    vis[m][k] = 1; // 把sta 到 ed 的时间区域全部置于 1 ， 已访问
                }


            }
        }
        // 插入 set 中的元素已经按照 从小到大排好序了
        cout << ans.size() <<endl;
        for(set< string > :: iterator it = ans.begin(); it != ans.end(); it++)
            cout << *it << endl;
    }
}
            /*不冲突的情况：
            .   .
                    .  .
            冲突的情况：
            .     .
               .     .

                .     .
            .      .

            .          .
                .    .
            不冲突的情况少，
            */
