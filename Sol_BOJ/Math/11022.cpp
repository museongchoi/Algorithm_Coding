#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;

	int A, B;
	for (int i = 1; i <= T; i++)
	{
		cin >> A >> B;
		cout << "Case #" << i << ": " << A << " + " << B << " = " << A + B << endl;
	}

	return 0;
}