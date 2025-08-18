#include <iostream>
#include <vector>
using namespace std;

void Display(vector<int>& vec)
{
	for (int i = 0; i < vec.size(); ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

void insertionSort(vector<int>& vec, int gap)
{
	int key, j;

	for (int i = gap; i < vec.size(); ++i)
	{
		// gap �� ���� ��, ���� ���ʿ� �ִ� ���� ���ϴ� ��.
		key = vec[i];
		j = i - gap;
		
		// gap ���� ��ŭ�� �� ��� | 0 ���� ũ�ų� ���ƾ� �Ѵ� && key ���� ��
		while (j >= 0 && vec[j] > key)
		{
			vec[j + gap] = vec[j];	// �� ū ������ �� ĭ(=gap��ŭ) �ڷ� �δ�
			j -= gap;
		}
		// while ���� ���� ���´ٸ� j���� 0���� �۰ų� or vec[j] �� key �� ���� ���� �� �̹Ƿ� ���̻� ��ü�� �ȵǴ� ��.
		// �׷��Ƿ� j idx ���� �ٽ� ������ �о ���ƿ� �ڿ� �ش� ��ġ�� �����Ǿ� �ִ� key ���� ����.
		vec[j + gap] = key; 
	}
}

void Shell_Sort(vector<int>& vec)
{
	int gap;

	for (gap = vec.size() / 2; gap > 0; gap /= 2)
	{
		// ���� ����
		insertionSort(vec, gap);
	}
}

int main()
{
	vector<int> vec = { 10, 8, 6, 20, 4, 3, 22, 1, 0, 15, 16 };

	cout << "be" << endl;
	Display(vec);

	Shell_Sort(vec);

	cout << "af" << endl;
	Display(vec);
	return 0;
}