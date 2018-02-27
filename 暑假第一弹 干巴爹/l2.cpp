#include <iostream>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <math.h>
using namespace std;
const int MAXN=210;

pair<int,int>p[MAXN];

double dis(pair<int,int>p1,pair<int,int>p2)
{
    return sqrt((double)(p1.first-p2.first)*(p1.first-p2.first)+(p2.second-p1.second)*(p2.second-p1.second));
}
double dist[MAXN][MAXN];
int main()
{
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);
    int n;
    int x,y;
    int iCase=0;
    while(scanf("%d",&n)==1&&n)
    {
        iCase++;
        printf("Scenario #%d\n",iCase);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            p[i]=make_pair(x,y);
        	//cout << p[i].first << endl;
		}
        
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
            {
                if(i==j)dist[i][j]=dis(p[i],p[j]);
                else dist[j][i]=dist[i][j]=dis(p[i],p[j]);
            }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(dist[i][j]>max(dist[i][k],dist[k][j]))
                        dist[i][j]=max(dist[i][k],dist[k][j]);
        printf("Frog Distance = %.3f\n\n",dist[0][1]);
    }
    return 0;
}
