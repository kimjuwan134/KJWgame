#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <conio.h>

#define LEFT 75
#define RIGHT 77

struct Player
{
	int x, y;
	const char* shape;
};

struct Enemy
{
	int x, y;
	const char* shape;
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
		case RIGHT:if (player->x >= 28)return;
			player->x += 2;
			break;
		}
	}
}

int RandomX()
{
	srand(time(NULL));

	int x = rand() % 31;

	if (x % 2 == 1)
	{
		x += 1;
	}

	return x;
}

int main()
{
	system("mode con cols=5 lines=5");

	Player player = { 2,4,"бс" };
	Enemy enemy = { 3,1,"бр" };

	while (1)
	{
		Keyboard(&player);
	}
	
	return 0;
}