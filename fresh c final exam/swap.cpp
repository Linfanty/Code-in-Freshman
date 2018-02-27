#include<cstdio>
#include<iostream>
//#include<algorithm>
//#include<string>
using namespace std;
void swap2(int& a,int& b)
{
		cout<<&a<<' '<<&b<<endl;
		cout<<a<<' '<<b<<endl;
	int t;
	t=a;a=b;b=t;
		cout<<&a<<' '<<&b<<endl;
		cout<<a<<' '<<b<<endl<<endl;
}

int main()
{
	int a=3,b=4;
	cout<<&a<<' '<<&b<<endl;
	cout<<a<<' '<<b<<endl;
	swap2(a,b);
	cout<<&a<<' '<<&b<<endl;
	cout<<a<<' '<<b<<endl;
}
