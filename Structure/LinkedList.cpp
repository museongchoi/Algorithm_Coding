#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int v) : data(v), next(nullptr) {}
};

// 리스트 앞에 삽입 (double_pointer 버전)
void push_front(Node** head_ref, int value)
{
	// 새 노드 생성
	Node* newNode = new Node(value);

	// 새 노드의 next 가 기존 head 를 가르키도록
	newNode->next = *head_ref;

	// head 를 새 노드로 업데이트
	*head_ref = newNode;
}

void printList(Node* head)
{

}

void freeList(Node* head)
{

}

int main()
{
	Node* head = nullptr;	// 빈 리스트

	// push_front 호출 시 &head (Node**) 를 넘겨준다
	push_front(&head, 10);
	push_front(&head, 20);
	push_front(&head, 30);
	// 리스트 30 -> 20 -> 10

	cout << "Linked List";
	printList(head);	// 출력 : 30 20 10

	freeList(head);

	return 0;
}