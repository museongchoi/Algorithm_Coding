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

// ��Ʈ�� ���� ���� Ȯ�� ���
#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;
    while (true)
    {
        getline(cin, text);
        if (!cin) break;
        cout << text << "\n";
    }
    return 0;
}