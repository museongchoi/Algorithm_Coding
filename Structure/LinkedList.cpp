#include <iostream>
using namespace std;

typedef int element;

// ��� ����ü ����
struct Node {
	element data;	// ���� ������
	Node* link;	// ���� ��� ������
};

// �� ��� ���� : malloc -> new, free -> delete
Node* create_node(element data, Node* link)
{
	Node* new_node = new Node;	// ���� Node �Ҵ�
	new_node->data = data;		// �� ����  
	new_node->link = link;		// ���� ��� ����
	return new_node;			// ȣ���ڿ��� �ּ� ��ȯ
}

// phead : head �������� �ּ�, p : ���� ��ġ ���� ���, new_node : ������ ���
void insert_node(Node** phead, Node* p, Node* new_node)
{
	// (1) ����Ʈ ��� ���� ��
	if (*phead == nullptr)
	{
		*phead = new_node;
		new_node->link = nullptr;
	}
	// (2) �� �տ� �����ϰ� ���� �� (p == nullptr)
	else if (p == nullptr)
	{
		new_node->link = *phead; // *phead == head �� ����Ű�� ����� �ּҸ� new_Node->link �� ����Ű�� �Ѵ�.
		*phead = new_node; // head �� ����Ű�� ù��° ��带 new_node �� ����.
	}
	// (3) �߰� �Ǵ� �� �� ����(������ ��� ���)
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

// phead : head �������� �ּ�, p : ���� ��ġ ���� ���, tmp : ������ ���
void remove_node(Node** phead, Node* p, Node* target)
{
	// phead ��ü null, ����Ʈ�� ��� �ְų�, ���� ����� ���� ���
	if (phead == nullptr || *phead == nullptr || target == nullptr)
	{
		return; // ���� �Ұ�
	}

	// 1) �� �� ��带 �����Ϸ��� ���
	if (p == nullptr)
	{
		// ����Ʈ �� �� ����
		*phead = target->link;
		delete target;
	}
	// 2) �߰� �Ǵ� ������ ����
	else {
		p->link = target->link;
		delete target;
	}
}

// ����Ʈ ��ȸ�Ͽ� ���
void display(Node* head)
{
	Node* p = head;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->link;
	}

	cout << "\n";

	//// ���� : cur; �� cur != nullptr �� ����
	//for (Node* cur = head; cur; cur = cur->link)
	//{
	//	cout << cur->data;
	//}
	//cout << "\n";
}

// ���� i�� ��� �˻� (�� ã���� nullptr ��ȯ)
Node* search_node(Node* head, element value)
{
	Node* p = head;
	while (p != nullptr)
	{
		if (value == p->data)
		{
			return p;
		}
		p = p->link;
	}

	return nullptr;

	//for (Node* cur = head; cur; cur = cur->link)
	//{
	//	if (cur->data == value)
	//	{
	//		return cur;
	//	}
	//}
	//return nullptr;
}

/* ����Ʈ ���� : head1 ���� head2 ������ ���̰� head1 ��ȯ */
Node* concat(Node* head1, Node* head2)
{
	if (!head1) // if (head1 == nullptr) head1 �� ��� ������
	{
		return head2;	// head2 �� �� ����Ʈ
	}

	Node* p = head1;
	while (p->link != nullptr) // �� ��带 ã�� ������
	{
		p = p->link;
	}
	p->link = head2;	// ����

	return head1;
}

int main()
{
	Node* list1 = nullptr;
	Node* list2 = nullptr;
	Node* list3 = nullptr;

	// 1~3�� list1, 10~30�� list2 �� �� ����
	for (int i = 1; i <= 3; i++)
	{
		insert_node(&list1, nullptr, create_node(i, nullptr));
		insert_node(&list2, nullptr, create_node(i * 10, nullptr));
	}

	// list1���� ������ 1 �ڿ� 4 ����
	insert_node(&list1, search_node(list1, 1), create_node(4, nullptr));

	display(list1); // 3, 2, 1, 4
	display(list2); // 30, 20, 10
	cout << "\n";

	// list1 �� �� 3 ����
	remove_node(&list1, nullptr, list1);
	// list2���� 30 ���� 20 ����
	remove_node(&list2, search_node(list2, 30), search_node(list2, 20));

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

// ���
/*
3 2 1 4 
30 20 10 

2 1 4 
30 10 

2 1 4 30 10 
*/