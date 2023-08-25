#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>

#define MINE_COUNT 7
#define X_COUNT 6
#define Y_COUNT 6

void CreateMineTable(char mine_table[][X_COUNT], char check_table[][X_COUNT])
{
	int x, y, mine_count;
	// mine 정보를 저장할 메모리에 모두 0을 채운다.

	memset(mine_table, 0, Y_COUNT * X_COUNT);
	// 사용자의 선택 정보를 저장할 메모리에 모두 0을 채운다.
	
	memset(check_table, 0, Y_COUNT * X_COUNT);

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
					if ((x + 1) < X_COUNT && mine_table[y + 1][x + 1] == '*')
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

void ShowMineTable(char mine_table[][X_COUNT])
{
	printf("\n"); // 줄 바꿈
	for (int y = 0; y < Y_COUNT; y++)
	{
		// 한 줄의 정보를 출력
		for (int x = 0; x < X_COUNT; x++)
		{
			printf("%c", mine_table[y][x]);	
		}
		printf("\n"); // 줄 바꿈
	}
	printf("\n"); // 줄 바꿈
}

void ShowCurrentState(char mine_table[][X_COUNT], char check_table[][X_COUNT])
{
	printf("\n"); // 줄 바꿈
	for (int y = 0; y < Y_COUNT; y++)
	{
		// 한 줄의 정보를 출력
		for (int x = 0; x < X_COUNT; x++)
		{
			if (check_table[y][x]) 
				printf("%c", mine_table[y][x]);
			else
				printf("■");
		}
		printf("\n"); // 줄 바꿈
	}
	printf("\n"); // 줄 바꿈
}

int main()
{
	// 폭탄이 설치된 정보를 저장할 변수
	char mine_table[Y_COUNT][X_COUNT];

	// 사용자가 선택한 위치를 기억할 변수
	char check_table[Y_COUNT][X_COUNT];

	// 현재 시간을 기준으로 난수를 설정
	srand((unsigned)time(NULL));

	// 폭탄 설치 정보를 구성
	CreateMineTable(mine_table, check_table);
	
	// 선택 정보를 반영하여 지뢰 정보를 출력
	// @ 문자로 출력된 것은 아직 확인이 안된 항목
	ShowCurrentState(mine_table, check_table);

	int x, y;
	while (1)
	{
		printf("확인할 위치의 x, y좌표를 입력하세요.\n");
		printf("음수를 입력하면 게임이 종료됩니다.\n");
		printf("x 좌표 입력 : ");
		scanf_s("%d", &x);
		// 음수가 입력되었으면 게임을 종료
		if (x < 0) break;

		printf("y 좌표 입력 : ");
		scanf_s("%d", &y);
		// 음수가 입력되었으면 게임 종료
		if (y < 0) break;

		// 위치 정보를 제대로 입력했는지 확인
		if (x < X_COUNT && y < Y_COUNT)
		{
			// 이미 확인한 위치인지 체크
			if (check_table[y][x] == 0)
			{
				// 사용자가 폭탄을 선택한 경우
				if (mine_table[y][x] == '*')
				{
					printf("폭탄을 선택했습니다. 미션 실패!\n\n");
					break; // 게임 중단
				}
				else
				{
					// 선택했음을 설정
					check_table[y][x] = 1;
					// 선택 정보를 반영하여 지뢰 정보를 출력
					// @ 문자로 출력된 것은 아직 확인이 안된 항목
					ShowCurrentState(mine_table, check_table);
				}
			}
			else printf("이미 확인한 위치입니다.\n\n");
		}
		else printf("잘못된 위치를 입력했습니다.\n\n");
	}

	// 설치 정보를 확인
	ShowMineTable(mine_table);


	return 0;
}