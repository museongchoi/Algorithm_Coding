#include <iostream>

using namespace std;

int main()
{
	// ũ�� 5�� ���� �迭 ����
	int arr[5] = { 10, 20, 30, 40, 50 };

	for (int i = 0; i < 5; i++)
	{
		cout << "arr[" << i << "] = " << arr[i] << endl;
	}

	// ���� �� ����
	arr[2] = 99;
	cout << "���� �� arr[2] = " << arr[2] << endl;

	return 0;
}