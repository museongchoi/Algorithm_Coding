#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str = "";
	getline(cin, str);

	int cnt = 1;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] == ' ')
		{
			cnt++;
		}
	}

	if (str[0] == ' ')
	{
		cnt--;
	}
	if (str[str.size() - 1] == ' ')
	{
		cnt--;
	}

	cout << cnt;
	return 0;
}