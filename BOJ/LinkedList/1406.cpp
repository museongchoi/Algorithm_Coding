// list
#include <iostream>
#include <string>
#include <list>
using namespace std;

int main()
{
	string st = "";
	cin >> st;

	list<char> li(st.begin(), st.end());

	int m;
	cin >> m;

	auto cursor = li.end();

	for (int i = 0; i < m; ++i)
	{
		char cmd;
		char val;
		cin >> cmd;

		if (cmd == 'L')
		{
			if (cursor != li.begin())
			{
				cursor--;
			}
		}
		else if (cmd == 'D')
		{
			if (cursor != li.end())
			{
				cursor++;
			}
		}
		else if (cmd == 'B')
		{
			if (cursor != li.begin())
			{
				cursor--;
				cursor = li.erase(cursor);
			}
		}
		else if (cmd == 'P')
		{
			cin >> val;
			li.insert(cursor, val);
		}
	}


	for (cursor = li.begin(); cursor != li.end(); cursor++)
	{
		cout << *cursor;
	}

	return 0;
}


// stack
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	string st = "";
	cin >> st;

	stack<char> stLeft;
	stack<char> stRight;

	for (int i = 0; i < (int)st.size(); ++i)
	{
		stLeft.push(st[i]);
	}

	int M;
	cin >> M;

	for (int i = 0; i < M; ++i)
	{
		char cmd;
		cin >> cmd;

		if (cmd == 'L')
		{
			if (!stLeft.empty())
			{
				stRight.push(stLeft.top());
				stLeft.pop();
			}
		}
		else if (cmd == 'D')
		{
			if (!stRight.empty())
			{
				stLeft.push(stRight.top());
				stRight.pop();
			}
		}
		else if (cmd == 'B')
		{
			if (!stLeft.empty())
			{
				stLeft.pop();
			}
		}
		else if (cmd == 'P')
		{
			char val;
			cin >> val;
			stLeft.push(val);
		}
	}

	while (!stLeft.empty())
	{
		stRight.push(stLeft.top());
		stLeft.pop();
	}

	while (!stRight.empty())
	{
		cout << stRight.top();
		stRight.pop();
	}

	return 0;
}