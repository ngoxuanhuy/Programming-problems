#include <stdio.h>
int T, N;
int matrix[20][20];
int result;
void DFS(int, int, int);
void switching(int, int);
int check(int, int);
int main()
{
	//freopen("sample_input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d", &N);
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				scanf("%d", &matrix[i][j]);
		result = 2147483647;
		DFS(0, 0, 0);
		if (result == 2147483647)
			result = -1;
		printf("Case %d: %d\n", tc, result);
	}
	return 0;
}
void DFS(int x, int y, int step)
{
	if (step >= result) return;
	if (y == N)
	{
		y = 0;
		x++;
	}
	if (x == 0)
	{
		DFS(x, y+1, step);
		if (matrix[x][y] == 0)
		{
			switching(x, y);
			DFS(x, y+1, step+1);
			switching(x, y);
		}
	}
	else if (x < N)
	{
		if (check(x-1, y))
		{
			if (matrix[x][y] == 0)
			{
				switching(x, y);
				DFS(x, y+1, step+1);
				switching(x, y);
			}
		}
		else
		{
			DFS(x, y+1, step);
		}
	}
	else
	{
		for(int j = 0; j < N; j++)
			if (check(x-1, j))
				return;
		result = result > step ? step : result;
	}
}
void switching(int x, int y)
{
	matrix[x][y] = !matrix[x][y];
}
int check(int x, int y)
{
	int numOfOnes = 0;
	if (x-1 >= 0) numOfOnes += matrix[x-1][y];
	if (x+1 < N) numOfOnes += matrix[x+1][y];
	if (y-1 >= 0) numOfOnes += matrix[x][y-1];
	if (y+1 < N) numOfOnes += matrix[x][y+1];
	return numOfOnes & 1;
}
