#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
	cin >> n;

	queue<int> que;
	int val;
	for (int i = 1; i <= n; ++i)
	{
		que.push(i);
	}

	while (1 < que.size())
	{
		que.pop();
		que.push(que.front());
		que.pop();
	}

	cout << que.front();

	return 0;
}