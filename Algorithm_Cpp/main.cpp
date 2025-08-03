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