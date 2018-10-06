#include <stdio.h>

int T, N, M;
int maze[105][105];
bool visited[105][105];
int start_y, end_y;
bool found;
void readInput();
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void DFS(int x, int y, int curValue, int finalValue)
{
	if (x < 1 || x > N || y < 1 || y > M) return;
	if (visited[x][y] == true) return;
	if (maze[x][y] != curValue) return;
	if (x == N)
	{
		found = true;
		end_y = end_y > y ? y : end_y;
		return;
	}
	if (curValue == finalValue)
	{
		finalValue++;
		curValue = 0;
	}
	visited[x][y] = true;
	for(int k = 0; k < 4; k++)
	{
		DFS(x + dx[k], y + dy[k], curValue+1, finalValue);
	}
	visited[x][y] = false;
}
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		readInput();
		found = false;
		for(int j = 1; j <= M; j++)
		{
			start_y = j;
			end_y = 2147483647;
			DFS(1, start_y, 1, 1);
			if (found)
				break;
		}
		printf("1 %d\n", start_y);
		printf("%d %d\n", N, end_y);
		if (tc != T)
		{
			printf("\n");
		}
	}
	return 0;
}
void readInput()
{
	scanf("%d %d", &N, &M);
	for(int i = 1; i <= N; i++)
	{
		for(int j = 1; j <= M; j++)
		{
			scanf("%d", &maze[i][j]);
		}
	}
}