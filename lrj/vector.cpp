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
	//����Ԫ�أ�
	
	vec.insert(vec.begin()+i,10);
//	�ڵ�i��Ԫ�� ���� ����a;
//vec.pop_back() ;
//(7)ɾ��Ԫ�أ�    
	vec.erase(vec.begin()+1);
//ɾ����3��Ԫ��
//(8)������С:vec.size();

//(9)���:vec.clear();
//sort(vec.begin(),vec.end());
	for(int i=0;i<vec.size();i++)
	cout<<vec[i]<<endl;
	return 0;
} 
