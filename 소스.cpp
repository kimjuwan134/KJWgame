#include <iostream>

using namespace std;


int main()
{
	int N;
	int result = 0;

	cin >> N;

	while (N)
	{
		string str;
		bool groupWord = true;
		int abc[26] = { 0, };
		cin >> str;
		for (int i = 0; i < str.length(); i++)
		{
			int temp = str[i] - 'a';
			if (i != 0 && str[i - 1] != str[i])
			{
				if (abc[temp] != 0)
				{
					groupWord = false;
					break;
				}
			}
			abc[temp]++;
		}
		if (groupWord) result++;
		N--;
	}

	cout << result;

	return 0;
}