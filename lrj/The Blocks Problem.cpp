#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<string>
using namespace std;
vector<int> pile[30]; 
vector<double> vec;
int n=10;
void find_block(int a,int& p,int& h)
{
	for(p=0;p<n;p++)
		for(h=0;h<pile[p].size();h++)
		if(pile[p][h]==a)
		return;
}
int main()
{
	vec.push_back(1);
	string s1;
	s1="move";
	int pa,pb;
	for(int i=0;i<n;i++)
	{
		pile[i].push_back(i);
		cout<<pile[i].size()<<' ';
		cout<<pile[i][0]<<endl;
	}
	for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
	{
	//	cout<<pile[i][j];
	}
	find_block(5,pa,pb);
	cout<<pa<<pb;
}
