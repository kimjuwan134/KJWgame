#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define CAR_WIDTH 12
#define CAR_HEIGHT 6
#define MAP_HEIGHT 37

char car[CAR_HEIGHT][CAR_WIDTH];
char map[MAP_HEIGHT];

void gotoXY(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

struct Player
{
	int x, y;
};

struct Enemy
{
	int x, y;
};

void MapInit()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		map[i] = 'l';
	}
}

void MapRender()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		gotoXY(40, i);
		printf("%c", map[i]);
		printf("\n");
	}
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		gotoXY(100, i);
		printf("%c", map[i]);
		printf("\n");
	}
}

void CarInit()
{
	strcpy(car[0], "  _____    ");
	strcpy(car[1], " /     \\   ");
	strcpy(car[2], "び-----び");
	strcpy(car[3], "び-----び");
	strcpy(car[4], "び-----び");
	strcpy(car[5], "び_____び");
}

void CarRender(Player * player)
{
	for (int i = 0; i <= CAR_HEIGHT - 1; i++)
	{
		gotoXY(player->x, i+player->y);
		printf("%s", car[i]);
		printf("\n");
	}
}

void EnemyRender(Enemy* enemy)
{
	for (int i = 0; i <= CAR_HEIGHT - 1; i++)
	{
		gotoXY(enemy->x, i + enemy->y);
		printf("%s", car[i]);
		printf("\n");
	}
}

void Keyboard(Player* player)
{
	char key = 0;

	if (_kbhit())
	{
		key = _getch();

		if (key == -32)
		{
			key = _getch();
		}

		switch (key)
		{
		case LEFT:if (player->x <= 51)return;
			player->x -= 15;
			break;
		case RIGHT:if (player->x >= 81)return;
			player->x += 15;
			break;
		}
		system("cls");
	}
}

void Create(Enemy* enemy)
{
	static int index = 0;

	for (int i = 0; i < index; i++)
	{
		gotoXY(enemy[i].x, enemy[i].y++);
		EnemyRender(&enemy[i]);
	}

	int random = rand() % 5;
	
	if (random == 4)
	{
		if (index <= 2)
		{
			index++;
		}
	}
}

int RandomX()
{
	srand(time(NULL));

	int x = rand() % 3;

	int randomX = 66;

	switch (x)
	{
	case 0: randomX -= 15;
		break;
	case 1 : randomX = 66;
		break;
	case 2 : randomX += 15;
		break;
	}
   

	return randomX;
}

int main()
{
	system("mode con cols=140 lines=38");

	Player player = {66,30 };
	Enemy enemy[3] = {RandomX(),1};

	CarInit();
	MapInit();

	enemy[0].y = 0;
	enemy[0].x = RandomX();

	while (1)
	{
		Keyboard(&player);
		
		Create(enemy);


		if (player.x == enemy[0].x && player.y == enemy[0].y)
		{
			break;
		}
		CarRender(&player);
		EnemyRender(&enemy[0]);
		MapRender();
		
	}


		//Sleep(100);
	
	
	return 0;
}