// ver.03
// stack<pair<int, int>> : height, idx
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// pair : height, idx
	stack<pair<int, int>> st;

	for (int i = 0; i < n; ++i)
	{
		int TowerNumber;
		cin >> TowerNumber;

		// 송신 타워는 자기보다 높은 첫번째 수신 타워에 신호를 보냄. 신호 방향은 왼쪽.
		while (!st.empty())
		{
			if (TowerNumber <= st.top().first)
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

		st.emplace(TowerNumber, i + 1);
	}

	return 0;
}

// ver.02
// 결과값 배열을 사용했지만 ver.01과 다르게 배열 초기화 값 + idx 위치를 이용
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> vec(n, 0);
	stack<pair<int, int>> st;

	for (int i = 0; i < n; ++i)
	{
		int TowerNumber;
		cin >> TowerNumber;

		// 송신 타워는 자기보다 높은 첫번째 송신 타워에 신호를 보냄. 신호 방향은 왼쪽.
		while (!st.empty())
		{
			if (TowerNumber > st.top().first)
			{
				st.pop();
			}
			else
			{
				break;
			}
		}

		// stack 이 비어있는데 top에 접근하게 되면 런타임 크래시가 일어나므로 주의.
		if (!st.empty())
		{
			// 송신 타워보다 수신 타워가 크다면 수신 타워 idx 를 저장.
			if (TowerNumber < st.top().first)
			{
				vec[i] = st.top().second;
			}
		}
		st.emplace(TowerNumber, i + 1);

	}

	for (int i = 0; i < n; ++i)
	{
		cout << vec[i] << " ";
	}

	return 0;
}

// ver.01
// vector, stack<pair<int, int>> | 출력 저장 배열 사용
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