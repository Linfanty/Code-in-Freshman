//F(n)=JI OU
#include <iostream>
using namespace std;
int main() {
    long long N;
    while(cin >> N)
    {
	long long result = 0;
    for (long long i = 1; i <= N; ++i) {
        int temp = i;
        while (temp % 2 == 0) {
            temp /= 2;
        }
        result += temp;
    }
    cout << result << endl;
	}
	return 0;
}
