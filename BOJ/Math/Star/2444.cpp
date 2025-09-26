#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	int total = 2 * n - 1; // �� �� ��

	for (int i = 1; i <= total; ++i) // i�� 1���� ����
	{
		int m = (i <= n) ? (i - 1) : (2 * n - 1 - i); // 1~n ������ i-1, �� ���Ĵ� ��Ī
		int spaces = (n - 1) - m;                 // ���� ���� ����
		int stars = 2 * m + 1;                    // �� ����(�׻� Ȧ��)

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

// for ���� �ʱⰪ 0
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