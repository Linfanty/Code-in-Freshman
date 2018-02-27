#include<string>
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	//char a[10][33];
	while(n--)
	{	
		string s;
		cin>>s;
		string str2=s.substr(0,8); 
		//s[0],s[7]
		cout<<str2<<endl;
		long long int a;
		
		//string->double
 	    //double d=atof(s.c_str());
 	    //long num = atol(str2);
 	    long b = atoi(str2.c_str());  
		//long long int oct=str2.to
		cout<<dec<<b<<endl;
		
	}
}
