// include stack
#include <iostream>
#include <stack>
#include <string>

using namespace std;

enum Cmd
{
	push,
	pop,
	size,
	empty,
	top,
	unknown
};

static Cmd ToCmd(const string st)
{
	if (st == "push") return Cmd::push;
	if (st == "pop") return Cmd::pop;
	if (st == "size") return Cmd::size;
	if (st == "empty") return Cmd::empty;
	if (st == "top") return Cmd::top;
	return Cmd::unknown;
}

static void StartCmd(stack<int>& st, string& cmd, int num = -1)
{
	switch (ToCmd(cmd))
	{
	case Cmd::push:
		st.push(num);
		break;
	case Cmd::pop:
		if (st.empty())
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << st.top() << "\n";
			st.pop();
		}
		break;
	case Cmd::size:
		cout << st.size() << "\n";
		break;
	case Cmd::empty:
		cout << st.empty() << "\n";
		break;
	case Cmd::top:
		if (st.empty())
		{
			cout << -1 << "\n";
		}
		else
		{
			cout << st.top() << "\n";
		}
		break;
	default:
		break;
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	stack<int> st;

	for (int i = 0; i < n; ++i)
	{
		string cmd;
		cin >> cmd;

		int num = -1;
		if (cmd == "push")
		{
			cin >> num;
		}

		StartCmd(st, cmd, num);
	}

	return 0;
}

// stack 구현 (ver.2)
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* link;
};

struct Stack {
	Node* St;

	Stack() : St(nullptr) {}
	~Stack() { Clear(); }

	void Push(int value)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->link = St;

		St = newNode;
	}

	void Pop()
	{
		if (St == nullptr)
		{
			cout << -1 << "\n";
			return;
		}

		cout << St->data << "\n";

		Node* tmp = St;
		St = St->link;
		delete tmp;
	}

	void Size()
	{
		Node* cur = St;
		int cnt = 0;
		while (cur != nullptr)
		{
			++cnt;
			cur = cur->link;
		}

		cout << cnt << "\n";
	}

	bool Empty()
	{
		if (St == nullptr)
		{
			return 1;
		}
		return 0;
	}

	void Top()
	{
		if (Empty())
		{
			cout << -1 << "\n";
			return;
		}
		cout << St->data << "\n";
	}

	void Clear()
	{
		while (St)
		{
			Node* tmp = St;
			St = St->link;
			delete tmp;
		}
	}
};

enum Cmd
{
	push,
	pop,
	size,
	empty,
	top,
	unknown
};

Cmd ToCmd(string st)
{
	if (st == "push") return Cmd::push;
	if (st == "pop") return Cmd::pop;
	if (st == "size") return Cmd::size;
	if (st == "empty") return Cmd::empty;
	if (st == "top") return Cmd::top;
	return Cmd::unknown;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	Stack st;

	int n;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		string cmd;
		int val;

		cin >> cmd;

		switch (ToCmd(cmd))
		{
		case Cmd::push:
			cin >> val;
			st.Push(val);
			break;
		case Cmd::pop:
			st.Pop();
			break;
		case Cmd::size:
			st.Size();
			break;
		case Cmd::empty:
			cout << st.Empty() << "\n";
			break;
		case Cmd::top:
			st.Top();
			break;
		default:
			break;
		}
	}

	return 0;
}

// stack 구현 (ver.1)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Node
{
	int data;
	Node* link;
};

struct Stack
{
	Node* top;
	int cntNode = 0;

	Stack() : top(nullptr) {}
	~Stack() { clear(); }

	void push(int value)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->link = top;

		top = newNode;
		cntNode++;
	}

	void pop()
	{
		if (top == nullptr)
		{
			cout << -1 << "\n";
			return;
		}

		cntNode--;
		cout << top->data << "\n";

		Node* tmp = top;
		top = top->link;
		delete tmp;
	}

	void size()
	{
		cout << cntNode << "\n";
	}

	void empty() const
	{
		if (top == nullptr)
		{
			cout << 1 << "\n";
			return;
		}
		cout << 0 << "\n";
		return;
	}

	void topVal() const
	{
		if (top == nullptr)
		{
			cout << -1 << "\n";
			return;
		}
		cout << top->data << "\n";
	}

	void clear()
	{
		while (top)
		{
			Node* tmp = top;
			top = top->link;
			delete tmp;
		}
		cntNode = 0;
	}
};

enum Cmd
{
	push,
	pop,
	size,
	empty,
	top,
	unknown
};

Cmd ToCmd(string st)
{
	if (st == "push") return Cmd::push;
	if (st == "pop") return Cmd::pop;
	if (st == "size") return Cmd::size;
	if (st == "empty") return Cmd::empty;
	if (st == "top") return Cmd::top;
	return Cmd::unknown;
}

void cmdStart(vector<pair<string, int>>& vec, Stack& st)
{

	for (size_t i = 0; i < vec.size(); ++i)
	{
		Cmd c = ToCmd(vec[i].first);
		int val = vec[i].second;
		switch (c)
		{
		case Cmd::push:
			st.push(val);
			break;
		case Cmd::pop:
			st.pop();
			break;
		case Cmd::size:
			st.size();
			break;
		case Cmd::empty:
			st.empty();
			break;
		case Cmd::top:
			st.topVal();
			break;
		default:
			break;
		}
	}
}

int main()
{
	int N;
	cin >> N;

	vector<pair<string, int>> cmdVec;
	cmdVec.reserve(N);

	for (int i = 0; i < N; ++i)
	{
		string cmd;
		cin >> cmd;
		if (cmd == "push")
		{
			int num;
			cin >> num;

			cmdVec.push_back({ cmd, num });
			continue;
		}
		cmdVec.push_back({ cmd, -1 });
	}

	Stack st;
	cmdStart(cmdVec, st);

	return 0;
}