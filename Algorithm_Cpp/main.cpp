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

		tmp = vec[min_idx];
		vec[min_idx] = vec[i];
		vec[i] = tmp;
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

	BubbleSort(vec);
	cout << endl;

	return 0;
}