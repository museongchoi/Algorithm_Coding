#include <iostream>
using namespace std;

typedef int element;

// 노드 구조체 정의
struct Node {
	element data;	// 실제 데이터
	Node* link;	// 다음 노드 포인터
};

// 새 노드 생성 : malloc -> new, free -> delete
Node* create_node(element data, Node* link)
{
	Node* new_node = new Node;	// 힙에 Node 할당
	new_node->data = data;		// 값 설정  
	new_node->link = link;		// 다음 노드 연결
	return new_node;			// 호출자에게 주소 반환
}

// phead : head 포인터의 주소, p : 삽입 위치 직전 노드, new_node : 삽입할 노드
void insert_node(Node** phead, Node* p, Node* new_node)
{
	// (1) 리스트 비어 있을 때
	if (*phead == nullptr)
	{
		*phead = new_node;
		new_node->link = nullptr;
	}
	// (2) 맨 앞에 삽입하고 싶을 때 (p == nullptr)
	else if (p == nullptr)
	{
		new_node->link = *phead; // *phead == head 가 가르키는 노드의 주소를 new_Node->link 가 가르키게 한다.
		*phead = new_node; // head 가 가르키는 첫번째 노드를 new_node 로 변경.
	}
	// (3) 중간 또는 맨 끝 삽입(나머지 모든 경우)
	else {
		new_node->link = p->link;
		p->link = new_node;
	}
}

// phead : head 포인터의 주소, p : 삭제 위치 직전 노드, tmp : 삭제할 노드
void remove_node(Node** phead, Node* p, Node* target)
{
	// phead 자체 null, 리스트가 비어 있거나, 삭제 대상이 널인 경우
	if (phead == nullptr || *phead == nullptr || target == nullptr)
	{
		return; // 삭제 불가
	}

	// 1) 맨 앞 노드를 삭제하려는 경우
	if (p == nullptr)
	{
		// 리스트 맨 앞 삭제
		*phead = target->link;
		delete target;
	}
	// 2) 중간 또는 마지막 삭제
	else {
		p->link = target->link;
		delete target;
	}
}

// 리스트 순회하여 출력
void display(Node* head)
{
	Node* p = head;
	while (p != nullptr)
	{
		cout << p->data << " ";
		p = p->link;
	}

	cout << "\n";

	//// 범위 : cur; 은 cur != nullptr 과 동일
	//for (Node* cur = head; cur; cur = cur->link)
	//{
	//	cout << cur->data;
	//}
	//cout << "\n";
}

// 값이 i인 노드 검색 (못 찾으면 nullptr 반환)
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

/* 리스트 연결 : head1 끝에 head2 시작을 붙이고 head1 반환 */
Node* concat(Node* head1, Node* head2)
{
	if (!head1) // if (head1 == nullptr) head1 이 비어 있으면
	{
		return head2;	// head2 가 새 리스트
	}

	Node* p = head1;
	while (p->link != nullptr) // 끝 노드를 찾을 때까지
	{
		p = p->link;
	}
	p->link = head2;	// 연결

	return head1;
}

int main()
{
	Node* list1 = nullptr;
	Node* list2 = nullptr;
	Node* list3 = nullptr;

	// 1~3을 list1, 10~30을 list2 맨 앞 삽입
	for (int i = 1; i <= 3; i++)
	{
		insert_node(&list1, nullptr, create_node(i, nullptr));
		insert_node(&list2, nullptr, create_node(i * 10, nullptr));
	}

	// list1에서 데이터 1 뒤에 4 삽입
	insert_node(&list1, search_node(list1, 1), create_node(4, nullptr));

	display(list1); // 3, 2, 1, 4
	display(list2); // 30, 20, 10
	cout << "\n";

	// list1 맨 앞 3 삭제
	remove_node(&list1, nullptr, list1);
	// list2에서 30 뒤의 20 삭제
	remove_node(&list2, search_node(list2, 30), search_node(list2, 20));

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

// 출력
/*
3 2 1 4 
30 20 10 

2 1 4 
30 10 

2 1 4 30 10 
*/