#include <iostream>
#include <vector>

using namespace std;

struct Heap {
	vector<int> data; // data[0] 은 비워둠.
	int size = 0; // 유효 원소 개수 (1~size)
};

Heap* CreateHeap(int heapsize)
{
	if (heapsize < 1) heapsize = 1;
	Heap* h = new Heap;
	h->data.resize(heapsize + 1); // idx 1부터 시작이므로 heapsize + 1
	h->size = 0; // 현재 요소 개수
	return h;
}

void DestroyHeap(Heap* h)
{
	if (!h) return;
	delete h; // vector 가 자동으로 내부 메모리 정리
}

bool isEmpty(Heap* h)
{
	if (!h) return true; // h == nullptr 이면 비었다 → true
	return h->size == 0; // 아니면 size == 0 이면 비었다 → true
}

void SizeEnsure(Heap* h)
{
	int nowsize = (int)h->data.size() - 1; // idx 0 은 사용하지 않으므로 실사용 칸수를 구하기 위해 size() - 1
	if (h->size < nowsize)
	{
		return;
	}

	if (nowsize == 0) nowsize = 1;
	else nowsize = nowsize * 2;

	h->data.resize(nowsize + 1);
}

// 삽입 후 위로 끌어 올림 (Max-Heap: 부모 >= 자식 유지)
void HeapifyUp(Heap* h, int idx)
{
	int x = h->data[idx];

	while (idx > 1)
	{
		int parent = idx / 2;

		if (h->data[parent] >= x)
		{
			break;
		}
		h->data[idx] = h->data[parent]; // parent 를 아래로 이동
		idx = parent; // idx 비교 위치 이동
	}
	h->data[idx] = x; // 최종 자리 확정
}

// 루트 교체 후 아래로 내림
void HeapifyDown(Heap* h, int idx)
{
	int x = h->data[idx];

	// idx 1이 root 인점을 고려
	while (true)
	{
		int left = idx * 2;
		int right = idx * 2 + 1;

		if (left > h->size) break; // 왼쪽 자식이 있는지 확인

		// left, right 중 더 큰 자식을 선택
		int Child = left;
		if (right <= h->size && h->data[right] > h->data[left])
		{
			Child = right;
		}

		if (h->data[Child] <= x) break; // 자식들 보다 크거나 같은 자리 확정

		h->data[idx] = h->data[Child]; // 자식을 한 칸 위로 복사
		idx = Child; // idx 비교 위치 이동
	}
	h->data[idx] = x; // 최종 자리 확정
}

int Top(Heap* h)
{
	if (isEmpty(h))
	{
		return -1;
	}
	return h->data[1];
}

// 삽입
void push(Heap* h, int value)
{
	SizeEnsure(h);
	h->size += 1;
	h->data[h->size] = value; // 맨 뒤에 임시 배치

	HeapifyUp(h, h->size);
}

// 삭제 (루트 제거)
void pop(Heap* h)
{
	h->data[1] = h->data[h->size];
	h->size -= 1;

	if (!isEmpty(h))
	{
		HeapifyDown(h, 1);
	}
}

int main()
{
	Heap* heap = CreateHeap(16);

	for (int i = 1; i <= 5; ++i)
	{
		push(heap, i * 10);
		cout << Top(heap) << "\n";
	}

	pop(heap);

	cout << "pop 1 : " << Top(heap) << "\n";

	DestroyHeap(heap);

	return 0;
}