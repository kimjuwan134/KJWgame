#include <stdio.h>

int main()
{
	int A, B;


	while (1)
	{
		scanf_s("%d %d", &A, &B);

		if (0 < A < 10 && 0 < B < 10)
		{

			printf("%d\n", A + B);
		}
	}

	return 0;
}