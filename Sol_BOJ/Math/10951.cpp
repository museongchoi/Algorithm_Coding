// cin bool 체크
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
	cout << A + B << "\n"; // 백준 제출 시 틀렸다 나오는데 VS 빌드 시는 정답으로 나옴

	return 0;
}

// 향상된 입출력
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