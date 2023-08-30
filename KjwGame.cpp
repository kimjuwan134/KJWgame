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
	strcpy(map[0], "��");
	strcpy(map[1], "��");
	strcpy(map[2], "��");
	strcpy(map[3], "��");
	strcpy(map[4], "��");
	strcpy(map[5], "��");
	strcpy(map[6], "��");
	strcpy(map[7], "��");
	strcpy(map[8], "��");
	strcpy(map[9], "��");
	strcpy(map[10], "��");
	strcpy(map[11], "��");
	strcpy(map[12], "��");
	strcpy(map[13], "��");
	strcpy(map[14], "��");
	strcpy(map[15], "��");
	strcpy(map[16], "��");
	strcpy(map[17], "��");
	strcpy(map[18], "��");
	strcpy(map[19], "��");
	strcpy(map[20], "��");
	strcpy(map[21], "��");
	strcpy(map[22], "��");
	strcpy(map[23], "��");
	strcpy(map[24], "��");
	strcpy(map[25], "��");
	strcpy(map[26], "��");
	strcpy(map[27], "��");
	strcpy(map[28], "��");
	strcpy(map[29], "��");

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
	strcpy(car[2], "��-----��");
	strcpy(car[3], "��-----��");
	strcpy(car[4], "��-----��");
	strcpy(car[5], "��_____��");
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
	//��     ��
	//��     ��
	//��     ��
	//��_____��
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