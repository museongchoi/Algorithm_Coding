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
void SelectionSort(vector<int> vec)
{
	int min, minidx = 0, swapnum = 0;

	for (int i = 0; i < T; i++)
	{
		min = 9999;

		for (int j = i; j < T; j++)
		{
			if (vec[j] < min)
			{
				min = vec[j];
				minidx = j;
			}
		}

		//swap
		swapnum = vec[minidx];
		vec[minidx] = vec[i];
		vec[i] = swapnum;
	}

	Display(vec);
}

// 삽입 정렬
void InsertionSort_01(vector<int> vec)
{
	// tmp : 임시 저장 값. ? j : 마지막 진행 idx.
	int tmp, endidx;

	for (int i = 1; i < T; i++)
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
	int t = T;
	int k = 0;

	while (t != 1)
	{
		for (int i = 0; i < t - 1; i++)
		{
			Display(vec);
			cout << " / ";

			if (vec[i] > vec[i + 1])
			{
				k = vec[i + 1];
				vec[i + 1] = vec[i];
				vec[i] = k;
			}
		}
		t--;
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