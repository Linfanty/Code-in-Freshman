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
                break;//����
        }
        n = n % (i-2);
		// ��n��������ģ����n = i-2ʱ, n=0,��ʱ����Ӧ��ȡarr[i-2]�ģ����԰�arr[0]=arr[i-2]
		if(n==0)	 n=i-2;
		//arr[0] = arr[i-2];
		cout << arr[n] << endl;
	}
	return 0;
}
