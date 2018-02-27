#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <cmath>
#define lson rt<<1, l, mid
#define rson rt<<1|1, mid+1, r
#define rep(i,a,b) for(ll i = a; i<b ;++i)
#define per(i,a,b) for(ll i = a; i>=b ;--i)
#define inf 0x3f3f3f3f
#define mem(a, b) memset(a, b, sizeof(a))
#define IO ios_base::sync_with_stdio(0),cin.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 500005;

struct Node {
    double x, y;
    int flag;//�ѵ㼯��x�����С��������
    bool operator < (const Node b) const {
        return x < b.x;
    }
}point[maxn];

double dist(const Node& a, const Node& b)
{
    if( a.flag != b.flag)
        return sqrt((a.x-b.x) * (a.x-b.x)+ (a.y-b.y) * (a.y-b.y));
    else return inf;
}

int yy[maxn];
double shortestdis(int left, int right)
{
    if( right - left == 1)//ֻʣ��������
        if(point[left].flag != point[right].flag )return dist(point[left], point[right]);
        else return inf;

    else if( right -left == 2)// ʣ��������
        return min(
        min(dist(point[left], point[left+1]),
            dist(point[left], point[left+2]))
        ,dist(point[left+1], point[left+2]));

    int mid = (left+right)/2;
    double mind = min(shortestdis(left,mid), shortestdis(mid+1, right));
    ///�ݹ���μ������߲��ֺ��ұ߲��ֵ���С����mind

    if( mind == 0) return 0;
    int yn = 0;
    ///����ĵ��λ�ã�һ������  mid-d,mid+d ֮��
    /// ��� ��ǰp[i]�� ������λ�� ��Χ���е������-mind���е������+mind��λ���ڣ����¼������
    for(int i = mid ; point[mid].x - point[i].x < mind && i >= left; i--)
        yy[yn++] = i;
    int ymid = yn;

    for(int i = mid + 1; point[i].x - point[mid].x < mind && i <= right; i++)
        yy[yn++] = i;

    ///��������俪ʼ�ҵ㣬�����ϸ���dֵ
    rep(i, 0, ymid)
        rep(j, ymid, yn)
            mind = min(mind, dist(point[yy[i]],point[yy[j]]));
            ///����벿�ֺ��Ұ벿�ִ���һ�Ե����С��mind
    return mind;
}

int main()
{
    int t;      scanf("%d", &t);
    while( t-- ) {
        int n;  scanf("%d", &n);
        rep(i, 0, n)
            scanf("%lf %lf", &point[i].x, &point[i].y), point[i].flag = 0;

        rep(i, n, 2*n)
           scanf("%lf %lf", &point[i].x, &point[i].y), point[i].flag = 1;
        sort( point, point + 2*n);
        printf("%.3lf\n", shortestdis(0, 2*n-1));
    }
}
