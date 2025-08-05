#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	// default : 왼쪽 공백 출력 후 각 조건에 따라 진행
	for (int i = 0; i < n; i++)
	{
		// 왼쪽 공백
		for (int k = 0; k < n - 1 - i; k++)
		{
			cout << " ";
		}

		if (i == 0) // 첫번째 줄 별 하나
		{
			cout << "*" << endl;
		}
		else if (i == n - 1) // 마지막 줄 "*" 만 출력
		{
			for (int k = 0; k < 2 * n - 1; k++)
			{
				cout << "*";
			}
		}
		else // 중간 별 + 공백 + 별
		{
			cout << "*";
			for (int k = 0; k < 2 * i - 1; k++)
			{
				cout << " ";
			}
			cout << "*" << endl;
		}

	}
	return 0;
}