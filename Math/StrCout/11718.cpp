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


// cin.read() (���� �״�� �б�)
#include <iostream>
using namespace std;

int main()
{
	char buf[101]; // �ӽ� ����
	while (cin.getline(buf, sizeof(buf)))
	{
		cout << buf << '\n';
	}
}



// cin.get() (���� ���� �Է�)
#include <iostream>
using namespace std;

int main()
{
	char ch;
	while (cin.get(ch)) // EOF���� ���� ������
	{
		cout << ch;
	}
}
