// 배열 사용
#include <iostream>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string st;
	cin >> st;

	int arr[26] = { 0, };

	for (char ch : st)
	{
		arr[ch - 'a'] += 1;
	}

	for (int i : arr)
	{
		cout << i << " ";
	}

	return 0;
}

// algorithm::count 풀이
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string st;
	cin >> st;

	for (int i = 'a'; i <= 'z'; ++i)
	{
		cout << count(st.begin(), st.end(), i) << " ";
	}

	return 0;
}