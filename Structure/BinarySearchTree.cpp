#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

// -- 생성 / 정리 --
Node* CreateNode(int data)
{
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = nullptr;
    newNode->right = nullptr;

    return newNode;
}

void Clear(Node* root) // 후위 순회로 안전 해제
{
    if (!root) return;
    Clear(root->left);
    Clear(root->right);
    delete root;
}

// -- BST 삽입 (중복 무시) ---
Node* BSTInsert(Node* root, int data)
{
    // 맨 처음 생성, root == nullptr 일때.
    if (!root)
    {
        return CreateNode(data);
    }

    if (data < root->data)
    {
        root->left = BSTInsert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = BSTInsert(root->right, data);
    }
    else {
        // data = root->data -> 중복 정책 무시
    }

    return root;
}

// -- BST 검색 --
Node* BSTSearch(Node* root, int data)
{
    if (!root) return nullptr;

    if (data == root->data)
    {
        return root;
    }
    if (data < root->data)
    {
        return BSTSearch(root->left, data);
    }
    return BSTSearch(root->right, data);
}

// --- 오른쪽 서브트리의 최소값(중위 후속자) ---
Node* MinValueNode(Node* root)
{
    Node* cur = root;
    while (cur && cur->left) // cur : 현재 노드가 nullptr 이면 false, cur->left : 현재 노드의 left 가 nullptr 이면 false
    {
        cur = cur->left;
    }
    return cur;
}

// -- BST 삭제 --
Node* BSTDelete(Node* root, int data)
{
    if (!root) return nullptr;

    if (data < root->data) // data 가 현재 Node->data 보다 작으면 왼쪽 이동
    {
        root->left = BSTDelete(root->left, data); // 왼쪽으로 내려가며 '부모의 left 링크' 갱신
    }
    else if (data > root->data) // data 가 현재 노드 data 보다 크면 오른쪽 이동
    {
        root->right = BSTDelete(root->right, data); // 오른쪽으로 내려가며 '부모의 right 링크' 갱신
    }
    else {
        // === '삭제 대상' 노드를 찾음 ===

        // 자식 0
        if (!root->left && !root->right)
        {
            delete root;
            return nullptr;
        }

        // 자식 1(오른쪽만)
        if (!root->left)
        {
            Node* r = root->right;
            delete root;
            return r;
        }
        // 자식 1(왼쪽만)
        if (!root->right)
        {
            Node* l = root->left;
            delete root;
            return l;
        }

        // 자식 2 -> 중위 후속자 값 복사 후, 후속자 노드 삭제 (BST 중위 순회 : 항상 오름차순 / 선행자,후속자)
        // 즉, 오른쪽 노드 중 가장 작은 값을 찾아 복사 후 해당 노드 삭제
        Node* succ = MinValueNode(root->right);
        root->data = succ->data;
        root->right = BSTDelete(root->right, succ->data);
    }

    return root;  // 상위 호출자가 자신의 child 포인터를 이 반환값으로 갱신
}

void Preorder(Node* root)
{
    if (!root) return;
    cout << root->data << " ";
    Preorder(root->left);
    Preorder(root->right);

}

void Inorder(Node* root)
{
    if (!root) return;
    Inorder(root->left);
    cout << root->data << " ";
    Inorder(root->right);
}

void Postorder(Node* root)
{
    if (!root) return;
    Postorder(root->left);
    Postorder(root->right);
    cout << root->data << " ";
}

void Levelorder(Node* root)
{
    if (!root)
    {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* tmp = q.front();
        q.pop();
        cout << tmp->data << " ";
        if (tmp->left)
        {
            q.push(tmp->left);
        }
        if (tmp->right)
        {
            q.push(tmp->right);
        }
    }
}

int main()
{
    Node* root = nullptr;

    // 삽입 (BST 규칙: 값 비교로 좌/우 배치)
    int arr[] = { 5, 3, 7, 2, 4, 6, 8 };
    for (int x : arr) root = BSTInsert(root, x);

    cout << "Preorder  : "; Preorder(root);   cout << '\n';
    cout << "Inorder   : "; Inorder(root);    cout << '\n'; // BST는 오름차순
    cout << "Postorder : "; Postorder(root);  cout << '\n';
    cout << "Levelorder: "; Levelorder(root); cout << '\n';

    // 검색
    int k = 6;
    cout << "Search " << k << " : " << (BSTSearch(root, k) ? "found" : "not found") << '\n';

    // 삭제(자식 둘 가진 노드 삭제 테스트)
    root = BSTDelete(root, 7);
    cout << "After delete 7, inorder: "; Inorder(root); cout << '\n';

    Clear(root); // 누수 방지
    root = nullptr;

    return 0;
}