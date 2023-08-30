#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77
#define CAR_WIDTH 7
#define CAR_HEIGHT 6

char car[CAR_WIDTH][CAR_HEIGHT];

struct Player
{
	int x, y;
	strcpy(car[0][], "  ____ ");
	strcpy(car[1], "  ____ ");
};

struct Enemy
{
	int x, y;
};

void gotoXY(int x, int y)
{
	COORD position = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
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
	system("mode con cols=200 lines=50");

	Player player = { 2,4,strcpy(car[][CAR_HEIGHT])};
	Enemy enemy = { 3,1,"÷" };

	while (1)
	{
		Keyboard(&player);

	}
	
	return 0;
}