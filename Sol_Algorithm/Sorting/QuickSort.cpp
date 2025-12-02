#include <iostream>
#include <vector>

using namespace std;

void Display(const vector<int>& vec)
{
	for (int i : vec)
	{
		cout << i << " ";
	}

	cout << "\n";
}

int Partition(vector<int>& vec, int l, int r)
{
	int pivot = vec[l];
	int left = l + 1;
	int right = r;

	// low와 high가 서로 교차 하기 전까지 반복 
	while (left <= right)
	{
		// pivot 보다 가장 큰 값을 찾는다. vec[left] 값이 작을 경우 + left는 r 까지 움직인다
		while (left <= r && pivot > vec[left])
		{
			left++;
		}
		// pivot 보다 가장 작은 값을 찾는다. vec[right] 값이 클 경우 + right는 l 까지 움직인다
		while (right > l && pivot < vec[right])
		{
			right--;
		}
		if (left >= right)
		{
			break;
		}

		// 조건에 맞는 위치에 도달. 이후 left 와 right 를 바꿔준다
		swap(vec[left], vec[right]);
	}
	if (left >= right)
	{
		// left 와 right 가 교차 후 right로 표시, right와 p(피벗) 을 바꾸어준다
		swap(vec[l], vec[right]);
	}
	// p(피벗)을 반환
	return right;
}

void QuickSort(vector<int>& vec, int l, int r)
{
	int q;

	if (l < r)
	{
		Display(vec);
		q = Partition(vec, l, r);
		QuickSort(vec, l, q - 1);
		QuickSort(vec, q + 1, r);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vec = { 27, 10, 12, 20, 25, 13, 15 };
	int n = vec.size();

	Display(vec);

	QuickSort(vec, 0, n - 1);

	Display(vec);

	return 0;
}
