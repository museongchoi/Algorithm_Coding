// 배열 + 투 포인터(지점)
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000000];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int x;
	cin >> x;

	sort(arr, arr + n);

	int cnt = 0;
	int left = 0;
	int right = n - 1;

	while (left < right)
	{
		int sum = arr[left] + arr[right];
		if (sum == x)
		{
			cnt++;
			left++;
			right--;
		}
		else if (sum > x)
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	cout << cnt;

	return 0;
}

// 존재 배열
#include <iostream>
#include <algorithm>

using namespace std;

int arr[1000000];
bool check[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	int x;
	cin >> x;

	sort(arr, arr + n);

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		// 조건 : v + y == x
		int v = arr[i];    // 현재 비교해야하는 값 v
		int sum = x - v; // 합 x 에서 v 를 빼서 y 값을 구함

		// y 값이 배열에 존재한다면 한쌍 완성. 존재 유무를 arrcheck 배열 값으로 확인 하는 것.
		if (sum > 0 && sum <= 1000000 && check[sum])
		{
			++answer;
		}
		check[v] = true;
	}

	cout << answer;

	return 0;
}

// vector + 투 포인터
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	int x;
	cin >> x;

	sort(vec.begin(), vec.end());

	int cnt = 0;
	int left = 0;
	int right = n - 1;

	while (left < right)
	{
		int sum = vec[left] + vec[right];
		if (sum == x)
		{
			cnt++;
			left++;
			right--;
		}
		else if (sum > x)
		{
			right--;
		}
		else
		{
			left++;
		}
	}

	cout << cnt;

	return 0;
}

// 존재 배열 ver.vector 
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	const int MAXVal = 1000000;

	int n;
	cin >> n;

	vector<int> vec(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	int x;
	cin >> x;

	sort(vec.begin(), vec.end());

	int answer = 0;
	vector<char> check(MAXVal + 1, 0);

	for (int i = 0; i < n; ++i)
	{
		// 조건 : v + y == x
		int v = vec[i];    // 현재 비교해야하는 값 v
		int sum = x - v; // 합 x 에서 v 를 빼서 y 값을 구함

		// y 값이 배열에 존재한다면 한쌍 완성. 존재 유무를 arrcheck 배열 값으로 확인 하는 것.
		if (sum > 0 && sum <= MAXVal && check[sum])
		{
			++answer;
		}
		check[v] = 1;
	}

	cout << answer;

	return 0;
}