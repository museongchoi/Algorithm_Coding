// 헤더 큐
#include <iostream>
#include <queue>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;

	queue<int> que;
	for (int i = 1; i <= n; ++i)
	{
		que.push(i);
	}

	cout << "<";
	int cnt = 0;
	int printed = 0;
	while (!que.empty())
	{
		cnt++;
		int val = que.front();
		que.pop();

		if (cnt % k == 0)
		{
			if (printed++)
			{
				cout << ", ";
			}
			cout << val;
		}
		else
		{
			que.push(val);
		}
	}
	cout << ">";

	return 0;
}


// que 구현
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* link;
};

class Queue
{
private:
	Node* front;
	Node* rear;

public:
	Queue() : front(nullptr), rear(nullptr) {}

	~Queue() {
		clear();
	}

	bool isEmpty()
	{
		if (front == nullptr)
		{
			return true;
		}
		return false;
	}

	void enqueue(int inData)
	{
		Node* newNode = new Node;
		newNode->data = inData;
		newNode->link = nullptr;

		if (isEmpty())
		{
			front = newNode;
			rear = newNode;
		}
		else
		{
			rear->link = newNode;
			rear = newNode;
		}

	}

	void dequeue()
	{
		if (isEmpty())
		{
			return;
		}
		Node* tmp = front;
		front = front->link;
		delete tmp;

		if (front == nullptr)
		{
			rear = nullptr;
		}
	}

	int peek()
	{
		if (isEmpty())
		{
			return -1;
		}

		return front->data;
	}

	void clear()
	{
		while (!isEmpty())
		{
			Node* tmp = front;
			front = front->link;
			delete tmp;
		}
	}

};

int main()
{
	int N;
	cin >> N;

	int K;
	cin >> K;

	Queue que;

	for (int i = 1; i <= N; ++i)
	{
		que.enqueue(i);
	}

	cout << "<";
	int cnt = 0;
	int value = 0;
	int printed = 0;
	while (!que.isEmpty())
	{
		cnt++;
		value = que.peek();
		que.dequeue();

		if (cnt == K)
		{
			if (printed++) cout << ", ";
			cout << value;
			cnt = 0;
		}
		else
		{
			que.enqueue(value);
		}
	}
	cout << ">";

	return 0;
}