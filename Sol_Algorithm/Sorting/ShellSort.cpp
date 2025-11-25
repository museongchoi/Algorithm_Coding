// ShellSort 01
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

void Shell_Sort(vector<int>& vec)
{
	int gap = vec.size() / 2; // gap 은 간격 즉, 간격 양쪽에 있는 값을 비교하는 것.
	int i, j, tmp;

	while (gap > 0)
	{
		for (i = gap; i < vec.size(); i++)
		{
			tmp = vec[i]; // 비교대상 A
			j = i - gap;  // gap 차이 만큼의 비교 대상 B 의 idx

			// j 가 0 보다 크거나 같아야 한다 && vec[j] 이 key 값보다 크다면
			while (j >= 0 && vec[j] > tmp)
			{
				vec[j + gap] = vec[j];	// 더 큰 값 vec[j] 가 gap 만큼 오른쪽으로 이동.
				j -= gap; // j 값을 gap 차이만큼 이동. (다음 비교 대상 idx)
			}

			// while 문을 빠져 나온다면 j값은 0보다 작거나 or vec[j] 가 key 값 보다 작은 값 이므로 더이상 교체가 안되는 것.
			// 그러므로 j + gap 즉, gap 크기만큼 다시 오른쪽으로 이동 후 key 값을 저장.
			vec[j + gap] = tmp;

			// 디버그 출력: 이번 단계의 결과
			cout << "  (gap=" << gap << ") i=" << i
				<< ", key=" << tmp << ", pos=" << (j + gap) << " : ";
			Display(vec);
		}
		gap /= 2;
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

// ShellSort 02
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
		j = i - gap; // gap 차이 만큼의 비교 대상 idx 선택

		// j 가 0 보다 크거나 같아야 한다 && vec[j] 이 key 값보다 크다면
		while (j >= 0 && vec[j] > key)
		{
			vec[j + gap] = vec[j];	// 더 큰 값 vec[j] 가 gap 만큼 오른쪽으로 이동.
			j -= gap; // j 값을 gap 차이만큼 이동.
		}

		// while 문을 빠져 나온다면 j값은 0보다 작거나 or vec[j] 가 key 값 보다 작은 값 이므로 더이상 교체가 안되는 것.
		// 그러므로 j + gap 즉, gap 크기만큼 다시 오른쪽으로 이동 후 key 값을 저장.
		vec[j + gap] = key;

		// 디버그 출력: 이번 단계의 결과
		cout << "  (gap=" << gap << ") i=" << i
			<< ", key=" << key << ", pos=" << (j + gap) << " : ";
		Display(vec);
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