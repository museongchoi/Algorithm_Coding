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

// 숫자 배열의 모든 요소를 앞에서부터 차례대로 이미 정렬된 배열 부분과 비교하여, 
// 자신의 위치를 찾아 삽입함으로써 정렬을 완성하는 알고리즘

// for문 쉬프트 + 직접 대입 :: inxkey 값을 사용
void InsertionSort(vector<int>& Vec)
{
	int Key;
	int idxkey;

	for (int i = 1; i < Vec.size(); i++)
	{
		Key = Vec[i];
		idxkey = i;

		for (int j = i - 1; j >= 0; j--)
		{
			if (Key < Vec[j])
			{
				Vec[j + 1] = Vec[j];
				idxkey = j;
			}
			else
			{
				break;
			}
		}
		Vec[idxkey] = Key;
		Display(Vec);
	}
}

// while문 쉬프트 + 직접 대입 
void InsertionSort(vector<int>& Vec)
{
	int key;
	int j;

	for (int i = 1; i < Vec.size(); i++)
	{
		key = Vec[i];
		j = i - 1;

		while (j >= 0 && Vec[j] > key)
		{
			Display(Vec);
			Vec[j + 1] = Vec[j];
			j--;
		}
		Vec[j + 1] = key;

		cout << "패스 " << i << " 완료: ";
		Display(Vec);
	}
}

// swap() 만을 이용한 삽입 정렬 (Bubble-styled Insertion Sort)
void InsertionSort(vector<int>& Vec)
{
	int n = Vec.size();

	for (int i = 1; i < n; ++i)
	{
		for (int j = i; j > 0 && Vec[j] < Vec[j - 1]; --j)
		{
			swap(Vec[j], Vec[j - 1]);
			Display(Vec);
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