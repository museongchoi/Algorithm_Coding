#include <iostream>
#include <string>
#include <cstring> // strlen, strcpy, strcmp 등

using namespace std;

int main()
{
	// insert()
	string str = "Hello";
	cout << "insert 전 str : " << str << endl;

	str.insert(5, " World");
	cout << "insert 후 str : " << str << endl;

	// .length() :: .size()
	cout << str.length() << endl;
	cout << str.size() << endl;

	// char:: 헤더 x (기본)
	char c = str[1];
	cout << "char c byte : " << sizeof(c) << endl;
	cout << "string str byte : " << sizeof(str) << endl;
	cout << sizeof(str) / sizeof(str[0]) << endl;

	char name[] = "Moo";
	cout << "char 형 name 길이 : " << strlen(name) << endl;

	// .find()::특정 문자열 찾기
	int stridx = str.find(" World");
	cout << stridx << endl;

	// .erase()::문자 삭제
	str.erase(stridx);
	cout << "str erase() 후 : " << str << endl; // 공백도 지우기 가능 find 할때 포함해서 찾으면 된다

	// += / append() 문자열 끝에 추가
	str += "!";
	cout << str << "\n";
	str += "!!!";
	cout << str << "\n";

	// 문자열 찾기 find + 문자열 삭제
	int stridx1 = str.find("!");
	cout << stridx1 << "\n";

	str.erase(stridx1 - 1, 5); // 공백 + !!!! (느낌표 4개)
	cout << str << "\n";


	// 두 문자열 비교 == , != / compare()
	string str2 = "Hello";
	string str3 = "World";

	if (str == str2)
		cout << "str 과 str2는 같다." << "\n";
	else
		cout << "str 과 str2는 다르다." << "\n";

	if (str.compare(str3) == 1)
		cout << "str 과 str3는 같다." << "\n";
	else
		cout << "str 과 str3는 다르다." << "\n";

	cout << str2 << "\n";
	// replace 문자열 교체 : 교체하고 싶은 문자열 위치 + 대체될 부분 문자열 길이 + 대체할 문자
	str2.replace(str2.find("Hello"), str3.length(), str3);
	cout << str2 << "\n";

	return 0;
}