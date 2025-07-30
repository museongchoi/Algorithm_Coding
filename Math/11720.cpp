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

// stoi() : 문자열을 10진수(base=10) 정수(int)로 변환
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