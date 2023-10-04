#include <iostream>

using namespace std;


int main()
{
	string str;
	int abc[26] = { 0, };
	int count = 0;

	cin >> str;

	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] < 'a') abc[str[i] - 'A']++;
		else abc[str[i] - 'a']++;
	}

	int max = 0, max_index = 0;

	for (int i = 0; i < 26; i++)
	{
		if (max < abc[i])
		{
			max = abc[i];
			max_index = i;
		}
	}

	for (int i = 0; i < 26; i++)
	{
		if (max == abc[i]) count++;
	}

	if (count > 1) cout << "?";
	else cout << char(max_index + 65);






	return 0;
}