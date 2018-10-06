#include <stdio.h>
int T, N, M;
int result;
int matrix[64][64];
bool visited[64][64];
void readInput();
void findPath(int, int, int);
void showOutput();
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		readInput();
		result = 0;
		findPath(0, 0, 1);
		findPath(0, 0, 0);
		showOutput();
	}
	return 0;
}
void readInput()
{
	scanf("%d %d", &N, &M);
	char s[4][500];
	int i, j;
	while (getchar() != '\n');
	while (getchar() != '\n');
	for(i = 0; i < N; i++)
	{
		for(j = 0; j < 4; j++)
			gets(s[j]);
		for(int j = 0, k = 1; j < M; j++, k+=4)
		{
			if (s[1][k] == ' ')
				matrix[i][j] = 0;	// Empty blank
			else if (s[1][k+2] == ' ')
				matrix[i][j] = 2;	// corner
			else
				matrix[i][j] = 1;	// line
		}
	}
}
void findPath(int x, int y, int direction)
{
	if (x == N-1 && y == M-1)
	{
		result++;
		return;
	}
	if (matrix[x][y] == 0)
	{
		return;
	}
	visited[x][y] = true;
	if (direction == 0)
	{
		if (x-1 >= 0 && !visited[x-1][y])
		{
			if (matrix[x-1][y] == 1)
			{
				findPath(x-1, y, 0);
			}
			else if (matrix[x-1][y] == 2)
			{
				findPath(x-1, y, 1);
			}
		}
		if (x+1 < N && !visited[x+1][y])
		{
			if (matrix[x+1][y] == 1)
			{
				findPath(x+1, y, 0);
			}
			else if (matrix[x+1][y] == 2)
			{
				findPath(x+1, y, 1);
			}
		}
	}
	else
	{
		if (y-1 >= 0 && !visited[x][y-1])
		{
			if (matrix[x][y-1] == 1)
			{
				findPath(x, y-1, 1);
			}
			else if (matrix[x][y-1] == 2)
			{
				findPath(x, y-1, 0);
			}
		}
		if (y+1 < M && !visited[x][y+1])
		{
			if (matrix[x][y+1] == 1)
			{
				findPath(x, y+1, 1);
			}
			else if (matrix[x][y+1] == 2)
			{
				findPath(x, y+1, 0);
			}
		}
	}
	visited[x][y] = false;
}
void showOutput()
{
	printf("Number of solutions: %d\n", result);
}