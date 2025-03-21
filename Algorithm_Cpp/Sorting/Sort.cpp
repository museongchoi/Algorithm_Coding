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
void InsertionSort(vector<int> vec)
{
	int k, j;
	for (int i = 1; i < T; i++)
	{
		k = vec[i];

		// 앞에서부터 이동하며 앞에 값이 자신보다 크면 뒤로 미룬다
		// idx 1부터 시작 앞에 값을 비교 해야 하기 때문이다
		for (j = i - 1; j >= 0; j--) // for (j = i - 1; j >= 0 && k < arr[j]; j--)
		{
			// k 값과 비교하여 앞에 값이 크면 뒤로 미룬다
			if (k < vec[j])
			{
				vec[j + 1] = vec[j];
			}
			else
			{
				break;
			}

		}

		// j 는 위 for 문을 빠져 나오기 위해 앞으로 한번 이동 한 상태이다.
		// 이때 vec[j] 에 있는 값은 for 문의 조건에 의해 이미 작은값이므로 +1 하여 알맞은 자리에 k 를 저장.
		vec[j + 1] = k;
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

	InsertionSort(vec);
	cout << endl;

	BubbleSort(vec);
	cout << endl;

	return 0;
}