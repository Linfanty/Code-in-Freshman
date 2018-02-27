#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in.txt","r",stdin);
    string line,linenew;
    int flag = 0;
    int ff = 0;
    //int gg = 0;
    while( getline( cin, line)  )
    {
        int len = line.size();
        linenew = '';
        for(int i = 0; i < len; i++)
        {
            if( flag != 1 && flag != 2 )
            ff = 0;
            char x = line[i];
            if( x == '/' && flag == 0) // 第一次 /
            {
                flag = 1;
                //gg = 0;
                ff = 0;
                continue;
            }

            if( x == '/' && flag == 1) //第二次 / 遇到//
            {
                flag = 0;
                ff = 1;
                break;
            }
            
            if( x == '*' && flag == 1) //遇到 /*
            {
                flag = 2;
                ff = 1;
                break;
            }

            if( x == '*' && flag == 2)  // 遇到 /* *
            {
                flag = 0;
                //gg = 1;
                break;
            }
            /*
            不能按字符直接输出， 比如说遇见     //test的情况
            前面有空格，就都输出了
            */
            if( flag != 2 )  
            linenew.push_back(x);

        }
        if( ff == 1 && line[0] != '/' && gg == 0)
            cout << endl; 
        else if( ff == 1 )
        {
            cout << linenew.find_first_not_of(" ") << 
        }
        else
        cout << endl;
    }

}