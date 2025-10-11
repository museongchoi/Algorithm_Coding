#include <iostream>
#include <stack>

using namespace std;

int main()
{
	int K;
	cin >> K;

	// sumValue : 최종 합 | value : 입력 저장 변수
	int sumValue = 0;
	int value = 0;
	stack<int> st;

	for (int i = 0; i < K; ++i)
	{
		cin >> value;

		// 0 일떄 스택 top 값을 지운다. 아니면 해당 정수를 스택 push
		if (value == 0)
		{
			st.pop();
		}
		else
		{
			st.push(value);
		}
	}

	while (!st.empty())
	{
		sumValue += st.top();
		st.pop();
	}

	cout << sumValue;

	return 0;
}