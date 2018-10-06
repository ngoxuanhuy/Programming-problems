// Very easy
// Using 4 loop
#include <stdio.h>

int N;
int matrix[11][11];
bool visited[11][11];
void calculate(int, int);

int main()
{
	int tc = 0;
	while(1)
	{
		scanf("%d", &N);
		if (N == 0) break;
		tc++;
		for(int i = 1; i <= N; i++)
		{
			for(int j = 1; j <= N; j++)
			{
				visited[i][j] = false;
				scanf("%d", &matrix[i][j]);
			}
		}
		printf("Case %d:", tc);
		if (N % 2 == 0)
		{
			for(int i = 1; i <= N/2; i++)
			{
				calculate(i, i);
			}
		}
		else
		{
			for(int i = 1; i <= N/2 + 1; i++)
			{
				calculate(i, i);
			}
		}
		printf("\n");
	}
	return 0;
}
void calculate(int index_x, int index_y)
{
	int x, y;
	int sum = matrix[index_x][index_y];
	visited[index_x][index_y] = true;
	// Move from left to right
	x = index_x;
	y = index_y;
	while (1)
	{
		if (y+1 > N || visited[x][y+1] == true)
			break;
		y++;
		visited[x][y] = true;
		sum += matrix[x][y];
	}
	// Move from top to bottom
	while (1)
	{
		if (x+1 > N || visited[x+1][y] == true)
			break;
		x++;
		visited[x][y] = true;
		sum += matrix[x][y];
	}
	// Move from right to left
	while (1)
	{
		if (y-1 < 1 || visited[x][y-1] == true)
			break;
		y--;
		visited[x][y] = true;
		sum += matrix[x][y];
	}
	// move form bottom to top
	while (1)
	{
		if (x-1 < 1 || visited[x-1][y] == true)
			break;
		x--;
		visited[x][y] = true;
		sum += matrix[x][y];
	}
	printf(" %d", sum);
}