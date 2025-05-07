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

// 선택 정렬
// 가장 작은 값을 찾고 맨 앞에서부터 차례대로 교환한다
void SelectionSort(vector<int> vec)
{
	int tmp, min_val, min_idx;

	for (int i = 0; i < vec.size(); i++)
	{
		// 초기화: 현재 인덱스를 최소값 인덱스로 설정
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
		// 찾은 최소값과 현재 값을 교환
		tmp = vec[min_idx];
		vec[min_idx] = vec[i];
		vec[i] = tmp;
	}

	Display(vec);
}

// 삽입 정렬
void InsertionSort_01(vector<int> vec)
{
	// tmp : 임시 저장 값. ? j : 마지막 진행 idx.
	int tmp, endidx;

	// InsertionSort_02 와 다르게 전역변수 T 를 사용하지 않고 vector 의 사이즈를 사용
	for (int i = 1; i < vec.size(); i++)
	{
		tmp = vec[i];

		// 앞에서부터 이동하며 앞에 값이 자신보다 크면 뒤로 미룬다
		// idx 1부터 시작 앞에 값을 비교 해야 하기 때문이다
		for (endidx = i - 1; endidx >= 0; endidx--)
		{
			// tmp 값과 비교하여 앞에 값이 크면 뒤로 미룬다
			if (tmp < vec[endidx])
			{
				vec[endidx + 1] = vec[endidx];
			}
			else
			{
				break;
			}
		}
		// for 문이 종료 된 시점에서 j 는 앞으로 한칸 이동한 상태.
		// tmp 의 위치를 가기 위해서는 마지막 최소값 위치로 가야한다. 그러므로 j + 1.
		vec[endidx + 1] = tmp;
	}
	Display(vec);
}

void InsertionSort_02(vector<int> vec)
{
	// tmp : 임시 저장 값. ? endidx : 마지막 진행 idx.
	int tmp, endidx;

	for (int i = 1; i < T; i++)
	{
		tmp = vec[i];
		for (endidx = i - 1; endidx >= 0 && tmp < vec[endidx]; endidx--)
		{
			vec[endidx + 1] = vec[endidx];
		}
		// for 문이 종료 된 시점에서 j 는 앞으로 한칸 이동한 상태.
		// tmp 의 위치를 가기 위해서는 마지막 최소값 위치로 가야한다. 그러므로 j + 1.
		vec[endidx + 1] = tmp;
	}
	Display(vec);
}

// 버블 정렬
// 차례대로 두개씩 비교하여 앞이 뒤보다 클 경우 교환
// 가장 큰 값은 맨 끝 자리에 가기에 매 반복마다 끝 자리는 다시 확인하지 않는다.
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