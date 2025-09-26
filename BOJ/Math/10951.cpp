// cin bool üũ
#include <iostream>

using namespace std;

int main()
{
	int A, B;

	while (cin >> A >> B)
	{
		cout << A + B << endl;
	}

	return 0;
}

// .eof()
#include <iostream>

using namespace std;

int main()
{
	int A, B;

	while (!(cin >> A >> B).eof())
	{
		cout << A + B << endl;
	}
	cout << A + B << "\n"; // ���� ���� �� Ʋ�ȴ� �����µ� VS ���� �ô� �������� ����

	return 0;
}

// ���� �����
#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int A, B;

	while (cin >> A >> B)
	{
		cout << A + B << "\n";
	}

	return 0;
}