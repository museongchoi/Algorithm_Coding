// array, 직접 변경
#include <iostream>
#include <array>

using namespace std;

void Display(int Arr[], int ArrSize)
{
	for (int i = 0; i < ArrSize; i++)
	{
		cout << Arr[i] << " ";
	}
	cout << endl;
}

void BubbleSort(int Arr[], int ArrSize)
{
	int tmp = 0;
	bool Swaped;

	for (int pass = 0; pass < ArrSize - 1; pass++)
	{
		Swaped = false;
		for (int i = 0; i < ArrSize - 1; i++)
		{
			Display(Arr, ArrSize);

			if (Arr[i] > Arr[i + 1])
			{
				tmp = Arr[i];
				Arr[i] = Arr[i + 1];
				Arr[i + 1] = tmp;
			}
			Swaped = true;
		}
		if (!Swaped)
		{
			break;
		}
	}
}

int main()
{
	int arr[] = { 5, 3, 8, 1, 2, 7 };
	int arrSize = size(arr);

	cout << "정렬 시작 : " << endl;

	BubbleSort(arr, arrSize);

	cout << "정렬 끝 : " << endl;

	Display(arr, arrSize);

	return 0;
}

// vector, swap()
#include <iostream>
#include <vector>

using namespace std;

void Display(vector<int>& Vec)
{
	for (int i = 0; i < Vec.size(); i++)
	{
		cout << Vec[i] << " ";
	}
	cout << endl;
}

void BubbleSort(vector<int>& Vec)
{
	int tmp = 0;
	bool Swaped;
	int VecSize = Vec.size();

	for (int pass = 0; pass < VecSize - 1; pass++)
	{
		Swaped = false;
		for (int i = 0; i < VecSize - 1 - pass; i++)
		{
			Display(Vec);
			if (Vec[i] > Vec[i + 1])
			{
				swap(Vec[i], Vec[i + 1]);
				Swaped = true;

			}
		}
		if (!Swaped)
		{
			break;
		}
	}
}

int main()
{
	vector<int> vec = { 5, 3, 8, 1, 2, 7 };

	Display(vec);
	cout << endl << "정렬 시작 : " << endl;

	BubbleSort(vec);

	cout << endl << "정렬 끝 : " << endl;

	Display(vec);

	return 0;
}