#include <iostream>
#include <algorithm> // sort()
using namespace std;

int main()
{
	int arr[] = { 5,4,1,3,2 };
	int arrSize = sizeof(arr) / sizeof(arr[0]);
	cout << "arrSize : " << arrSize << endl;

	sort(arr, arr + arrSize);

	for (int element : arr)
	{
		cout << element << endl;
	}

	return 0;
}

/*
arrSize : 5
1
2
3
4
5
*/

#include <iostream>

using namespace std;

int main()
{
	// 크기 5인 고정 배열 선언
	int arr[5] = { 10, 20, 30, 40, 50 };

	for (int i = 0; i < 5; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	// 직접 값 변경
	arr[2] = 99;
	cout << "수정 후 arr[2] = " << arr[2] << endl;

	return 0;
}