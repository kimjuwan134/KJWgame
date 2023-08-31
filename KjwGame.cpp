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
	for (int i = 0; i <= player->x; i++)
	{
		gotoXY(player->x, i+player->y);
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
		case LEFT:if (player->x <= 0)return;
			player->x -= 30;
			break;
		case RIGHT:if (player->x >= 200)return;
			player->x += 30;
			break;
		}
		system("cls");
	}
}

int RandomX()
{
	srand(time(NULL));

	int x = rand() % 200;

	if (x % 2 == 1)
	{
		x += 1;
	}

	return x;
}
	//  _____ 
	// /     \
	//び     び
	//び     び
	//び     び
	//び_____び
int main()
{
	system("mode con cols=140 lines=38");

	Player player = { 60,40 };
	Enemy enemy = { 3,1 };

	CarInit();
	MapInit();


	
	
	while (1)
	{
		MapRender();
		//CarRender(&player);
		//Keyboard(&player);
		//Sleep(100);
	}
	
	return 0;
}