#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;
	Node(int v) : data(v), next(nullptr) {}
};

// ����Ʈ �տ� ���� (double_pointer ����)
void push_front(Node** head_ref, int value)
{
	// �� ��� ����
	Node* newNode = new Node(value);

	// �� ����� next �� ���� head �� ����Ű����
	newNode->next = *head_ref;

	// head �� �� ���� ������Ʈ
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
	Node* head = nullptr;	// �� ����Ʈ

	// push_front ȣ�� �� &head (Node**) �� �Ѱ��ش�
	push_front(&head, 10);
	push_front(&head, 20);
	push_front(&head, 30);
	// ����Ʈ 30 -> 20 -> 10

	cout << "Linked List";
	printList(head);	// ��� : 30 20 10

	freeList(head);

	return 0;
}