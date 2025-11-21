// queue 구현
#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* link;
};

class Queue
{
private:
	Node* left;
	Node* right;
	int cnt;


public:
	Queue() : left(nullptr), right(nullptr), cnt(0) {}
	~Queue()
	{
		while (left != nullptr)
		{
			Node* tmp = left;
			left = left->link;
			delete tmp;
		}
		right = nullptr;
		cnt = 0;
	}

	void push(int element)
	{
		Node* newNode = new Node;
		newNode->data = element;
		newNode->link = nullptr;

		if (empty())
		{
			left = newNode;
			right = newNode;
		}
		else
		{
			right->link = newNode;
			right = newNode;
		}
		++cnt;
	}
	void pop()
	{
		if (empty())
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << left->data << "\n";

			Node* tmp = left;
			left = left->link;
			delete tmp;
			--cnt;

			if (left == nullptr)
			{
				right = nullptr;
			}
		}

	}
	void size() const
	{
		cout << cnt << "\n";
	}
	bool empty() const
	{
		return left == nullptr;
	}
	void front()
	{
		if (empty())
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << left->data << "\n";
		}
	}
	void back()
	{
		if (empty())
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << right->data << "\n";
		}
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	Queue que;

	for (int i = 0; i < n; ++i)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int val;
			cin >> val;
			que.push(val);
		}
		else if (cmd == "pop")
		{
			que.pop();
		}
		else if (cmd == "size")
		{
			que.size();
		}
		else if (cmd == "empty")
		{
			cout << que.empty() << "\n";
		}
		else if (cmd == "front")
		{
			que.front();
		}
		else if (cmd == "back")
		{
			que.back();
		}
	}

	return 0;
}

// include queue
#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	queue<int> que;

	for (int i = 0; i < n; ++i)
	{
		string cmd;
		cin >> cmd;

		if (cmd == "push")
		{
			int val;
			cin >> val;
			que.push(val);
		}
		else if (cmd == "pop")
		{
			if (que.empty())
			{
				cout << -1 << "\n";
			}
			else
			{
				cout << que.front() << "\n";
				que.pop();
			}
		}
		else if (cmd == "size")
		{
			cout << que.size() << "\n";
		}
		else if (cmd == "empty")
		{
			cout << que.empty() << "\n";
		}
		else if (cmd == "front")
		{
			if (!que.empty())
			{
				cout << que.front() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
		else if (cmd == "back")
		{
			if (!que.empty())
			{
				cout << que.back() << "\n";
			}
			else
			{
				cout << -1 << "\n";
			}
		}
	}

	return 0;
}