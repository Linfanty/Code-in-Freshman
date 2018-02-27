#include<stdio.h>
#include<string.h>
#include<vector>
#include<iostream>
//lower_bound
using namespace std;
int main()
{

vector<int>nums;
nums.push_back(-242);
nums.push_back(-1);
nums.push_back(0);
nums.push_back(5);
nums.push_back(8);
nums.push_back(8);
nums.push_back(11);
cout<<"Beforenumsis:";

for(unsigned int i=0;i<nums.size();i++)

{
cout<<nums[i]<<" ";
}
cout<<endl;

//vector<int>::iteratorresult;

int new_val=7;

//result=lower_bound(nums.begin(),nums.end(),new_val);

nums.insert(lower_bound(nums.begin(),nums.end(),new_val),new_val);//int new_val=7;

cout<<"After,numsis:";


for(unsigned int i=0;i<nums.size();i++)
{
cout<<nums[i]<<" ";
}

cout<<endl;
/*
Êä³ö£º
Before nums is: -242 -1 0 5 8 8 11
After, nums is: -242 -1 0 5 7 8 8 11
*/
}
