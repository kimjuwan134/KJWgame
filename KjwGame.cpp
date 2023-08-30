#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define CAR_WIDTH 12
#define CAR_HEIGHT 6
#define MAP_WIDTH 1
#define MAP_HEIGHT 30

char car[CAR_HEIGHT][CAR_WIDTH];
char map[MAP_HEIGHT][MAP_WIDTH];

void gotoXY(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
}

void MapInit()
{
	strcpy(map[0], "び");
	strcpy(map[1], "び");
	strcpy(map[2], "び");
	strcpy(map[3], "び");
	strcpy(map[4], "び");
	strcpy(map[5], "び");
	strcpy(map[6], "び");
	strcpy(map[7], "び");
	strcpy(map[8], "び");
	strcpy(map[9], "び");
	strcpy(map[10], "び");
	strcpy(map[11], "び");
	strcpy(map[12], "び");
	strcpy(map[13], "び");
	strcpy(map[14], "び");
	strcpy(map[15], "び");
	strcpy(map[16], "び");
	strcpy(map[17], "び");
	strcpy(map[18], "び");
	strcpy(map[19], "び");
	strcpy(map[20], "び");
	strcpy(map[21], "び");
	strcpy(map[22], "び");
	strcpy(map[23], "び");
	strcpy(map[24], "び");
	strcpy(map[25], "び");
	strcpy(map[26], "び");
	strcpy(map[27], "び");
	strcpy(map[28], "び");
	strcpy(map[29], "び");

}

void MapRender()
{
	for (int i = 0; i < MAP_HEIGHT; i++)
	{
		for (int j = 0; j < MAP_WIDTH; j++)
		{
			printf("%c", map[i][j]);
		}
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

void CarRender()
{
	for (int i = 0; i <= 5; i++)
	{
		gotoXY(5, i+5);
		printf("%s", car[i]);
	}

	for (int i = 0; i < CAR_HEIGHT; i++)
	{
		for (int j = 0; j < CAR_WIDTH; j++)
		{
			//printf("%c", car[i][j]);
		}

		printf("\n");
	}
}

struct Player
{
	int x, y;
};

struct Enemy
{
	int x, y;
};


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
			player->x -= 2;
			break;
		case RIGHT:if (player->x >= 199)return;
			player->x += 2;
			break;
		}
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

	CarInit();
	MapInit();

	Player player = { 5,5 };
	Enemy enemy = { 3,1 };
	
	// gotoXY(3, 3);
	// MapRender();
	
	CarRender();
	

	// printf("%s", player.shape);

	//while (1)
	//{
	//	Keyboard(&player);
	//
	//}
	
	return 0;
}