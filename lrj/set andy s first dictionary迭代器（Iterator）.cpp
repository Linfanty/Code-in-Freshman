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
    /*set<string>::iterator
    ��������Iterator��ģʽ��
	�ֽ����α꣨Cursor��ģʽ��
	GOF�����Ķ���Ϊ����
	��һ�ַ�������һ��������container�������и���Ԫ�أ�
	���ֲ��豩¶�ö�����ڲ�ϸ�ڡ� �Ӷ���ɼ���������ģʽ��Ϊ����������
	�����ԣ�����������ķ��ʱ�Ȼ�漰�������㷨��
	�����һ���ԵĽ�����������������������ȥ��
	���߸�����ȥ�ṩʲô�����㷨����
	ʹ�����������Լ�ȥʵ��ȥ�ɡ���������������ܹ�������⡣
	*/
    for(set<string>::iterator it=dict.begin(); it!=dict.end(); ++it)
        cout<<*it<<"\n";
	
	/*	for(int i=dict.begin(); i!=dict.end(); ++i)
		cout<<i<<"\n";
		*/
    return 0;
}

