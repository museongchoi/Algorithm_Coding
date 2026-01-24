// ver.2
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<char> result;
	stack<int> st;
	int val = 1;

	for (int i = 0; i < n; ++i)
	{
		int compareVal;
		cin >> compareVal;

		while (val <= compareVal)
		{
			st.push(val);
			val += 1;
			result.push_back('+');
		}

		if (st.top() == compareVal)
		{
			st.pop();
			result.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << "\n";
	}

	return 0;
}


// ver.1
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<int> vec(n);
	vector<char> result;
	stack<int> st;

	for (int i = 0; i < n; ++i)
	{
		cin >> vec[i];
	}

	int val = 1;

	for (int idx = 0; idx < n; ++idx)
	{
		while (val <= vec[idx])
		{
			st.push(val);
			val += 1;
			result.push_back('+');
		}

		if (st.top() == vec[idx])
		{
			st.pop();
			result.push_back('-');
		}
		else
		{
			cout << "NO";
			return 0;
		}
	}

	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << "\n";
	}

	return 0;
}