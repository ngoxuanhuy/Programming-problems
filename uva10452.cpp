// Recursive Backtracking (Very easy)
#include <stdio.h>

int T, N, M;
int result[8];
char matrix[12][12];
int start_y, end;

int dx[] = {-1, 0, 0};
int dy[] = {0, 1, -1};

void readInput();
void findPath(int, int, int);
void printOutput();

const char path[10] = "IEHOVA#";

int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		readInput();
		findPath(N, start_y, 0);
		printOutput();
	}
	return 0;
}

void readInput()
{
	int i, j;
	char newLine;
	scanf("%d %d", &N, &M);
	scanf("%c", &newLine);
	for(i = 1; i <= N; i++)
	{
		for(j = 1; j <= (M+1); j++)
		{
			scanf("%c", &matrix[i][j]);
		}
	}
	// Find start and end postions
	for(j = 1; j <= (M+1); j++)
	{
		if (matrix[N][j] == '@')
			start_y = j;
	}
}
void findPath(int x, int y, int index)
{
	if (index == 8)
	{
		return; 
	}
	int tx, ty;
	for(int k = 0; k < 3; k++)
	{
		tx = x + dx[k];
		ty = y + dy[k];
		if (tx >= 1 && ty >= 1 && ty <= M && matrix[tx][ty] == path[index])
		{
			if (ty < y)
			{
				result[index+1] = -1;
			}
			else if (ty > y)
			{
				result[index+1] = 1;
			}
			else
			{
				result[index+1] = 0;
			}
			findPath(tx, ty, index+1);
		}
	}
}
void printOutput()
{
	if (result[1] == -1)
		printf("left");
	else if (result[1] == 0)
		printf("forth");
	else
		printf("right");
	for(int i = 2; i <= 7; i++)
	{
		if (result[i] == -1)
			printf(" left");
		else if (result[i] == 0)
			printf(" forth");
		else
			printf(" right");
	}
	printf("\n");
}