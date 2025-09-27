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

	void push()
	{

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

void cmdStart(vector<pair<string, int>>* vec)
{
	int cmdsize = (int)vec->size();
	for (int i = 0; i < cmdsize; ++i)
	{
		const string& cmdStr = (*vec)[i].first;
		switch (ToCmd(vec->at(i).first))
		{
		case Cmd::push:

			break;
		case Cmd::pop:
			break;
		case Cmd::size:
			break;
		case Cmd::empty:
			break;
		case Cmd::top:
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
	Stack* stack = nullptr;

	string st;

	for (int i = 0; i < N; ++i)
	{
		cin >> st;
		if (st == "push")
		{
			int num;
			cin >> num;

			cmdVec.push_back({ st, num });
			continue;
		}
		cmdVec.push_back({ st, -1 });
	}

	cmdStart(&cmdVec);

	return 0;
}