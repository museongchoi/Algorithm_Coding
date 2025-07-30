#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int A, B;
	char Comma;

	for (int i = 0; i < T; i++)
	{
		cin >> A >> Comma >> B;
		cout << A + B << endl;
	}

	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string str;
		cin >> str;

		//int total = str[0] + str[2] - 96;
		int total = (str[0] - '0') + (str[2] - '0');
		cout << total << endl;
	}

	return 0;
}