//queue 구현

#include <iostream>
#include <string>

using namespace std;

typedef int element;

class Node {
public:
	element data;
	Node* link;
};

class Queue {
private:
	Node* front;
	Node* rear;

public:
	Queue() {
		front = nullptr;
		rear = nullptr;
	}

	bool isEmpty()
	{
		if (front == nullptr)
		{
			return true;
		}
		return false;
	}

	// 삽입 | 추가
	void enqueue(element data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->link = nullptr;

		if (isEmpty())
		{
			front = newNode;
			rear = newNode;
		}
		else {
			rear->link = newNode;
			rear = newNode;
		}
	}

	// 삭제 | 제외
	void dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is empty, cannot dequeue. " << endl;
		}

		// q 가 비어있지 않다면 tmp 가 front 를 저장 -> front 위치 변경
		// front 를 front 가 가르키고 있던 노드로 변경 -> 기존 노드는 tmp 저장되어 있으므로 tmp 를 삭제
		Node* tmp = front;
		front = front->link;
		delete tmp;
	}

	// q의 맨 앞 data 확인
	element peek()
	{
		if (!isEmpty())
		{
			return front->data;
		}
		// q가 비어있다면 
		cout << "Queue is empty." << endl;
		return -1;
	}
};

int main()
{
	Queue q;

	// 1, 2, 3 추가 후 하나씩 제외
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);

	std::cout << "Front element: " << q.peek() << std::endl; // 1

	q.dequeue();
	std::cout << "Front element after dequeue: " << q.peek() << std::endl; // 2

	q.dequeue();
	std::cout << "Front element after dequeue: " << q.peek() << std::endl; // 3

	return 0;
}


// queue 라이브러리 사용
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	queue<int> q;

	// Enqueue 삽입
	q.push(1);
	q.push(2);
	q.push(3);

	// Dequeue 삭제 및 반환
	cout << "Front : " << q.front() << endl;
	q.pop();

	cout << "Front after pop : " << q.front() << endl;

	return 0;
}