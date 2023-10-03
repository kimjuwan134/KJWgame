#include <iostream>

using namespace std;


int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < 2 * N - 1; i++)
	{
		for (int j = i; j < N; j++)
		{
			cout << " ";
		}
		for (int k = N - i; k <= N + i; k++)
		{
			cout << "*";
		}
		if (i >= N)
		{
			for (int j = i; j >= N; j--)
			{
				cout << " ";
			}
			for (int k = i - N; k <= N; k++)
			{
				cout << "*";
			}
		}
		else if (i == N)
		{
			continue;
		}
		cout << endl;
	}



	return 0;
}