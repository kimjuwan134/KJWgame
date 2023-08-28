#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <windows.h>

#define MINE_COUNT 7
#define X_COUNT 6
#define Y_COUNT 6



INPUT_RECORD rec;
DWORD dwNOER;
HANDLE CIN = 0;

void click(int* xx, int* yy, int* lr) {
	while (1)
	{
		ReadConsoleInput(GetStdHandle(STD_INPUT_HANDLE), &rec, 1, &dwNOER); // �ܼ�â �Է��� �޾Ƶ���.
		if (rec.EventType == MOUSE_EVENT) {// ���콺 �̺�Ʈ�� ���

			if (rec.Event.MouseEvent.dwButtonState & FROM_LEFT_1ST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
				int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
				int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

				*xx = mouse_x; //x���� �ѱ�
				*yy = mouse_y; //y���� �ѱ�
				*lr = 1; //���콺 Ŭ�����¸� �ѱ�

				break;
			}
			else if (rec.Event.MouseEvent.dwButtonState & RIGHTMOST_BUTTON_PRESSED) { // ���� ��ư�� Ŭ���Ǿ��� ���
				int mouse_x = rec.Event.MouseEvent.dwMousePosition.X; // X�� �޾ƿ�
				int mouse_y = rec.Event.MouseEvent.dwMousePosition.Y; // Y�� �޾ƿ�

				*xx = mouse_x; //x���� �ѱ�
				*yy = mouse_y; //y���� �ѱ�
				*lr = 2; //���콺 Ŭ�����¸� �ѱ�

				break;
			}
		}
	}
}

void CreateMineTable(char mine_table[][X_COUNT], char check_table[][X_COUNT])
{
	int x, y, mine_count;
	// mine ������ ������ �޸𸮿� ��� 0�� ä���.

	memset(mine_table, 0, Y_COUNT * X_COUNT);
	// ������� ���� ������ ������ �޸𸮿� ��� 0�� ä���.
	
	memset(check_table, 0, Y_COUNT * X_COUNT);

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
					if ((x + 1) < X_COUNT && mine_table[y + 1][x + 1] == '*')
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

void ShowMineTable(char mine_table[][X_COUNT])
{
	printf("\n"); // �� �ٲ�
	for (int y = 0; y < Y_COUNT; y++)
	{
		// �� ���� ������ ���
		for (int x = 0; x < X_COUNT; x++)
		{
			printf("%c", mine_table[y][x]);	
		}
		printf("\n"); // �� �ٲ�
	}
	printf("\n"); // �� �ٲ�
}

void ShowCurrentState(char mine_table[][X_COUNT], char check_table[][X_COUNT])
{
	printf("\n"); // �� �ٲ�
	for (int y = 0; y < Y_COUNT; y++)
	{
		// �� ���� ������ ���
		for (int x = 0; x < X_COUNT; x++)
		{
			if (check_table[y][x]) 
				printf("%c", mine_table[y][x]);
			else
				printf("��");
		}
		printf("\n"); // �� �ٲ�
	}
	printf("\n"); // �� �ٲ�
}

int main()
{
	// ��ź�� ��ġ�� ������ ������ ����
	char mine_table[Y_COUNT][X_COUNT];

	// ����ڰ� ������ ��ġ�� ����� ����
	char check_table[Y_COUNT][X_COUNT];

	// ���� �ð��� �������� ������ ����
	srand((unsigned)time(NULL));

	// ��ź ��ġ ������ ����
	CreateMineTable(mine_table, check_table);
	
	// ���� ������ �ݿ��Ͽ� ���� ������ ���
	// @ ���ڷ� ��µ� ���� ���� Ȯ���� �ȵ� �׸�
	ShowCurrentState(mine_table, check_table);
	
	SetConsoleMode(GetStdHandle(STD_OUTPUT_HANDLE), ENABLE_PROCESSED_INPUT | ENABLE_MOUSE_INPUT);
	//���콺 �Է¸��� �ٲ�
	DWORD mode;
	CIN = GetStdHandle(STD_INPUT_HANDLE); //���콺 ��Ȱ��ȭ
	GetConsoleMode(CIN, &mode);
	SetConsoleMode(CIN, mode | ENABLE_MOUSE_INPUT);
	int xx, yy, lr;

	

	int x = 0;
	int y =0;
	while (1)
	{
		printf("Ȯ���� ��ġ�� x, y��ǥ�� �Է��ϼ���.\n");
		printf("������ �Է��ϸ� ������ ����˴ϴ�.\n");
		printf("x ��ǥ �Է� : ");
		click(&xx, &yy, &lr);
		printf("%2d %2d %2d\n", xx, yy, lr);
		// ������ �ԷµǾ����� ������ ����

		printf("y ��ǥ �Է� : ");
		// ������ �ԷµǾ����� ���� ����

		// ��ġ ������ ����� �Է��ߴ��� Ȯ��
		if (x < X_COUNT && y < Y_COUNT)
		{
			// �̹� Ȯ���� ��ġ���� üũ
			if (check_table[y][x] == 0)
			{
				// ����ڰ� ��ź�� ������ ���
				if (mine_table[y][x] == '*')
				{
					printf("��ź�� �����߽��ϴ�. �̼� ����!\n\n");
					break; // ���� �ߴ�
				}
				else
				{
					// ���������� ����
					check_table[y][x] = 1;
					// ���� ������ �ݿ��Ͽ� ���� ������ ���
					// @ ���ڷ� ��µ� ���� ���� Ȯ���� �ȵ� �׸�
					ShowCurrentState(mine_table, check_table);
				}
			}
			else printf("�̹� Ȯ���� ��ġ�Դϴ�.\n\n");
		}
		else printf("�߸��� ��ġ�� �Է��߽��ϴ�.\n\n");
	}

	 // ��ġ ������ Ȯ��
	ShowMineTable(mine_table);


	return 0;
}