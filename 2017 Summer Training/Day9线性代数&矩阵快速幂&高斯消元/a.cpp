#include <iostream>
using namespace std;

int arr[10000];

int main()
{
	int A,B,n,i;
	arr[1] = arr[2] = 1;


	while(cin>>A>>B>>n, A || B || n)
	{

        for(i=3; i<10000 ;i++)
        {
            arr[i] = (A*arr[i-1] + B*arr[i-2]) % 7;
            if(arr[i] == 1 && arr[i-1] == 1)
                break;//周期
        }
        n = n % (i-2);
		// 把n对周期求模，当n = i-2时, n=0,此时本来应该取arr[i-2]的，所以把arr[0]=arr[i-2]
		if(n==0)	 n=i-2;
		//arr[0] = arr[i-2];
		cout << arr[n] << endl;
	}
	return 0;
}
