#include <iostream>

using namespace std;

typedef int element;

class Node {
public:
	element data;
	Node* prev;
	Node* next;
};

class Deque {
private:
	Node* front;
	Node* back;

public:
	Deque() : front(nullptr), back(nullptr) {}

	// 얕은 복사 금지 (이중 delete/댕글링 방지)
	Deque(const Deque&) = delete;
	Deque& operator=(const Deque&) = delete;

	~Deque()
	{
		clear();
	}

	bool isEmpty() const
	{
		return front == nullptr;
	}

	// 앞 쪽 삽입
	void push_front(element data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->prev = nullptr;
		newNode->next = front; // front가 nullptr(빈 덱)이든, 기존 첫 노드 주소든 그대로 연결
		// 빈 덱이면 newNode->next == nullptr 이 된다.

		if (isEmpty())
		{
			front = newNode;
			back = newNode;
		}
		else {
			// 현재 front 는 첫번째 노드 주소를 가지고 있다. 내 앞에 삽입되는 노드 prev 연결 후, front 이동(주소 변경)
			front->prev = newNode;
			front = newNode;
		}
	}

	// 뒤 쪽 삽입
	void push_back(element data)
	{
		Node* newNode = new Node;
		newNode->data = data;
		newNode->prev = back;
		newNode->next = nullptr;

		if (isEmpty())
		{
			front = newNode;
			back = newNode;
		}
		else {
			back->next = newNode;
			back = newNode;
		}
	}

	// 맨 앞 요소 삭제 (+ 선택적 삭제)
	bool pop_front(element* out = nullptr)
	{
		if (isEmpty())
		{
			cout << "Deque is Empty, cannot pop_front" << endl;
			return false;
		}

		Node* tmp = front;
		// out == nullptr 이면 false | out != nullptr 이면 true 즉, pop() 한 값을 받고 싶다.
		if (out)
		{
			// 역참조로 값의 주소를 넘기는 이유 : out = &tmp->data 즉, 값의 주소를 넘겨버린다면 delete tmp 가 되었을때 t->data 메모리는 해제 되기 때문이다. 
			*out = tmp->data;
		}

		front = front->next;
		/* front 가 존재하는것을 확인.
		front = front->next 를 진행 했을때 단일 노드였다면 이미 prev, next 가 nullptr 를 가르키고 있다.
		이후 front->prev = nullptr 을 진행한다면 널 역참조(크래시)가 일어나기 때문에 if 문으로 검사한다.
		*/
		if (front)
		{
			front->prev = nullptr;
		}
		else
		{
			back = nullptr;
		}

		delete tmp;
		return true;
	}

	// 맨 마지막 요소 삭제 (+선택적 삭제)
	bool pop_back(element* out = nullptr)
	{
		if (isEmpty())
		{
			cout << "Deque is Empty, cannot pop_back" << endl;
			return false;
		}

		Node* tmp = back;
		if (out)
		{
			*out = back->data;
		}

		back = back->prev;
		if (back)
		{
			back->next = nullptr;
		}
		else
		{
			front = nullptr;
		}
		delete tmp;
		return true;
	}

	// 맨 앞 요소 조회 (삭제 없음)
	bool peek_front(element& out) const
	{
		if (isEmpty())
		{
			cout << "Deque is empty, no front" << endl;
			return false;
		}
		// 삭제가 없으니 주소는 존재하기 때문에 
		out = front->data;
		return true;
	}

	// 맨 마지막 요소 조회 (삭제 없음)
	bool peek_back(element& out) const
	{
		if (isEmpty())
		{
			cout << "Deque is empty, no back" << endl;
			return false;
		}
		out = back->data;
		return true;
	}

	// 전부 비우기
	void clear()
	{
		while (!isEmpty())
		{
			Node* tmp = front;
			front = front->next;
			delete tmp;
		}
		back = nullptr;
	}
};

int main()
{
	Deque dq;

	// 뒤쪽 삽입
	dq.push_back(10);
	dq.push_back(20);

	// 앞쪽 삽입
	dq.push_front(1);
	dq.push_front(2);

	element v;

	// 앞/뒤 조회
	cout << "앞/뒤 조회 : " << endl;
	if (dq.peek_front(v)) cout << "front: " << v << "\n"; // 2
	if (dq.peek_back(v))  cout << "back: " << v << "\n"; // 20

	// 앞/뒤 삭제
	cout << "앞/뒤 삭제 : " << endl;
	dq.pop_front(&v); cout << "pop_front: " << v << "\n"; // 2
	dq.pop_back(&v);  cout << "pop_back: " << v << "\n"; // 20

	// 남은 것 출력(앞에서부터)
	cout << "남은 것 출력(앞에서부터) : " << endl;
	while (dq.pop_front(&v)) {
		cout << "pop_front: " << v << "\n"; // 1, 10
	}

	return 0;
}