#include <iostream>
#include <vector>

using namespace std;

void Display(vector<int> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		cout << vec[i] << " ";
	}
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
	int T;
	cin >> T;
	
	vector<int> vec(T);

	for (int i = 0; i < T; i++)
	{
		cin >> vec[i];
	}

	BubbleSort(vec);
	cout << endl;

	return 0;
}