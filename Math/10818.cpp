#include <iostream>
using namespace std;

int main()
{
	//ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int minNum, maxNum;
	minNum = 1000000;
	maxNum = -1000000;

	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		if (tmp < minNum)
		{
			minNum = tmp;
		}
		if (tmp > maxNum)
		{
			maxNum = tmp;
		}
	}
	cout << minNum << " " << maxNum;

	return 0;
}

// std::sort(first, last)
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);

	int N;
	cin >> N;

	int* arr = new int[N];

	int tmp = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cout << arr[0] << " " << arr[N - 1];

	return 0;
}