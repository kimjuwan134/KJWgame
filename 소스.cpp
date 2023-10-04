#include <iostream>

using namespace std;


int main()
{
	int N;

	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = i; j < N - 1; j++)
		{
			cout << " ";
		}
		for (int k = 1; k < 2 * (i+1); k++)
		{
			cout << "*";
		}
		cout << endl;
	}

	for (int i = N; i < 2*N-1; i++)
	{
		for (int k = N; k <= i; k++)
		{
			cout << " ";
		}
		for (int j = 4; j <= 2*(2*N-i); j++)
		{
			cout << "*";
		}
		cout << endl;
	}


	return 0;
}