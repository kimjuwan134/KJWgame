#include <iostream>
#include <vector>

using namespace std;


int main()
{
	int max = 0;
	int a, b;
	int arr[9][9];

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cin >> arr[i][j];

			if (max <= arr[i][j])
			{
				max = arr[i][j];
				a = i + 1;
				b = j + 1;
			}
		}
	}

	cout << max << endl << a << " " << b;




	return 0;
}