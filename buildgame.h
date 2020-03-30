#define matsize 12
#define wall '#'
#define point '.'
#define buli1 'B'
#define bear1 'D'
typedef char gameboard[matsize][matsize];
typedef char String[256];
typedef struct 
{
	int x;
	int y;
	int lastmove;
	int counter;
}buli;

typedef struct
{
	int x;
	int y;
}bear;


void startgame(gameboard gb, buli *b, bear *be);
int turn(gameboard gb, buli *b, bear *be, String st);

