// 2차원 배열
#include <iostream>

using namespace std;

int arr[2][6];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n; // 학생 수
	int k; // 방 배정 최대 인원 수
	int s; // 성별 여 : 0, 남 : 1
	int y; // 학년

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> s >> y;
		arr[s][y - 1] += 1;
	}

	int answer = 0;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 6; ++j)
		{
			if (arr[i][j] % k != 0)
			{
				answer += 1;
			}
			answer += arr[i][j] / k;

			/*
			for (int j = 0; j < 6; ++j)
			{
				answer += ceil((double)arr[i][j] / k); // ceil() 사용 시 <cmath> 추가 
			}
			*/
		}
	}

	cout << answer;

	return 0;
}

// 배열 2개 사용
#include <iostream>

using namespace std;

int arrM[7];
int arrG[7];

int main()
{
	int n; // 학생 수
	int k; // 방 배정 최대 인원 수
	int s; // 성별 여 : 0, 남 : 1
	int y; // 학년

	cin >> n >> k;

	for (int i = 0; i < n; ++i)
	{
		cin >> s >> y;
		if (s == 0)
		{
			arrG[y] += 1;
		}
		else
		{
			arrM[y] += 1;
		}
	}

	int answer = 0;
	for (int i = 0; i <= 6; ++i)
	{
		if (arrG[i] % k != 0)
		{
			answer += 1;
		}
		answer += arrG[i] / k;
	}

	for (int i = 0; i <= 6; ++i)
	{
		if (arrM[i] % k != 0)
		{
			answer += 1;
		}
		answer += arrM[i] / k;
	}

	cout << answer;

	return 0;
}