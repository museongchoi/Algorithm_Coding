#include <iostream>

using namespace std;

// 1) 값 전달 : x 는 a의 복사본
void PassByValue(int x)
{
	cout << "PassByValue x : " << x << " | &x : " << &x << "\n";
	x = 100; // x 만 변경될 뿐 호출 자 a 에는 영향이 없다.
	cout << "PassByValue [after] x = 100: x = " << x << "\n";
}

// 2) 포인터 전달 : p 는 a의 주소를 가리킴
void PassByPointer(int* p)
{
	cout << "PassByPointer p : " << p << " | *p : " << *p << "\n";
	*p = 200; // p 가 가리키는 메모리에 쓰기 -> 호출자 쪽 a 가 바뀜
	cout << "PassByPointer [after] *p = 200: *p = " << *p << "\n";
}

// 3) 참조 전달 : r 은 a 의 별칭(alias)
void PassByReference(int& r)
{
	cout << "PassByReference r: " << r << " | &r : " << &r << "\n";
	r = 300; // p 가 가리키는 메모리에 쓰기 -> 호출자 쪽 a 가 바뀜
	cout << "PassByReference [after] r = 300: r = " << r << "\n";
}

int main()
{
	int a = 10;
	cout << "main start : a = " << a << " | &a = " << &a << "\n";
	puts(" ");

	// -- 값 전달 --
	PassByValue(a);
	cout << "after PassByValue, a = " << a << "\n";
	puts(" ");

	// -- 포인터 전달 --
	// &a 를 넘겨주면 p == &a 가 되어 *p 는 a 를 가리킴
	PassByPointer(&a);
	cout << "after PassByPointer, a = " << a << "\n";
	puts(" ");

	// -- 참조 전달 --
	// a 를 그대로 넘기면 r==a 별칭이 되어 동일한 공간
	PassByReference(a);
	cout << "after PassByReference, a = " << a << "\n";


	return 0;
}