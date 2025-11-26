#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Display(const vector<int>& Vec)
{
	int n = Vec.size();
	for (int i = 0; i < n; i++)
	{
		cout << Vec[i] << " ";
	}
	cout << endl;
}

// 선택 정렬
// 가장 작은 값을 찾고 맨 앞에부터 차례대로 교환한다
void SelectionSort(vector<int>& Vec)
{
	int n = Vec.size();

	// 배열의 각 요소를 비교
	for (int i = 0; i < n - 1; ++i)
	{
		int MinIdx = i;

		// 현재 요소 i 를 기준으로 남은 배열에서 가장 작은 값을 찾는다.
		for (int j = i + 1; j < n; ++j)
		{
			if (Vec[MinIdx] > Vec[j])
			{
				MinIdx = j;
			}
		}

		// MinIdx 와 i 값이 같으면 발견하지 못한 것.
		if (MinIdx != i)
		{
			swap(Vec[i], Vec[MinIdx]);
		}
		Display(Vec);
	}
}

int main()
{
	vector<int> vec = { 5, 3, 8, 1, 2, 7 };

	Display(vec);
	cout << endl << "정렬 시작 : " << endl;

	SelectionSort(vec);

	cout << endl << "정렬 끝 : " << endl;

	Display(vec);

	return 0;
}

// 선택 정렬::수동 스왑
#include <iostream>
#include <vector>

using namespace std;

void Display(const vector<int>& vec)
{
	for (int v : vec)
	{
		cout << v << " ";
	}
	cout << "\n";
}

// 선택 정렬
// 가장 작은 값을 찾고 맨 앞에서부터 차례대로 교환한다
void SelectionSort(vector<int>& vec)
{
	int n = vec.size();

	for (int i = 0; i < n - 1; ++i)
	{
		// 초기화: 현재 인덱스를 최소값 인덱스로 설정
		int min_val = vec[i];
		int min_idx = i;

		// 가장 작은 값 탐색
		for (int j = i + 1; j < n; ++j)
		{
			if (min_val > vec[j])
			{
				min_val = vec[j];
				min_idx = j;
			}
		}

		// min_idx 와 i 값이 같다면 현재 값보다 작은 값을 찾지 못한 것. 즉, 스왑 발생하지 않음.
		if (min_idx != i)
		{
			// 찾은 최소값과 현재 값을 교환
			int tmp = vec[min_idx];
			vec[min_idx] = vec[i];
			vec[i] = tmp;
		}

		Display(vec);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	vector<int> vec(T);

	for (int i = 0; i < T; ++i)
	{
		cin >> vec[i];
	}

	cout << "정렬 전 : ";
	Display(vec);

	SelectionSort(vec);
	cout << "\n";

	return 0;
}