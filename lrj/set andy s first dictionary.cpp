#include<cstdio>
#include<iostream>
#include<string>
#include<set>
#include<sstream>
using namespace std;
set<string> dict;
int main()
{
    string s,buf;
    cin>>s;
    {
        for(int i=0; i<s.length(); i++)
            if(isalpha(s[i])) s[i]=tolower(s[i]);
            else s[i]=' ';
        stringstream ss(s);  
        
        //stringsteam ss(s);  stringstream
		//读取str中的单字，比如hello world ,就会读取hello和world。
		//stringstram 得到各个单词
		 
        while(ss>>buf) 
		dict.insert(buf);
    }
    //set<string>::iterator
    /*
    for(set<string>::iterator it=dict.begin(); it!=dict.end(); ++it)
        cout<<*it<<"\n";
	*/
	for(int i=dict.begin(); i!=dict.end(); ++i)
		cout<<i<<"\n";
    return 0;
}

