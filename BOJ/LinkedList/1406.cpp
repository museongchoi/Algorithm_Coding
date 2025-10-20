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