#include <iostream>

using namespace std;


int main()
{
	int n, m, a, b;

	cin >> n >> m;

	int * arr = new int[n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b;

		for (int j = 0; j <= (b - a) / 2; j++)
		{
			int temp = 0;
			temp = arr[j + a - 1];
			arr[j + a - 1] = arr[b - j - 1];
			arr[b - j - 1] = temp;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}


	return 0;
}



