#include<cstdio>

int arr[100];

int main()
{
	int n;
	int target;
	int input;
	int count = 0;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", arr + i);
	}

	scanf("%d", &target);

	for (int i = 0; i < n; i++) {
		if (arr[i] == target) count += 1;
	}

	printf("%d\n", count);

	return 0;
}



