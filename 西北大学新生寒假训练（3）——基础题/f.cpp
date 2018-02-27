#include<string.h>
#include<string>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
#include<climits>
#include<map>
#include<set>
typedef long long ll;
const int maxn = 105;
using namespace std;
set<string> s;
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	
	string line;
	while(getline(cin,line))
	{
		s.clear() ;
		if(line=="#")
		break;
		string x;
		int sum=0;
		stringstream pri(line);
		while(pri>>x)
		{
			s.insert(x);
		}
		printf("%d\n",s.size());
	}
	return 0;
}
