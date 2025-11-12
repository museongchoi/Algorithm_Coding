// 5397
/*
* 테스트 케이스 L, 명령 문자열 st
* 명령어 '-', '<', '>' 각 명령 수행
* '-' : 커서 위치 바로 앞 글자 지우기
* '<', '<' : 커서의 움직임, 왼쪽/오른쪽으로 1 이동
*/

// list 풀이
#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int L;
	cin >> L;

	for (int i = 0; i < L; ++i)
	{
		string st;
		cin >> st;

		list<char> ListResult;
		auto cursor = ListResult.end();

		for (auto ch : st)
		{
			if (ch == '-')
			{
				if (cursor != ListResult.begin())
				{
					auto it = cursor;
					it--;
					cursor = ListResult.erase(it);
				}
			}
			else if (ch == '<')
			{
				if (cursor != ListResult.begin())
				{
					cursor--;
				}
			}
			else if (ch == '>')
			{
				if (cursor != ListResult.end())
				{
					cursor++;
				}
			}
			else
			{
				ListResult.insert(cursor, ch);
			}
		}

		for (char ch : ListResult)
		{
			cout << ch;
		}
		cout << "\n";
	}

	return 0;
}

// string 풀이
#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int L;
	cin >> L;

	for (int i = 0; i < L; ++i)
	{
		string st;
		cin >> st;

		string left, right;

		for (char ch : st)
		{
			if (ch == '-')
			{
				if (!left.empty())
				{
					left.pop_back();
				}
			}
			else if (ch == '<')
			{
				if (!left.empty())
				{
					right.push_back(left.back());
					left.pop_back();
				}
			}
			else if (ch == '>')
			{
				if (!right.empty())
				{
					left.push_back(right.back());
					right.pop_back();
				}
			}
			else
			{
				left.push_back(ch);
			}
		}

		cout << left;
		for (auto val = right.rbegin(); val != right.rend(); ++val)
		{
			cout << *val;
		}
		cout << "\n";
	}

	return 0;
}

//stack 사용
#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int L;
	cin >> L;

	for (int i = 0; i < L; ++i)
	{
		string st;
		cin >> st;

		stack<char> left;
		stack<char> right;

		for (char ch : st)
		{
			if (ch == '-')
			{
				if (!left.empty())
				{
					left.pop();
				}
			}
			else if (ch == '<')
			{
				if (!left.empty())
				{
					right.push(left.top());
					left.pop();
				}
			}
			else if (ch == '>')
			{
				if (!right.empty())
				{
					left.push(right.top());
					right.pop();
				}
			}
			else
			{
				left.push(ch);
			}
		}

		while (!left.empty())
		{
			right.push(left.top());
			left.pop();
		}

		while (!right.empty())
		{
			cout << right.top();
			right.pop();
		}

		cout << "\n";
	}

	return 0;
}