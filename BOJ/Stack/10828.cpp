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