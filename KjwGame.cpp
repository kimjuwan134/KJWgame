#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MINE_COUNT 7
#define X_COUNT 6
#define Y_COUNT 6

void CreateMineTable(char mine_table[][X_COUNT])
{
	int x, y, mine_count;

	// mine 정보를 저장할 메모리에 모두 0을 채운다.
	for (y = 0; y < Y_COUNT; y++)
	{
		for (x = 0; x < X_COUNT; x++)
		{
			mine_table[y][x] = 0;
		}
	}

	// 폭탄을 MINE_COUNT개만큼 생성한다.
	for (mine_count = 0; mine_count < MINE_COUNT; mine_count++)
	{
		// 난수를 사용하여 폭탄이 위치할 곳을 생성한다.
		x = rand() % X_COUNT;
		y = rand() % Y_COUNT;
		// 폭탄이 설치된 곳이 아니라면 폭탄을 설치하고 이미 설치된 곳이라면
		// 폭탄의 수를 줄여서 다시 시도하게 된다.
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
			// 폭탄이 아니라면 인접한 위치에 폭탄이 몇개 있는지 체크한다.
			if (mine_table[y][x] == 0)
			{
				// 폭탄의 수를 초기화한다.
				mine_count = 0;
				// 현재 위치 (C)를 중심으로 총 8방향의 위치에 폭탄이 몇개 있는지 체크한다.
				// 1, 2, 3
				// 4, C, 5
				// 6, 7, 8
				if ((y - 1) >= 0)
				{
					// 음수가 나오지 않게 체크한다.
					// 1, 2, 3번 항목을 체크한다.
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
				// 4, 5 항목을 체크한다.
				if ((x - 1) >= 0 && mine_table[y][x - 1] == '*')
				{
					mine_count++;
				}
				if ((x + 1) < X_COUNT && mine_table[y][x + 1] == '*')
				{
					mine_count++;
				}
				// 6, 7, 8번 항목을 체크한다.
				if ((y + 1) < Y_COUNT)
				{
					// 범위를 벗어나지 않게 체크한다.
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
				// 계산된 폭탄 수를 정수에서 문자로 변경해서 현재 위치에 대입한다.
				// 예를 들어, 5 라면 '5'로 저장한다.
				mine_table[y][x] = '0' + mine_count;
			}
		}
	}
}

int main()
{
	// 폭탄이 설치된 정보를 저장할 변수
	char mine_table[Y_COUNT][X_COUNT];

	// 현재 시간을 기준으로 난수를 설정
	srand((unsigned)time(NULL));

	// 폭탄 설치 정보를 구성
	CreateMineTable(mine_table);


	return 0;
}