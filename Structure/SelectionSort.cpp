#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Display(vector<int>& Vec)
{
	for (int i = 0; i < Vec.size(); i++)
	{
		cout << Vec[i] << " ";
	}
	cout << endl;
}

// 선택 정렬
// 가장 작은 값을 찾고 맨 앞에부터 차례대로 교환한다
void SelectionSort(vector<int>& Vec)
{
	int tmp, MinVal, MinIdx;
	
	// 배열의 각 요소를 비교
	for (int i = 0; i < Vec.size(); i++)
	{
		MinIdx = i;

		// 현재 요소 i 를 기준으로 남은 배열에서 가장 작은 값을 찾는다.
		for (int j = i + 1; j < Vec.size(); j++)
		{
			if (Vec[MinIdx] > Vec[j])
			{
				MinIdx = j;
			}
		}
		swap(Vec[i], Vec[MinIdx]);
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