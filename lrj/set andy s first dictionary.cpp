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
		//��ȡstr�еĵ��֣�����hello world ,�ͻ��ȡhello��world��
		//stringstram �õ���������
		 
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

