// getline()
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string line;
	while (getline(cin, line))
	{
		cout << line << endl;
	}
	return 0;
}


// cin.read() (문자 그대로 읽기)
#include <iostream>
using namespace std;

int main()
{
	char buf[101]; // 임시 버퍼
	while (cin.getline(buf, sizeof(buf)))
	{
		cout << buf << '\n';
	}
}



// cin.get() (문자 단위 입력)
#include <iostream>
using namespace std;

int main()
{
	char ch;
	while (cin.get(ch)) // EOF까지 문자 단위로
	{
		cout << ch;
	}
}
