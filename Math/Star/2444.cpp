#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int total = 2 * n - 1; // 총 줄 수

	for (int i = 1; i <= total; ++i) // i를 1부터 시작
	{
		int m = (i <= n) ? (i - 1) : (2 * n - 1 - i); // 1~n 구간은 i-1, 그 이후는 대칭
		int spaces = (n - 1) - m;                 // 왼쪽 공백 개수
		int stars = 2 * m + 1;                    // 별 개수(항상 홀수)

		for (int s = 0; s < spaces; ++s)
		{
			cout << ' ';
		}
		for (int a = 0; a < stars; ++a)
		{
			cout << '*';
		}
		cout << '\n';
	}

	return 0;
}

// for 루프 초기값 0
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;


	for (int i = 0; i < 2 * N - 1; ++i)
	{
		if (i < N - 1)
		{
			for (int j = 0; j < N - 1 - i; ++j)
			{
				cout << " ";
			}
			for (int k = 0; k < 2 * i + 1; ++k)
			{
				cout << "*";
			}
		}
		else
		{
			for (int j = 0; j < i - (N - 1); ++j)
			{
				cout << " ";
			}
			for (int k = 0; k < 2 * ((2 * N - 1) - i) - 1; ++k)
			{
				cout << "*";
			}
		}
		cout << endl;
	}

	return 0;
}