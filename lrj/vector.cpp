#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
using namespace std;

vector<double> vec;

int main()
{
	int i=2; 
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	//插入元素：
	
	vec.insert(vec.begin()+i,10);
//	在第i个元素 后面 插入a;
//vec.pop_back() ;
//(7)删除元素：    
	vec.erase(vec.begin()+1);
//删除第3个元素
//(8)向量大小:vec.size();

//(9)清空:vec.clear();
//sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	cout<<vec[i]<<endl;
	return 0;
} 
