#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	string str;
	cin >> str;

	int NumMax = 0;
	for (int i = 0; i < T; i++)
	{
		NumMax += str[i] - '0';
	}
	cout << NumMax;
	return 0;
}

// stoi() : ���ڿ��� 10����(base=10) ����(int)�� ��ȯ
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int T;
	cin >> T;

	string str;
	string tmp;
	cin >> str;

	int NumMax = 0;
	for (int i = 0; i < T; i++)
	{
		tmp = str[i];
		NumMax += stoi(tmp);
	}

	cout << NumMax;

	return 0;
}