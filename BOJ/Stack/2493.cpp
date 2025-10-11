// vector : 출력 값 저장 | stack<pair<int, int>> : height, idx
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	vector<int> vec(n, 0);
	stack<pair<int, int>> st;
	int value;

	for (int i = 0; i < n; ++i)
	{
		cin >> value;

		while (!st.empty())
		{
			if (st.top().first < value)
			{
				st.pop();
			}
			else
			{
				break;
			}
		}

		if (!st.empty())
		{
			vec[i] = st.top().second;
		}
		else
		{
			vec[i] = 0;
		}

		st.push({ value, i + 1 });
	}

	for (int i = 0; i < n; ++i)
	{
		cout << vec[i] << " ";

	}

	return 0;
}


// stack<pair<int, int>> : height, idx
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n;
	cin >> n;

	// pair : height, idx
	stack<pair<int, int>> st;
	int value;

	for (int i = 0; i < n; ++i)
	{
		cin >> value;

		while (!st.empty())
		{
			if (st.top().first >= value)
			{
				cout << st.top().second << " ";
				break;
			}
			st.pop();
		}

		if (st.empty())
		{
			cout << 0 << " ";
		}

		st.push({ value, i + 1 });
	}

	return 0;
}