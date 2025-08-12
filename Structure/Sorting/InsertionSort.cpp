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

// ���� �迭�� ��� ��Ҹ� �տ������� ���ʴ�� �̹� ���ĵ� �迭 �κа� ���Ͽ�, 
// �ڽ��� ��ġ�� ã�� ���������ν� ������ �ϼ��ϴ� �˰���

// for�� ����Ʈ + ���� ���� :: inxkey ���� ���
void InsertionSort(vector<int>& Vec)
{
	int Key;
	int idxkey;

	for (int i = 1; i < Vec.size(); i++)
	{
		Key = Vec[i];
		idxkey = i;

		for (int j = i - 1; j >= 0; j--)
		{
			if (Key < Vec[j])
			{
				Vec[j + 1] = Vec[j];
				idxkey = j;
			}
			else
			{
				break;
			}
		}
		Vec[idxkey] = Key;
		Display(Vec);
	}
}

// while�� ����Ʈ + ���� ���� 
void InsertionSort(vector<int>& Vec)
{
	int key;
	int j;

	for (int i = 1; i < Vec.size(); i++)
	{
		key = Vec[i];
		j = i - 1;

		while (j >= 0 && Vec[j] > key)
		{
			Display(Vec);
			Vec[j + 1] = Vec[j];
			j--;
		}
		Vec[j + 1] = key;

		cout << "�н� " << i << " �Ϸ�: ";
		Display(Vec);
	}
}

// swap() ���� �̿��� ���� ���� (Bubble-styled Insertion Sort)
void InsertionSort(vector<int>& Vec)
{
	int n = Vec.size();

	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j > 0 && Vec[j] < Vec[j - 1]; --j)
		{
			swap(Vec[j], Vec[j - 1]);
			Display(Vec);
		}
	}
}

int main()
{
	vector<int> vec = { 5, 3, 8, 1, 2, 7 };

	Display(vec);
	cout << endl << "���� ���� : " << endl;

	// �ܼ� ����
	InsertionSort(vec);

	cout << endl << "���� �� : " << endl;

	Display(vec);

	return 0;
}