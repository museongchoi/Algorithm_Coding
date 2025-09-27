// stack 구현
#include <iostream>

using namespace std;
typedef int element;

class Node {
public:
	element data;
	Node* link;
};

class Stack {

private:
	Node* top;

public:
	Stack() : top(nullptr) {}

	// 얕은 복사 금지(이중 delete / 댕글링 포인터 방지) | 필요 없으면 지워도 됨
	Stack(const Stack&) = delete;
	Stack& operator=(const Stack&) = delete;

	~Stack() {
		clear();
	}

	// bool isEmpty() const { return top == nullptr; }
	bool isEmpty() const
	{
		if (top == nullptr)
		{
			return true;
		}
		return false;
	}

	void push(element data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->link = top;

		top = newNode;
	}

	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack is empty, cannot pop" << endl;
			return;
		}

		Node* temp = top;
		top = top->link;
		delete temp;

	}

	element peek() const
	{
		if (isEmpty())
		{
			cout << "Stack is empty, not data" << endl;
			return -1; // 호출부에서 -1 처리 주의
		}
		else {
			return top->data;
		}
	}

	void clear()
	{
		while (!isEmpty())
		{
			Node* temp = top;
			top = top->link;
			delete temp;
		}
	}

};

int main()
{
	Stack s;

	s.push(1);
	s.push(2);
	s.push(3);

	cout << "Stack top data : " << s.peek() << endl;
	s.pop();
	cout << "pop after Stack top data" << s.peek() << endl;

	// s.clear();  // 명시적 정리도 가능
	return 0;
}



// stack 라이브러리 사용
#include <iostream>
#include <stack>

using namespace std;

int main()
{
	stack<int> st01;
	stack<int> st02;

	st01.push(1);
	st01.push(2);
	st01.push(3);

	st02.push(10);
	st02.push(20);
	st02.push(30);

	swap(st01, st02);

	while (!st01.empty())
	{
		cout << st01.top() << endl;
		st01.pop();
	}

	return 0;
}