#include <stdio.h>

int main()
{
	int A, B, C, D;

	scanf_s("%d %d", &A, &B);
	scanf_s("%d", &C);

	if (0 <= A <= 23 && 0 <= B <= 59 && 0 <= C <= 1000);
	{
		D = B + C;
		if (D > 59)
		{
			A += D / 60;
			D %= 60;
			if (A > 23)
			{
				A -= 24;
			}
		}
		printf("%d %d", A, D);
	}


	return 0;
}