#include <iostream>
#include <queue>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
};

Node* CreateNode(int data)
{
	Node* newNode = new Node;

	newNode->data = data;
	newNode->left = nullptr;
	newNode->right = nullptr;

	return newNode;
}

Node* InsertNode(Node* root, int data)
{
	if (!root)
	{
		root = CreateNode(data);
		return root;
	}

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* tmp = q.front();
		q.pop();

		if (tmp->left != nullptr)
		{
			q.push(tmp->left);
		}
		else {
			tmp->left = CreateNode(data);
			return root;
		}

		if (tmp->right != nullptr)
		{
			q.push(tmp->right);
		}
		else {
			tmp->right = CreateNode(data);
			return root;
		}
	}

	return root; // 반환 타입이 있기 때문에 컴파일러가 내는 분석 경고를 방지하는 return
}

// 전위 순회
void preorder(Node* root)
{
	if (root == nullptr) return;
	cout << root->data << "->";
	preorder(root->left);
	preorder(root->right);
}

// 중위 순회
void inorder(Node* root)
{
	if (root == nullptr) return;
	inorder(root->left);
	cout << root->data << "->";
	inorder(root->right);
}

// 후위 순회
void postorder(Node* root)
{
	if (root == nullptr) return;
	postorder(root->left);
	postorder(root->right);
	cout << root->data << "->";
}

// 레벨 순회
void levelorder(Node* root)
{
	if (!root) return;

	queue<Node*> q;
	q.push(root);

	while (!q.empty())
	{
		Node* tmp = q.front();
		q.pop();
		cout << tmp->data << "->";

		// tmp 가 nullptr 이 아니고, tmp->left 가 nullptr 이 아니면 true 를 반환. nullptr 이면 false 반환
		if (tmp->left)
		{
			q.push(tmp->left);
		}
		if (tmp->right)
		{
			q.push(tmp->right);
		}
	}
	cout << "\n";
}

int main()
{
	Node* root = CreateNode(1);
	root = InsertNode(root, 2);
	root = InsertNode(root, 3);
	root = InsertNode(root, 4);
	root = InsertNode(root, 5);

	cout << "전위 순회 : " << endl;
	preorder(root);

	cout << "\n";

	cout << "중이 순회 : " << endl;
	inorder(root);

	cout << "\n";

	cout << "후위 순회 : " << endl;
	postorder(root);

	cout << "\n";

	cout << "레벨 순회 : " << endl;
	levelorder(root);

	return 0;
}