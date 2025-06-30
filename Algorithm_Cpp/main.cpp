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
void InsertNode(Node*& head, Node* p, Node* newNode)
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

/* ��� ����: head �����͸� ������ �޾� ����
   p == nullptr �̸� �� ��, �� �ܿ� p ����(tmp)�� ����
*/

void removeNode(Node*& head, Node* p, Node* target)
{
	// ������ ��尡 ������ ����
	if (target == nullptr)
	{
		return;
	}

	if (p == nullptr)
	{
		// ����Ʈ �� �� ����
		head = target->link;
	}
	else {
		p->link = target->link;
	}
	delete target;
}

// ����Ʈ ���
void display(Node* head)
{
	// ���� : cur; �� cur != nullptr �� ����
	for (Node* cur = head; cur; cur = cur->link)
	{
		cout << cur->data;
	}
	cout << "\n";
}

/* �����ͷ� ��� �˻�
   ã���� �� ��� ������, �� ã���� nullptr ��ȯ
*/
Node* searchNode(Node* head, int value)
{
	for (Node* cur = head; cur; cur = cur->link)
	{
		if (cur->data == value)
		{
			return cur;
		}
	}
	return nullptr;
}

/* ����Ʈ ���� : head1 ���� head2 �� ���̰� head1 ��ȯ */
Node* concat(Node* head1, Node* head2)
{
	if (!head1)
	{
		return head2;
	}
	Node* cur = head1;
	while (cur->link)
	{
		cur = cur->link;
	}
	cur->link = head2;
	return head1;
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
		InsertNode(list2, nullptr, new Node(i * 10));
	}

	// list1���� ������ 1 �ڿ� 4 ����
	InsertNode(list1, searchNode(list1, 1), new Node(4));

	display(list1); // 3, 2, 1, 4
	display(list2); // 30, 20, 10
	cout << "\n";

	// ����Ʈ ����
	removeNode(list1, nullptr, list1);	// �� �� ���� (3)
	removeNode(list2, searchNode(list2, 30), searchNode(list2, 20)); // 20 ����

	display(list1);
	display(list2);
	cout << "\n";

	// ����Ʈ ����
	list3 = concat(list1, list2);
	display(list3);

	// ��ü �޸� ����
	while (list3)
	{
		Node* nxt = list3->link;
		delete list3;
		list3 = nxt;
	}

	return 0;
}