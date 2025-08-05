#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		// 왼쪽 공백
		for (int k = 0; k < n - 1 - i; k++)
		{
			cout << " ";
		}
		// 별 출력 후 공백 + 별로 idx 에 맞게 출력
		cout << "*";
		for (int k = 0; k < i; k++)
		{
			cout << " " << "*";
		}
		cout << endl;

	}
	return 0;
}