#include <stdio.h>

int main()
{
	int A, B, C;

	scanf_s("%d %d", &A, &B);
	scanf_s("%d", &C);

	if (0 <= A <= 23 && 0 <= B <= 59 && 0 <= C <= 1000)
	{
		if (B + C < 59)
		{
			B += C;
			if (B > 59)
			{
				A++;
				if (A > 23)
				{
					A = 0;
				}
			}
		}
		else if (B + C > 59)
		{
			int a = C % 60;
			int b = C / 60;
			A += b;
			B = a;

			if (A > 23)
			{
				A -= 23;
			}
		}
		printf("%d %d", A, B);
	}

	return 0;
}