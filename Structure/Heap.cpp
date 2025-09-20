#include <iostream>

using namespace std;

struct Heap {
    int* data;    // 힙 원소들을 담는 동적 배열. 1번 인덱스부터 사용(루트=data[1]).
    int size;     // 현재 힙에 들어있는 원소 개수 (유효한 인덱스는 1..size).
    int capacity; // data 배열에 미리 할당해 둔 최대 수용량(1칸은 버리므로 실사용칸은 capacity).
};

Heap* CreateHeap(int cap = 16)
{
    if (cap < 1) cap = 1;
    Heap* h = new Heap;         // 생성
    h->data = new int[cap + 1]; // 힙 원소 동적 배열
    h->size = 0;                // 현재 힙에 들어가 있는 원소 개수
    h->capacity = cap;          // data 배열 최대 수용량

    return h;
}

void DestroyHeap(Heap* h)
{
    if (!h) return;
    delete[] h->data;
    delete h;
}

// isEmpty(h)는(h == nullptr) || (h->size == 0) 일 때 true
bool isEmpty(const Heap* h)
{
    if (!h) return false;
    return h->size == 0;
}

int Top(const Heap* h)
{
    if (isEmpty(h))
    {
        return -1;
    }

    return h->data[1];
}

// 용량이 부족하면 두배로 늘리기.
void EnsureCapacity(Heap* h)
{
    if (h->size < h->capacity) return;
    int newCap = (h->capacity == 0) ? 1 : h->capacity * 2;
    int* newArr = new int[newCap + 1];

    for (int i = 1; i <= h->size; i++)
    {
        newArr[i] = h->data[i];
    }

    delete[] h->data;
    h->data = newArr;
    h->capacity = newCap;
}

//Insert
// 1. Heap 배열 맨 끝에 임시 노드 삽입
// 2. 부모 노드와 우선순위 비교
//	  (3,4번은 2번이 충족 시 반복)
// 3. 임시 노드가 있던 자리에 부모 노드를 옮긴다
//  -> 이때, 임시 노드와 부모 노드 간에 swap이 아니다
// 4. 임시 노드를 다음 단계로 이동
// 5. 임시 노드에 element를 삽입
// heapInsert : 맨끝을 임시삽입을 한뒤 반복문을 돌려 자리를 찾는다
void HeapifyUp(Heap* h, int idx)
{
    int x = h->data[idx]; // 삽입할 값 보관

    while (idx > 1)
    {
        int parent = idx / 2;

        if (h->data[parent] >= x)
        {
            break; // 부모 노드 값이 더 큰 상태이므로 멈춘다.
        }
        h->data[idx] = h->data[parent]; // 부모를 한 칸 아래로 복사
        idx = parent;                   // 구멍을 부모 위치로 이동
    }
    h->data[idx] = x; // 최종 자리 확정
}

//Delete
// 1. Root삭제 후 그 자리에 마지막 노드를 임시 배치
// -> Root값이 필요한 경우, 삭제하기전에 임시변수에 저장
// 2. 두 자식 중 우선순위가 높은 자식을 구별
// 3. 임시 노드와 자식 노드 우선순위 비교
// 4. 자식 노드를 부모 노드로 바꾼다
// 5. 임시 노드에 마지막 노드를 삽입
// 맨 끝 노드를 루트 노드로 옮긴 후 자료구조 재정렬
void HeapifyDown(Heap* h, int idx)
{
    int x = h->data[idx];

    while (true)
    {
        int left = idx * 2;
        int right = idx * 2 + 1;

        if (left > h->size)
        {
            break; // 자식 없음 -> 자리 찾음
        }

        int Child = left;
        if (right <= h->size && h->data[right] > h->data[left])
        {
            Child = right; // 더 큰 자식을 선택
        }

        if (h->data[Child] <= x)
        {
            break; // 자식들보다 크거나 같음 -> 자리 확정
        }

        h->data[idx] = h->data[Child]; // 자식을 한 칸 끌어올림
        idx = Child;                   // 구멍을 자식 위치로 이동
    }
    h->data[idx] = x; //  최종 자리 확정
}

void Push(Heap* h, int value)
{
    EnsureCapacity(h);

    h->size += 1;
    h->data[h->size] = value; // 맨 뒤 임시 배치

    HeapifyUp(h, h->size);
}

bool Pop(Heap* h, int* out = nullptr)
{
    if (isEmpty(h))
    {
        cout << "Heap is empty" << "\n";
        return false;
    }
    if (out != nullptr)
    {
        *out = h->data[1]; // 루트 값 전달.
    }

    h->data[1] = h->data[h->size]; // 마지막 원소를 루트 자리로
    h->size -= 1;

    if (!isEmpty(h))
    {
        HeapifyDown(h, 1);
    }

    return true;
}


int main()
{
    Heap* h = CreateHeap(16);

    // 개별 삽입
    Push(h, 10);
    Push(h, 40);
    Push(h, 30);
    Push(h, 20);
    Push(h, 50);

    // 3) 최댓값 확인(Top)
    int t1 = Top(h);
    cout << "Top: " << t1 << '\n'; // 40

    // 4) 삭제(Pop) — 루트 제거
    int popped = -1;
    bool ok = Pop(h, &popped);
    if (ok)
    {
        cout << "Pop -> " << popped << '\n'; // 40
    }

    // 5) 다시 최댓값 확인
    int t2 = Top(h);
    cout << "Top: " << t2 << '\n'; // 30

    // 6) 자원 해제
    DestroyHeap(h);

    return 0;
}