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