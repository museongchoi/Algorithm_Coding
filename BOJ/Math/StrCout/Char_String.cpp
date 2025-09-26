#include <iostream>
#include <string>
#include <cstring> // strlen, strcpy, strcmp ��

using namespace std;

int main()
{
	// insert()
	string str = "Hello";
	cout << "insert �� str : " << str << endl;

	str.insert(5, " World");
	cout << "insert �� str : " << str << endl;

	// .length() :: .size()
	cout << str.length() << endl;
	cout << str.size() << endl;

	// char:: ��� x (�⺻)
	char c = str[1];
	cout << "char c byte : " << sizeof(c) << endl;
	cout << "string str byte : " << sizeof(str) << endl;
	cout << sizeof(str) / sizeof(str[0]) << endl;

	char name[] = "Moo";
	cout << "char �� name ���� : " << strlen(name) << endl;

	// .find()::Ư�� ���ڿ� ã��
	int stridx = str.find(" World");
	cout << stridx << endl;

	// .erase()::���� ����
	str.erase(stridx);
	cout << "str erase() �� : " << str << endl; // ���鵵 ����� ���� find �Ҷ� �����ؼ� ã���� �ȴ�

	// += / append() ���ڿ� ���� �߰�
	str += "!";
	cout << str << "\n";
	str += "!!!";
	cout << str << "\n";

	// ���ڿ� ã�� find + ���ڿ� ����
	int stridx1 = str.find("!");
	cout << stridx1 << "\n";

	str.erase(stridx1 - 1, 5); // ���� + !!!! (����ǥ 4��)
	cout << str << "\n";


	// �� ���ڿ� �� == , != / compare()
	string str2 = "Hello";
	string str3 = "World";

	if (str == str2)
		cout << "str �� str2�� ����." << "\n";
	else
		cout << "str �� str2�� �ٸ���." << "\n";

	if (str.compare(str3) == 1)
		cout << "str �� str3�� ����." << "\n";
	else
		cout << "str �� str3�� �ٸ���." << "\n";

	cout << str2 << "\n";
	// replace ���ڿ� ��ü : ��ü�ϰ� ���� ���ڿ� ��ġ + ��ü�� �κ� ���ڿ� ���� + ��ü�� ����
	str2.replace(str2.find("Hello"), str3.length(), str3);
	cout << str2 << "\n";

	return 0;
}