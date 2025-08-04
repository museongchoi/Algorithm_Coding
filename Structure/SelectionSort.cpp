#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Display(vector<int>& Vec)
{
	for (int i = 0; i < Vec.size(); i++)
	{
		cout << Vec[i] << " ";
	}
	cout << endl;
}

// ���� ����
// ���� ���� ���� ã�� �� �տ����� ���ʴ�� ��ȯ�Ѵ�
void SelectionSort(vector<int>& Vec)
{
	int tmp, MinVal, MinIdx;
	
	// �迭�� �� ��Ҹ� ��
	for (int i = 0; i < Vec.size(); i++)
	{
		MinIdx = i;

		// ���� ��� i �� �������� ���� �迭���� ���� ���� ���� ã�´�.
		for (int j = i + 1; j < Vec.size(); j++)
		{
			if (Vec[MinIdx] > Vec[j])
			{
				MinIdx = j;
			}
		}
		swap(Vec[i], Vec[MinIdx]);
		Display(Vec);
	}
}

int main()
{
	vector<int> vec = { 5, 3, 8, 1, 2, 7 };

	Display(vec);
	cout << endl << "���� ���� : " << endl;
	
	SelectionSort(vec);

	cout << endl << "���� �� : " << endl;
	
	Display(vec);

	return 0;
}