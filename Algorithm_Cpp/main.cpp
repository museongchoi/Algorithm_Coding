#include <iostream>
#include <vector>
using namespace std;

void Display()
{

}

void insertionSort(vector<int>& vec)
{
	int key, keyidx;

	for (int i = 0; i < vec.size(); ++i)
	{
		key = vec[i];
		keyidx = i;
		
		for (int j = i - 1; j >= 0; --i)
		{
			if (key < vec[j])
			{
				vec[j+1] = vec[j];
				keyidx = j;
			}
			else
			{
				break;
			}
		}
		vec[keyidx] = key;
	}
}

void Shell_Sort(vector<int>& vec)
{
	int gap;

	for (gap = vec.size() / 2; gap > 0; gap /= 2)
	{
		if (gap / 2 == 0)
		{
			gap++;
		}
		// »ðÀÔ Á¤·Ä
		insertionSort(vec);
	}

}

int main()
{
	vector<int> vec = { 10, 8, 6, 20, 4, 3, 22, 1, 0, 15, 16 };


	Display();

	Shell_Sort(vec);
	return 0;
}