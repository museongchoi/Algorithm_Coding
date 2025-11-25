// 아스키 코드 풀이
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, C;
	cin >> A >> B >> C;
	int Total = A * B * C;

	string Value = to_string(Total);
	int arr[10] = { 0, };

	for (char ch : Value)
	{
		arr[ch - '0'] += 1;
	}

	for (int i : arr)
	{
		cout << i << "\n";
	}

	return 0;
}

// 산술 연산자 풀이
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int A, B, C;
	cin >> A >> B >> C;
	int Total = A * B * C;

	int arr[10] = { 0, };

	while (Total > 0)
	{
		arr[Total % 10] += 1;
		Total = Total / 10;
	}

	for (int i : arr)
	{
		cout << i << "\n";
	}

	return 0;
}