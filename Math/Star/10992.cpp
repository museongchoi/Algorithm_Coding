#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;
	
	// default : ���� ���� ��� �� �� ���ǿ� ���� ����
	for (int i = 0; i < n; i++)
	{
		// ���� ����
		for (int k = 0; k < n - 1 - i; k++)
		{
			cout << " ";
		}

		if (i == 0) // ù��° �� �� �ϳ�
		{
			cout << "*" << endl;
		}
		else if (i == n - 1) // ������ �� "*" �� ���
		{
			for (int k = 0; k < 2 * n - 1; k++)
			{
				cout << "*";
			}
		}
		else // �߰� �� + ���� + ��
		{
			cout << "*";
			for (int k = 0; k < 2 * i - 1; k++)
			{
				cout << " ";
			}
			cout << "*" << endl;
		}

	}
	return 0;
}