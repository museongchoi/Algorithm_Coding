#include <iostream>
#include <string>

using namespace std;

struct Node
{
	int data;
	Node* link;
};

class Que
{
protected:
	Node* first;
	Node* end;
	int cnt;

public:
	Que() : first(nullptr), end(nullptr), cnt(0) {}
	~Que() {}

	void push(int inData)
	{
		Node* newNode = new Node();
		newNode->data = inData;
		newNode->link = nullptr;

		if (Empty())
		{
			first = newNode;
			end = newNode;
		}
		else
		{
			end->link = newNode;
			end = newNode;
		}
		++cnt;
	}

	void pop()
	{
		if (Empty())
		{
			cout << -1 << "\n";
			return;
		}

		Node* tmpNode = first;
		first = first->link;
		cout << tmpNode->data << "\n";
		delete tmpNode;

		if (first == nullptr)
		{
			end = nullptr;
		}
		--cnt;
	}

	int Empty()
	{
		return first == nullptr;
	}

	void size()
	{
		cout << cnt << "\n";
	}

	void front()
	{
		if (Empty())
		{
			cout << -1 << "\n";
			return;
		}
		cout << first->data << "\n";
	}

	void back()
	{
		if (Empty())
		{
			cout << -1 << "\n";
			return;
		}
		cout << end->data << "\n";
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	Que que;

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
			cout << que.Empty() << "\n";
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
	Node* first;
	Node* end;
	int cnt;

public:
	Queue() : first(nullptr), end(nullptr), cnt(0) {}
	~Queue()
	{
		while (first != nullptr)
		{
			Node* tmp = first;
			first = first->link;
			delete tmp;
		}
		end = nullptr;
		cnt = 0;
	}

	void push(int element)
	{
		Node* newNode = new Node;
		newNode->data = element;
		newNode->link = nullptr;

		if (empty())
		{
			first = newNode;
			end = newNode;
		}
		else
		{
			end->link = newNode;
			end = newNode;
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
			cout << first->data << "\n";

			Node* tmp = first;
			first = first->link;
			delete tmp;
			--cnt;

			if (first == nullptr)
			{
				end = nullptr;
			}
		}
	}
	void size() const
	{
		cout << cnt << "\n";
	}
	bool empty() const
	{
		return first == nullptr;
	}
	void front()
	{
		if (first == nullptr)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << first->data << "\n";
		}
	}
	void back()
	{
		if (first == nullptr)
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << end->data << "\n";
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
			cout << (que.empty() ? 1 : 0) << "\n";
		}
		else if (cmd == "front")
		{
			if (que.empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.front() << "\n";
			}
		}
		else if (cmd == "back")
		{
			if (que.empty())
			{
				cout << "-1" << "\n";
			}
			else
			{
				cout << que.back() << "\n";
			}
		}
	}

	return 0;
}