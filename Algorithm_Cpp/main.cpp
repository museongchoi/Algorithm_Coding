#include <iostream>
using namespace std;

struct Node {
	int data;	// ������ ��
	Node* link;	// ���� ��� ������
	Node(int v, Node* nxt = nullptr) 
		: data(v), link(nxt) {}
};

/*  
	��� ���� : head �����͸� ������ �޾� ����
	p == nullptr �̸� �� ��, �� �ܿ� p ������ ����
*/
InsertNode(Node*& head, Node* p, Node* newNode)
{
	if (head == nullptr)
	{
		// �� ����Ʈ �϶�
		head = newNode;
	}
	else if (p == nullptr) {
		// �� �տ� ����
		newNode->link = head;
		head = newNode;
	}
}

int main()
{
	Node* list1 = nullptr;
	Node* list2 = nullptr;
	Node* list3 = nullptr;

	// 1~3�� list1, 10~30�� list2 �� �� ����
	for (int i = 0; i <= 3; i++)
	{
		InsertNode(list1, nullptr, new Node(i));
		InsertNode()
	}

	return 0;
}