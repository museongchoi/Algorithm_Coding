#include <iostream>
#include <vector>

using namespace std;

int T;

void Display(vector<int> vec)
{
	for (int i = 0; i < T; i++)
	{
		cout << vec[i] << " ";
	}
}

// ���� ����
// ���� ���� ���� ã�� �� �տ������� ���ʴ�� ��ȯ�Ѵ�
void SelectionSort(vector<int> vec)
{
	int tmp, min_val, min_idx;

	for (int i = 0; i < vec.size(); i++)
	{
		// �ʱ�ȭ: ���� �ε����� �ּҰ� �ε����� ����
		min_val = vec[i];
		min_idx = i;

		for (int j = i + 1; j < vec.size(); j++)
		{
			if (min_val > vec[j])
			{
				min_val = vec[j];
				min_idx = j;
			}
		}
		// ã�� �ּҰ��� ���� ���� ��ȯ
		tmp = vec[min_idx];
		vec[min_idx] = vec[i];
		vec[i] = tmp;
	}

	Display(vec);
}

// ���� ����
void InsertionSort_01(vector<int> vec)
{
	// tmp : �ӽ� ���� ��. ? j : ������ ���� idx.
	int tmp, endidx;

	// InsertionSort_02 �� �ٸ��� �������� T �� ������� �ʰ� vector �� ����� ���
	for (int i = 1; i < vec.size(); i++)
	{
		tmp = vec[i];

		// �տ������� �̵��ϸ� �տ� ���� �ڽź��� ũ�� �ڷ� �̷��
		// idx 1���� ���� �տ� ���� �� �ؾ� �ϱ� �����̴�
		for (endidx = i - 1; endidx >= 0; endidx--)
		{
			// tmp ���� ���Ͽ� �տ� ���� ũ�� �ڷ� �̷��
			if (tmp < vec[endidx])
			{
				vec[endidx + 1] = vec[endidx];
			}
			else
			{
				break;
			}
		}
		// for ���� ���� �� �������� j �� ������ ��ĭ �̵��� ����.
		// tmp �� ��ġ�� ���� ���ؼ��� ������ �ּҰ� ��ġ�� �����Ѵ�. �׷��Ƿ� j + 1.
		vec[endidx + 1] = tmp;
	}
	Display(vec);
}

void InsertionSort_02(vector<int> vec)
{
	// tmp : �ӽ� ���� ��. ? endidx : ������ ���� idx.
	int tmp, endidx;

	for (int i = 1; i < T; i++)
	{
		tmp = vec[i];
		for (endidx = i - 1; endidx >= 0 && tmp < vec[endidx]; endidx--)
		{
			vec[endidx + 1] = vec[endidx];
		}
		// for ���� ���� �� �������� j �� ������ ��ĭ �̵��� ����.
		// tmp �� ��ġ�� ���� ���ؼ��� ������ �ּҰ� ��ġ�� �����Ѵ�. �׷��Ƿ� j + 1.
		vec[endidx + 1] = tmp;
	}
	Display(vec);
}

// ���� ����
// ���ʴ�� �ΰ��� ���Ͽ� ���� �ں��� Ŭ ��� ��ȯ
// ���� ū ���� �� �� �ڸ��� ���⿡ �� �ݺ����� �� �ڸ��� �ٽ� Ȯ������ �ʴ´�.
void BubbleSort(vector<int> vec)
{
	int loop_cnt = vec.size();
	int tmp = 0;

	while (loop_cnt != 1)
	{
		for (int i = 0; i < loop_cnt - 1; i++)
		{
			Display(vec);
			cout << " / ";

			if (vec[i] > vec[i + 1])
			{
				tmp = vec[i + 1];
				vec[i + 1] = vec[i];
				vec[i] = tmp;
			}
		}
		loop_cnt--;
	}
}

int main()
{
	cin >> T;

	vector<int> vec(T);

	for (int i = 0; i < T; i++)
	{
		cin >> vec[i];
	}

	SelectionSort(vec);
	cout << endl;

	InsertionSort_01(vec);
	cout << endl;

	InsertionSort_02(vec);
	cout << endl;

	BubbleSort(vec);
	cout << endl;

	return 0;
}