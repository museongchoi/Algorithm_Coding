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
void InsertNode(Node*& head, Node* p, Node* newNode)
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

/* 노드 삭제: head 포인터를 참조로 받아 수정
   p == nullptr 이면 맨 앞, 그 외엔 p 다음(tmp)을 삭제
*/

void removeNode(Node*& head, Node* p, Node* target)
{
	// 삭제할 노드가 없으면 무시
	if (target == nullptr)
	{
		return;
	}

	if (p == nullptr)
	{
		// 리스트 맨 앞 삭제
		head = target->link;
	}
	else {
		p->link = target->link;
	}
	delete target;
}

// 리스트 출력
void display(Node* head)
{
	// 범위 : cur; 은 cur != nullptr 과 동일
	for (Node* cur = head; cur; cur = cur->link)
	{
		cout << cur->data;
	}
	cout << "\n";
}

/* 데이터로 노드 검색
   찾으면 그 노드 포인터, 못 찾으면 nullptr 반환
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

/* 리스트 연결 : head1 끝에 head2 를 붙이고 head1 반환 */
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

	// 1~3을 list1, 10~30을 list2 맨 앞 삽입
	for (int i = 0; i <= 3; i++)
	{
		InsertNode(list1, nullptr, new Node(i));
		InsertNode(list2, nullptr, new Node(i * 10));
	}

	// list1에서 데이터 1 뒤에 4 삽입
	InsertNode(list1, searchNode(list1, 1), new Node(4));

	display(list1); // 3, 2, 1, 4
	display(list2); // 30, 20, 10
	cout << "\n";

	// 리스트 삭제
	removeNode(list1, nullptr, list1);	// 맨 앞 삭제 (3)
	removeNode(list2, searchNode(list2, 30), searchNode(list2, 20)); // 20 삭제

	display(list1);
	display(list2);
	cout << "\n";

	// 리스트 연결
	list3 = concat(list1, list2);
	display(list3);

	// 전체 메모리 해제
	while (list3)
	{
		Node* nxt = list3->link;
		delete list3;
		list3 = nxt;
	}

	return 0;
}