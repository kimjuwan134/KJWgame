#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINE_COUNT 7
#define X_COUNT 6
#define Y_COUNT 6

void CreateMineTable(char mine_table[][X_COUNT])
{
	int x, y, mine_count;

	// mine ������ ������ �޸𸮿� ��� 0�� ä���.
	for (y = 0; y < Y_COUNT; y++)
	{
		for (x = 0; x < X_COUNT; x++)
		{
			mine_table[y][x] = 0;
		}
	}

	// ��ź�� MINE_COUNT����ŭ �����Ѵ�.
	for (mine_count = 0; mine_count < MINE_COUNT; mine_count++)
	{
		// ������ ����Ͽ� ��ź�� ��ġ�� ���� �����Ѵ�.
		x = rand() % X_COUNT;
		y = rand() % Y_COUNT;
		// ��ź�� ��ġ�� ���� �ƴ϶�� ��ź�� ��ġ�ϰ� �̹� ��ġ�� ���̶��
		// ��ź�� ���� �ٿ��� �ٽ� �õ��ϰ� �ȴ�.
		if (mine_table[y][x] == 0)
		{
			mine_table[y][x] = '*';
		}
		else mine_count--;
	}

	for (y = 0; y < Y_COUNT; y++)
	{
		for (x = 0; x < X_COUNT; x++)
		{
			// ��ź�� �ƴ϶�� ������ ��ġ�� ��ź�� � �ִ��� üũ�Ѵ�.
			if (mine_table[y][x] == 0)
			{
				// ��ź�� ���� �ʱ�ȭ�Ѵ�.
				mine_count = 0;
				// ���� ��ġ (C)�� �߽����� �� 8������ ��ġ�� ��ź�� � �ִ��� üũ�Ѵ�.
				// 1, 2, 3
				// 4, C, 5
				// 6, 7, 8
				if ((y - 1) >= 0)
				{
					// ������ ������ �ʰ� üũ�Ѵ�.
					// 1, 2, 3�� �׸��� üũ�Ѵ�.
					if ((x - 1) >= 0 && mine_table[y - 1][x - 1] == '*')
					{
						mine_count++;
					}
					if (mine_table[y - 1][x] == '*')
					{
						mine_count++;
					}
					if ((x + 1) < X_COUNT && mine_table[y - 1][x + 1] == '*')
					{
						mine_count++;
					}
				}
				// 4, 5 �׸��� üũ�Ѵ�.
				if ((x - 1) >= 0 && mine_table[y][x - 1] == '*')
				{
					mine_count++;
				}
				if ((x + 1) < X_COUNT && mine_table[y][x + 1] == '*')
				{
					mine_count++;
				}
				// 6, 7, 8�� �׸��� üũ�Ѵ�.
				if ((y + 1) < Y_COUNT)
				{
					// ������ ����� �ʰ� üũ�Ѵ�.
					if ((x - 1) >= 0 && mine_table[y + 1][x - 1] == '*')
					{
						mine_count++;
					}
					if (mine_table[y + 1][x] == '*')
					{
						mine_count++;
					}
					if ((x + 1) X_COUNT && mine_table[y + 1][x + 1] == '*')
					{
						mine_count++;
					}
				}
				// ���� ��ź ���� �������� ���ڷ� �����ؼ� ���� ��ġ�� �����Ѵ�.
				// ���� ���, 5 ��� '5'�� �����Ѵ�.
				mine_table[y][x] = '0' + mine_count;
			}
		}
	}
}

int main()
{
	// ��ź�� ��ġ�� ������ ������ ����
	char mine_table[Y_COUNT][X_COUNT];

	// ���� �ð��� �������� ������ ����
	srand((unsigned)time(NULL));

	// ��ź ��ġ ������ ����
	CreateMineTable(mine_table);


	return 0;
}