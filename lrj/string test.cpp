#include<iostream>
#include<algorithm>
#include<cstdio>
#include<vector>
#include<string>
#include<sstream>

using namespace std;
int main()
{	string line;
	while(getline (cin,line))   //����һ���� getline cin line 
	{
		int sum=0,x;
		stringstream pri(line);  //stringstream���� pri �Ĺ���ΪΪɨ����е�ÿһ�� �ַ� 
		while(pri>>x)			//���� pri  >>x  
		sum+=x;
		cout<<sum<<endl;
	}
	
	//string s;
	//cin>>s;
	//cout<<s;
string s;
stringstream ss;
int n, i, sum, a;
cin >> n;
getline(cin, s); // �xȡ�Q��
for (i=0; i<n; i++)
	{
    getline(cin, s);
    ss.clear();
    ss.str(s);
    sum=0;
    while (1)
    	{
       	ss >> a;
    	if ( ss.fail() ) break;
   	    sum+=a;
   		}
   	 cout << sum << endl;
	}

	return 0;
}
