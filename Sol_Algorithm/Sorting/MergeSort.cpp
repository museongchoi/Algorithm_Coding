// MergeSort 01
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

// 두 개의 배열을 합병하는 함수
// 1. 두 개의 배열을 정렬하여 새로운 배열에 저장.
// 1-1. 두 개의 배열의 각 첫번째 요소부터 비교하여 새로운 배열 arr1에 저장.
// 2. 두 배열 중 하나라도 빈다면 남아있는 요소가 있는 배열을 찾고, 해당 배열에 남아있는 요소를 arr1에 저장
// 3. 정렬되어 저장된 새로운 배열 arr1 요소들을 원래 배열 arr에 저장. arr == arr1
void Merge(vector<int>& vec, int left, int mid, int right)
{
	vector<int> tmp;
	tmp.reserve(right - left + 1);

	int i = left;
	int j = mid + 1;

	// p 와 q 값을 비교하여 vecTemp 에 넣는다. | p, q 가 배열을 벗어나면 안된다.
	while (i <= mid && j <= right)
	{
		if (vec[i] <= vec[j])
		{
			tmp.push_back(vec[i]);
			i++;
		}
		else
		{
			tmp.push_back(vec[j]);
			j++;
		}
	}

	while (i <= mid)
	{
		tmp.push_back(vec[i]);
		++i;
	}
	while (j <= right)
	{
		tmp.push_back(vec[j]);
		++j;
	}

	for (int t = 0; t < tmp.size(); ++t)
	{
		vec[left + t] = tmp[t];
	}
}

// 재귀함수
// 배열의 길이가 1이 될때까지, 즉 하나의 요소만 가질때까지 나눈다.
// merge 함수를 사용하여 정렬한뒤 병합
void MergeSort(vector<int>& vec, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(vec, left, mid);
		MergeSort(vec, mid + 1, right);
		Merge(vec, left, mid, right);
	}
}

int main()
{
	vector<int> vec = { 27, 10, 12, 20, 25, 13, 15 };
	//int veclen = static_cast<int>(vec.size());
	int n = vec.size();

	Display(vec);

	MergeSort(vec, 0, n - 1);

	Display(vec);

	return 0;
}

// MergeSort 02
#include <iostream>
#include <vector>

using namespace std;

void Display(const vector<int>& vec)
{
	for (int n : vec)
	{
		cout << n << " ";
	}
	cout << "\n";
}

// 두 개의 배열을 합병하는 함수
// 1. 두 개의 배열을 정렬하여 새로운 배열에 저장.
// 1-1. 두 개의 배열의 각 첫번째 요소부터 비교하여 새로운 배열 arr1에 저장.
// 2. 두 배열 중 하나라도 빈다면 남아있는 요소가 있는 배열을 찾고, 해당 배열에 남아있는 요소를 arr1에 저장
// 3. 정렬되어 저장된 새로운 배열 arr1 요소들을 원래 배열 arr에 저장. arr == arr1
void Merge(vector<int>& vec, int left, int mid, int right)
{
	vector<int> vecTemp(vec.size());

	// left, mid, right 는 고정값
	// p : 왼쪽 리스트 idx | q : 오른쪽 리스트 idx | 
	int p, q, k;
	p = left;
	q = mid + 1;
	k = left;

	// p 와 q 값을 비교하여 vecTemp 에 넣는다. | p, q 가 배열을 벗어나면 안된다.
	while (p <= mid && q <= right)
	{
		if (vec[p] < vec[q])
		{
			vecTemp[k] = vec[p];
			++p;
		}
		else
		{
			vecTemp[k] = vec[q];
			++q;
		}
		++k;
	}

	if (p > mid)
	{
		for (int i = q; i <= right; ++i)
		{
			vecTemp[k] = vec[i];
			++k;
		}
	}
	else
	{
		for (int i = p; i <= mid; ++i)
		{
			vecTemp[k] = vec[i];
			++k;
		}
	}

	for (int i = left; i <= right; ++i)
	{
		vec[i] = vecTemp[i];
	}
}

// 재귀함수
// 배열의 길이가 1이 될때까지, 즉 하나의 요소만 가질때까지 나눈다.
// merge 함수를 사용하여 정렬한뒤 병합
void MergeSort(vector<int>& vec, int left, int right)
{
	int mid;

	if (left < right)
	{
		mid = (left + right) / 2;
		MergeSort(vec, left, mid);
		MergeSort(vec, mid + 1, right);
		Merge(vec, left, mid, right);
	}
}

int main()
{
	vector<int> vec = { 27, 10, 12, 20, 25, 13, 15 };
	int n = vec.size();

	Display(vec);

	MergeSort(vec, 0, n - 1);

	Display(vec);

	return 0;
}
