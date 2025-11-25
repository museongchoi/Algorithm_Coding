#include <iostream>

using namespace std;

int main()
{
	// 두 개의 정수 변수 초기화
	int tmp1 = 5;
	int tmp2 = 10;

	// 1) 포인터 : 변수의 주소 저장
	int* ptr = &tmp1;
	// ptr 은 tmp1 의 주소(&tmp1)를 저장

	cout << "tmp1 값 : " << tmp1 << "\n";
	cout << "tmp1 주소 : " << &tmp1 << "\n";

	cout << "ptr 값 (ptr 이 저장한 주소) : " << ptr << "\n";
	cout << "*ptr(그 주소가 가리키는 값) : " << *ptr << "\n";

	// 포인터를 통해 tmp1 의 값을 변경
	*ptr = 20;
	cout << "*ptr = 20; 수행 후 tmp1 값 : " << tmp1 << "\n";

	puts(" ");

	// 2) 참조 : 변수의 별칭(alias) 역할
	int& ref = tmp2;
	// ref 는 tmp2 를 가리키며, 실제로 tmp2 와 같은 메모리 공간

	cout << "tmp2 값 : " << tmp2 << "\n";
	cout << "tmp2 주소 : " << &tmp2 << "\n";
	cout << "ref 값 : " << ref << "\n";
	cout << "ref 주소 : " << &ref << "\n";

	// 참조를 통해 tmp2 값을 변경
	ref = 40;
	cout << "ref = 40; 수행 후 tmp2 값" << tmp2 << "\n" << "\n";

	puts(" ");

	// 3) 이중 포인터 : 포인터를 가리키는 포인터
	int** pp = &ptr;

	cout << "ptr 주소 : " << &ptr << "\n";
	cout << "pp 값(pp가 저장한 주소) : " << pp << "\n";

	cout << " *pp (=ptr) 값 : " << *pp << "\n";
	cout << " **pp (=*ptr) 값 : " << **pp << "\n";

	// 이중 포인터를 통해 tmp1 값 변경
	**pp = 100;
	cout << "**pp = 100; 수행 후 tmp1 값 : " << tmp1 << "\n";


	return 0;
}