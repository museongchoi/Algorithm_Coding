#include <iostream>

using namespace std;

// 1) �� ���� : x �� a�� ���纻
void PassByValue(int x)
{
	cout << "PassByValue x : " << x << " | &x : " << &x << "\n";
	x = 100; // x �� ����� �� ȣ�� �� a ���� ������ ����.
	cout << "PassByValue [after] x = 100: x = " << x << "\n";
}

// 2) ������ ���� : p �� a�� �ּҸ� ����Ŵ
void PassByPointer(int* p)
{
	cout << "PassByPointer p : " << p << " | *p : " << *p << "\n";
	*p = 200; // p �� ����Ű�� �޸𸮿� ���� -> ȣ���� �� a �� �ٲ�
	cout << "PassByPointer [after] *p = 200: *p = " << *p << "\n";
}

// 3) ���� ���� : r �� a �� ��Ī(alias)
void PassByReference(int& r)
{
	cout << "PassByReference r: " << r << " | &r : " << &r << "\n";
	r = 300; // p �� ����Ű�� �޸𸮿� ���� -> ȣ���� �� a �� �ٲ�
	cout << "PassByReference [after] r = 300: r = " << r << "\n";
}

int main()
{
	int a = 10;
	cout << "main start : a = " << a << " | &a = " << &a << "\n";
	puts(" ");

	// -- �� ���� --
	PassByValue(a);
	cout << "after PassByValue, a = " << a << "\n";
	puts(" ");

	// -- ������ ���� --
	// &a �� �Ѱ��ָ� p == &a �� �Ǿ� *p �� a �� ����Ŵ
	PassByPointer(&a);
	cout << "after PassByPointer, a = " << a << "\n";
	puts(" ");

	// -- ���� ���� --
	// a �� �״�� �ѱ�� r==a ��Ī�� �Ǿ� ������ ����
	PassByReference(a);
	cout << "after PassByReference, a = " << a << "\n";


	return 0;
}