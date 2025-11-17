// 카운트를 하는 도중
// idx 6과 9에 있는 카운팅 값을 비교하여 작은 값을 올린다.
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
	int Number;
	cin >> Number;

	array<int, 10> arr = { 0, };

	while (Number > 0)
	{
		if (Number % 10 == 6)
		{
			arr[Number % 10] > arr[9] ? arr[9]++ : arr[Number % 10]++;
		}
		else if (Number % 10 == 9)
		{
			arr[Number % 10] > arr[6] ? arr[6]++ : arr[Number % 10]++;
		}
		else
		{
			arr[Number % 10] += 1;
		}
		Number = Number / 10;
	}

	cout << *max_element(arr.begin(), arr.end());

	return 0;
}

// 카운트 후
/*
* 전체 카운트 완료 후, 배열 안에 idx 6, 9의 있는 카운팅 값을 합하여 2로 나눈다.
* 나머지가 0이면 몫으로 배열 idx 6, 9 세트 수 세팅
* 나머지가 1이면 몫을 1 올려서 배열 idx 6, 9 세트 수 세팅
*/
#include <iostream>
#include <algorithm>
#include <array>

using namespace std;

int main()
{
	int Number;
	cin >> Number;

	array<int, 10> arr = { 0, };

	while (Number > 0)
	{
		arr[Number % 10] += 1;
		Number = Number / 10;
	}

	int element = (arr[6] + arr[9]) % 2;
	int Key = (arr[6] + arr[9]) / 2;
	if (element == 0)
	{
		arr[6] = Key;
		arr[9] = Key;
	}
	else
	{
		Key++;
		arr[6] = Key;
		arr[9] = Key;
	}

	cout << *max_element(arr.begin(), arr.end());

	return 0;
}