#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"buildgame.h"
#include<string.h>
#include<stdlib.h>


void buildWalls(gameboard gb)
{
	int x, y;
	printf("enter 2 numbers for wall index(x,y)");
	scanf(" %d %d", &x, &y);
	while (x != 0 && y != 0)
	{
		gb[x][y] = wall;
		printf("enter 2 numbers for wall index(x,y)");
		scanf(" %d %d", &x, &y);
	}
	for (int i = 0; i < matsize; i++)
	{
		gb[0][i] = wall;
		gb[i][0] = wall;
		gb[matsize - 1][i] = wall;
		gb[i][matsize - 1] = wall;
	}
}
int fillpoints(gameboard gb)
{
	int count = 0;
	for (int i = 1; i < matsize - 1; i++)
	{
		for (int j = 1; j < matsize - 1; j++)
		{
			if (gb[i][j] != wall)
			{
				gb[i][j] = point;
				count++;
			}
		}
	}
	return count;
}
void insertbuli(gameboard gb, buli *b, int count)
{
	int x, y;
	printf("enter 2 numbers for buli index(x,y)");
	scanf("%d %d", &x, &y);
	if (gb[x][y] != wall)
	{
		(*b).x = x;
		b->y = y;
		b->counter = --count;
		b->lastmove = -1;
		gb[x][y] = ' ';
	}
}
void insertbear(gameboard gb, bear *be)
{
	int x, y;
	printf("enter 2 numbers for bear index(x,y)");
	scanf("%d %d", &x, &y);
	if (gb[x][y] != wall)
	{
		be->x = x;
		(*be).y = y;
	}
}
void printgameboard(gameboard gb, buli *b, bear *be)
{
	system("cls");
	for (int x = 1; x < matsize - 1; x++)
	{
		for (int y = 1; y < matsize - 1; y++)
		{
			if (b->x == x && b->y == y)
				printf("%c ", buli1);
			else if (be->x == x && be->y == y)
				printf("%c ", bear1);
			else
				printf("%c ", gb[x][y]);
		}
		printf("\n");
	}
}
void startgame(gameboard gb, buli *b, bear *be)
{
	int points;
	buildWalls(gb);
	points = fillpoints(gb);
	insertbuli(gb, &(*b), points);
	insertbear(gb, &(*be));
	printgameboard(gb, &(*b), &(*be));
}
void bulimovment(gameboard gb, buli *b)
{
	int move;
	printf("enter number 1 to move right, 2 to move left,3 upward,4 downkward, 0 countine in last movement\n");
	scanf("%d", &move);
	if (b->lastmove != -1 && move == 0)
	{
		move = b->lastmove;
	}
	switch (move)
	{
	case 4:
		if (gb[b->x + 1][b->y] != wall)
			b->x = b->x + 1;
		b->lastmove = 4;
		break;
	case 3:
		if (gb[b->x - 1][b->y] != wall)
			b->x = b->x - 1;
		b->lastmove = 3;
		break;
	case 2:
		if (gb[b->x][b->y - 1] != wall)
			b->y = b->y - 1;
		b->lastmove = 2;
		break;
	case 1:
		if (gb[b->x][b->y + 1] != wall)
			b->y = b->y + 1;
		b->lastmove = 1;
		break;
	}
	if (gb[b->x][b->y] == point)
	{
		gb[b->x][b->y] = ' ';
		b->counter--;
	}
}
void bearmovment(gameboard gb, buli *b, bear *be)
{
	int movex, movey;
	if ((b->x) - (be->x) == 0)
	{
		movex = 0;
	}
 	else if ((b->x) - (be->x) > 0)
	{
		movex = 1;
	}
	else if ((b->x) - (be->x) < 0)
	{
		movex = -1;
	}

	if ((b->y) - (be->y) == 0)
	{
		movey = 0;
	}
	else if ((b->y) - (be->y) > 0)
	{
		movey = 1;
	}
	else if ((b->y) - (be->y) < 0)
	{
		movey = -1;
	}
	if (gb[be->x + movex][be->y + movey] != wall)
	{
		be->y = be->y + movey;
		be->x = be->x + movex;
	}
}
int turn(gameboard gb, buli *b, bear *be, String st)
{
	if (b->counter == 0)
	{
		strcpy(st, "you have WON!!");
		return 0;
	}
	else if (b->x == be->x && be->y == b->y)
	{
		strcpy(st, "game over, try again");
		return 0;
	}
	bulimovment(gb, &(*b));
	bearmovment(gb, &(*b), &(*be));
	printgameboard(gb, &(*b), &(*be));
	return 1;
}
