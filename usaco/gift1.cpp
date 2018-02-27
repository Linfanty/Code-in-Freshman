/*
ID: wty2001
LANG: C++
TASK: gift1
 */

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
using namespace std;
int n;

map<string, int> mymap;
int wei[15][2];
string name[20];

void init()
{
  int i;
  freopen("gift1.in", "r", stdin);
  freopen("gift1.out", "w", stdout);
  memset(wei, 0, sizeof(wei));
  scanf("%d", &n);

  for (i = 0; i < n; ++i)
 {
    cin >> name[i];
    mymap[name[i]] = i;
  }

  string str, str1;

  while (cin >> str)
 {
    int cnt, id, recid, i;
    id = mymap[str];
    scanf("%d%d", &wei[id][0], &cnt);
    for (i = 0; i < cnt;++i) {
      cin >> str1; recid = mymap[str1];
      int tmp = wei[id][0] / cnt;
      wei[id][0] = tmp * cnt;
      wei[recid][1] += tmp;
    }
  }

}

void solve()
{
  int i;
  for (i = 0; i < n; ++i)
    cout << name[i] << ' ' << -wei[i][0]+wei[i][1]<<'\n';
}

int main(void) {
  init();
  solve();

  return 0;
}
