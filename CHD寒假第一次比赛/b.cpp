#include<string.h>
#include<algorithm>
#include<sstream>
#include<iostream>
#include<math.h>
#include<vector>
#include<stdlib.h>
typedef long long ll;
const int maxn = 105;
using namespace std;


vector<int> a;
vector<int> b;
bool cmp(const int &a,const int &b)
{
    return a<b;
}

int main()
{
		int an[maxn],bn[maxn];	
		int n,m;
    	scanf("%d",&n);
         for (int i=0 ;i<n ;i++) 
		 {
			 scanf("%d ",&an[i]);
     		 a.insert(a.begin()+i,an[i]);	
		}
         scanf("%d ",&m);
         for (int i=0 ;i<m ;i++) 
		  {
			 scanf("%d ",&bn[i]);
     		 b.insert(b.begin()+i,bn[i]);	
		}
         
         int count=0;
         sort(a.begin() ,a.end() ,cmp);
         sort(b.begin() ,b.end() ,cmp);
         
         for(int i=0;i<a.size();i++)
         	for(int j=0;j<b.size();j++)
         	{
         		if(abs(a[i]-b[j])<=1)
				{
					count++;
					a.erase(a.begin()+i);
					b.erase(b.begin()+j);	
					break;
				}
			}
         
         printf("%d\n",count);
     
     return 0;
}
