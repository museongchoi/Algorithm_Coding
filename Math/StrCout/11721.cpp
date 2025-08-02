#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str = "";
	cin >> str;

	for (int i = 0; i < str.size(); i++)
	{
		if (i % 10 == 9)
		{
			cout << endl;
		}
		cout << str[i];

	}
	return 0;
}


// string::substr()
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string str = "";
	cin >> str;

	for (int i = 0; i < str.size(); i += 10)
	{
		cout << str.substr(i, 10) << endl;
	}
	return 0;
}