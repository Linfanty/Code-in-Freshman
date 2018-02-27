#include <bits/stdc++.h>
using namespace std;

int main()
{
    freopen("in1.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    
    string line, newline;
    int flag, x = 0;

    while( getline( cin, line)  )
    {
      int len = line.size();

      for(int i = 0; i < len; i++)
      {
        if( line[i] == '/' && line[i+1] == '/')
        {
            flag = 0;
            for(int j = i-1; j >= 0 ; j--)
            {
                if(line[j] != ' ')
                {
                    x = j; 
                    flag = 1;
                    break;
                }
            }
            
            if( flag == 1)
                cout << line.substr(0,x+1) << endl;
            break;
        }
       

      } 


    }

}