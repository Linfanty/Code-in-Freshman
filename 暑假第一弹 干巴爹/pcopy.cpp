#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
int const MAX = 500005;
int a[MAX], n;
ll ans;
 
void Merge(int l, int mid, int r)
{
    int i = l, j = mid + 1;
    while(i <= mid && j <= r)
    {
        if(a[i] <= a[j])
            i ++;
        else
        {
            j ++;
            //因为左右区间都是有序的，因此a[i]>a[j]说明a[i]~a[mid]都大于a[j]
            ans += mid - i + 1;
        }
    }
    sort(a + l, a + r + 1);
    return;
}
 
void Merge_sort(int l, int r)
{
    if(l < r)
    {
        int mid = (l + r) / 2;
        Merge_sort(l, mid);
        Merge_sort(mid + 1, r);
        Merge(l, mid, r);
    }
    return;
}
 
int main()
{
    while(scanf(%d, &n) != EOF && n)
    {
        ans = 0;
        for(int i = 0; i < n; i++)
            scanf(%d, &a[i]);
        Merge_sort(0, n - 1);
        printf(%lld, ans);
    }
}
