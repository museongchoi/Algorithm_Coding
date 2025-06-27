#include <iostream>
using namespace std;

struct Node {
	int data;	// 저장할 값
	Node* link;	// 다음 노드 포인터
	Node(int v, Node* nxt = nullptr) 
		: data(v), link(nxt) {}
};

/*  
	노드 삽입 : head 포인터를 참조로 받아 수정
	p == nullptr 이면 맨 앞, 그 외엔 p 다음에 삽입
*/
InsertNode(Node*& head, Node* p, Node* newNode)
{
	if (head == nullptr)
	{
		// 빈 리스트 일때
		head = newNode;
	}
	else if (p == nullptr) {
		// 맨 앞에 삽입
		newNode->link = head;
		head = newNode;
	}
}

int main()
{
	Node* list1 = nullptr;
	Node* list2 = nullptr;
	Node* list3 = nullptr;

	// 1~3을 list1, 10~30을 list2 맨 앞 삽입
	for (int i = 0; i <= 3; i++)
	{
		InsertNode(list1, nullptr, new Node(i));
		InsertNode()
	}

	return 0;
}