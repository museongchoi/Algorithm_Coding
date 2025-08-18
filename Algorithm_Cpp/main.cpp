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
		// gap 은 간격 즉, 간격 양쪽에 있는 값을 비교하는 것.
		key = vec[i];
		j = i - gap;
		
		// gap 차이 만큼의 비교 대상 | 0 보다 크거나 같아야 한다 && key 값과 비교
		while (j >= 0 && vec[j] > key)
		{
			vec[j + gap] = vec[j];	// 더 큰 값들을 한 칸(=gap만큼) 뒤로 민다
			j -= gap;
		}
		// while 문을 빠져 나온다면 j값은 0보다 작거나 or vec[j] 가 key 값 보다 작은 값 이므로 더이상 교체가 안되는 것.
		// 그러므로 j idx 값을 다시 앞으로 밀어서 돌아온 뒤에 해당 위치에 보관되어 있던 key 값을 저장.
		vec[j + gap] = key; 
	}
}

void Shell_Sort(vector<int>& vec)
{
	int gap;

	for (gap = vec.size() / 2; gap > 0; gap /= 2)
	{
		// 삽입 정렬
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