#include<iostream>
#include<cmath>
using namespace std;

bool Isleapyear(int n)
{
	if(n%400==0||((n%4==0)&&(n%100!=0)))
		return true;
	else 
		return false;
}

int main()
{
	int t;
	int y,n,m;
	cin>>t;
	while(t--)
	{
		m=0;
		cin>>y>>n;
		if(Isleapyear(y))
			m=1;
		else
			m=0;
		if(m==0)
		{
			for(int i=1;i<=100;i++)
			{
				if(Isleapyear(y+i))
				{
					y=y+i;
					m=1;
					break;
				}
			}
		}

		for(m;m<n;)
		{
			y+=4;
			if(Isleapyear(y))
				m+=1;
		}
		cout<<y<<endl;
	}
	return 0;
}

