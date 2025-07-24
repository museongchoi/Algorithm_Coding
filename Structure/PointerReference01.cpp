#include <iostream>

using namespace std;

int main()
{
	// �� ���� ���� ���� �ʱ�ȭ
	int tmp1 = 5;
	int tmp2 = 10;

	// 1) ������ : ������ �ּ� ����
	int* ptr = &tmp1;
	// ptr �� tmp1 �� �ּ�(&tmp1)�� ����

	cout << "tmp1 �� : " << tmp1 << "\n";
	cout << "tmp1 �ּ� : " << &tmp1 << "\n";

	cout << "ptr �� (ptr �� ������ �ּ�) : " << ptr << "\n";
	cout << "*ptr(�� �ּҰ� ����Ű�� ��) : " << *ptr << "\n";

	// �����͸� ���� tmp1 �� ���� ����
	*ptr = 20;
	cout << "*ptr = 20; ���� �� tmp1 �� : " << tmp1 << "\n";

	puts(" ");

	// 2) ���� : ������ ��Ī(alias) ����
	int& ref = tmp2;
	// ref �� tmp2 �� ����Ű��, ������ tmp2 �� ���� �޸� ����

	cout << "tmp2 �� : " << tmp2 << "\n";
	cout << "tmp2 �ּ� : " << &tmp2 << "\n";
	cout << "ref �� : " << ref << "\n";
	cout << "ref �ּ� : " << &ref << "\n";

	// ������ ���� tmp2 ���� ����
	ref = 40;
	cout << "ref = 40; ���� �� tmp2 ��" << tmp2 << "\n" << "\n";

	puts(" ");

	// 3) ���� ������ : �����͸� ����Ű�� ������
	int** pp = &ptr;

	cout << "ptr �ּ� : " << &ptr << "\n";
	cout << "pp ��(pp�� ������ �ּ�) : " << pp << "\n";

	cout << " *pp (=ptr) �� : " << *pp << "\n";
	cout << " **pp (=*ptr) �� : " << **pp << "\n";

	// ���� �����͸� ���� tmp1 �� ����
	**pp = 100;
	cout << "**pp = 100; ���� �� tmp1 �� : " << tmp1 << "\n";


	return 0;
}