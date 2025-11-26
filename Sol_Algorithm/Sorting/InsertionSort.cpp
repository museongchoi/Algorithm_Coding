#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Display(const vector<int>& vec)
{
	int n = vec.size();
	for (int i = 0; i < n; ++i)
	{
		cout << vec[i] << " ";
	}
	cout << endl;
}

// 숫자 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여, 
// 자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘

// for문 쉬프트 + 직접 대입
void InsertionSort_ForShift(vector<int>& vec)
{
	int n = vec.size();

	for (int i = 1; i < n; ++i)
	{
		int Key = vec[i];
		int idxkey = i;

		for (int j = i - 1; j >= 0; --j)
		{
			if (vec[j] > Key)
			{
				vec[j + 1] = vec[j];
				idxkey = j;
			}
			else
			{
				break;
			}
		}
		vec[idxkey] = Key;
		Display(vec);
	}
}

// while문 쉬프트 + 직접 대입 
void InsertionSort_WhileShift(vector<int>& vec)
{
	int n = vec.size();

	for (int i = 1; i < n; ++i)
	{
		int key = vec[i];
		int j = i - 1;

		while (j >= 0 && vec[j] > key)
		{
			Display(vec);
			vec[j + 1] = vec[j];
			--j;
		}
		// while 문이 끝난 시점은 앞서 조건에 맞는 값을 찾고 --j 왼쪽으로 한 칸 이동한 상황이다.
		// 즉, 현재 j 값은 조건에 맞지 않으므로 while문이 종료된것이다.
		// 조건에 맞지 않으며 이미 왼쪽으로 한칸 이동했으니 j + 1로 삽입할 원래 위치로 맞춰준다.
		vec[j + 1] = key;

		cout << "패스 " << i << " 완료: ";
		Display(vec);
	}
}

// swap() 만을 이용한 삽입 정렬 (Bubble-styled Insertion Sort)
void InsertionSort(vector<int>& vec)
{
	int n = vec.size();

	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j > 0; --j)
		{
			if (vec[j] < vec[j - 1])
			{
				swap(vec[j], vec[j - 1]);
				Display(vec);
			}
			else
			{
				break;
			}
		}
	}
}

int main()
{
	vector<int> vec = { 5, 3, 8, 1, 2, 7 };

	Display(vec);
	cout << endl << "정렬 시작 : " << endl;

	// 단순 대입
	InsertionSort(vec);

	cout << endl << "정렬 끝 : " << endl;

	Display(vec);

	return 0;
}