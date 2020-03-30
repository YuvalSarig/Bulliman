#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include"buildgame.h"

void main()
{
	int a;
	String s;
	gameboard gb;
	buli b;
	buli *b1 = &b;
	bear be;
	bear *be1 = &be;
	startgame(gb, &b, &be);
	while (turn(gb, &b, &be,s))
	{
		
	}
	printf("%s", s);
	scanf("%d", &a);
}
