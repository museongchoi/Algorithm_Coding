// ShellSort 01
#include <iostream>
#include <vector>
using namespace std;

void Display(const vector<int>& vec)
{
	for (int n : vec)
	{
		cout << n << " ";
	}
	cout << "\n";
}

void Shell_Sort(vector<int>& vec)
{
	int gap = vec.size() / 2; // gap 은 간격 즉, 간격 양쪽에 있는 값을 비교하는 것.
	int i, j, tmp;
	int n = vec.size();

	while (gap > 0)
	{
		for (i = gap; i < n; ++i)
		{
			tmp = vec[i]; // 비교대상 A 값 저장
			j = i - gap;  // gap 차이 만큼의 비교대상 B 의 idx

			// vec[j]가 key 값보다 크다면 교환
			while (j >= 0 && vec[j] > tmp)
			{
				vec[j + gap] = vec[j];	// 더 큰 값 vec[j] 가 gap 만큼 오른쪽으로 이동.
				j -= gap; // j 값을 gap 차이만큼 이동. (다음 비교대상 B idx)
			}

			// key 삽입 위치 맞추기
			// while 종료 전 j의 위치가 이동됨. 즉, gap 크기만큼 다시 오른쪽 쉬프트 후 key 값을 저장.
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vec;

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		vec.push_back(n);
	}

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
	int n = vec.size();

	for (int i = gap; i < n; ++i)
	{
		// gap 은 간격 즉, 간격 양쪽에 있는 값을 비교하는 것.
		key = vec[i];
		j = i - gap; // gap 차이 만큼의 비교 대상 idx 선택

		while (j >= 0 && vec[j] > key)
		{
			vec[j + gap] = vec[j];	// vec[j] 값이 더 크다면 gap 만큼 오른쪽으로 이동.
			j -= gap; // 비교대상 idx 를 gap 만큼 이동.
		}

		// key 삽입 위치 맞추기
		// while 종료 전 j의 위치가 이동됨. 즉, gap 크기만큼 다시 오른쪽 쉬프트 후 key 값을 저장.
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
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vec;

	int t;
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n;
		cin >> n;
		vec.push_back(n);
	}

	cout << "be" << endl;
	Display(vec);

	Shell_Sort(vec);

	cout << "af" << endl;
	Display(vec);
	return 0;
}
