#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	int NumMax = 0;
	for (int i = 1; i <= N; i++)
	{
		NumMax += i;
	}
	cout << NumMax;

	return 0;
}

// 수열 합 공식
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;

	cout << N * (N + 1) / 2;

	return 0;
}