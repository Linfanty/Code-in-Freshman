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
    /*set<string>::iterator
    迭代器（Iterator）模式，
	又叫做游标（Cursor）模式。
	GOF给出的定义为：提
	供一种方法访问一个容器（container）对象中各个元素，
	而又不需暴露该对象的内部细节。 从定义可见，迭代器模式是为容器而生。
	很明显，对容器对象的访问必然涉及到遍历算法。
	你可以一股脑的将遍历方法塞到容器对象中去；
	或者根本不去提供什么遍历算法，让
	使用容器的人自己去实现去吧。这两种情况好像都能够解决问题。
	*/
    for(set<string>::iterator it=dict.begin(); it!=dict.end(); ++it)
        cout<<*it<<"\n";
	
	/*	for(int i=dict.begin(); i!=dict.end(); ++i)
		cout<<i<<"\n";
		*/
    return 0;
}

