#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
typedef long long LL;

int main()
{
    string s;
    cin >>s;
    int flag = 0, x = 1;
    int len = s.size();
    for(int i = 0; i <len ;i++)
    {
        if(s[i]=='h' && s[i+1]=='a'&&s[i+2]=='p'
           &&s[i+3]=='p'&&s[i+4]=='i'&&s[i+5]=='n'
           &&s[i+6]=='e'&&s[i+7]=='s'&&s[i+8]=='s')
        {
            flag ++;
            //cout<<i;
            x =  i+1;
        }
        if(flag == 2)
        {
            cout << "NO"<<endl;
            break;
        }
    }
    if( flag <= 1)
        cout<<"YES"<<endl<<x <<' ' << x+1<<endl;
}
