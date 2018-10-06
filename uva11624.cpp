// Use BFS to pre-calculate the matrix of fire
#include <stdio.h>

int T, R, C;
int start_x, start_y;
int result;
char map[1000+2][1000+2];
int fireMap[1000+2][1000+2];
bool visited[1000+2][1000+2];
void readInput();
void preCalculate();
struct Point
{
	int x;
	int y;
	int step;
};
Point pQueue[1000002];
int first, last;
void initQueue();
void enQueue(int, int, int);
Point deQueue();
bool isEmpty();
void findResult();
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		readInput();
		preCalculate();
		result = -1;
		findResult();
		if (result == -1)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("%d\n", result);
		}
	}
	return 0;
}
void readInput()
{
	int t;
	scanf("%d %d", &R, &C);
	scanf("%c", &t);
	initQueue();
	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			visited[i][j] = false;
			fireMap[i][j] = 1000000;
			scanf("%c", &map[i][j]);
			if (map[i][j] == 'F')
			{
				fireMap[i][j] = 0;
				enQueue(i, j, 0);
			}
			else if (map[i][j] == 'J')
			{
				start_x = i;
				start_y = j;
			}
		}
		scanf("%c", &t);
	}
}
void preCalculate()
{
	int tx;
	int ty;
	Point tmp;
	while (!isEmpty())
	{
		tmp = deQueue();
		for(int k = 0; k < 4; k++)
		{
			tx = tmp.x + dx[k];
			ty = tmp.y + dy[k];
			if (tx < 0 || tx == R || ty < 0 || ty == C)
			{
				continue;
			}
			if (fireMap[tx][ty] == 1000000 && map[tx][ty] == '.')
			{
				fireMap[tx][ty] = fireMap[tmp.x][tmp.y] + 1;
				enQueue(tx, ty, 0);
			}
		}
	}
}
void initQueue()
{
	first = -1;
	last = -1;
}
void enQueue(int x, int y, int step)
{
	Point tmp;
	tmp.x = x;
	tmp.y = y;
	tmp.step = step;
	last++;
	pQueue[last] = tmp;
}
Point deQueue()
{
	if (!isEmpty())
	{
		first++;
		return pQueue[first];
	}
}
bool isEmpty()
{
	return first == last;
}
void findResult()
{
	initQueue();
	enQueue(start_x, start_y, 0);
	visited[start_x][start_y] = true;
	Point tmp;
	int tx, ty;
	while (!isEmpty())
	{
		tmp = deQueue();
		if (tmp.x == 0 || tmp.x == R-1 || tmp.y == 0 || tmp.y == C-1)
		{
			result = tmp.step + 1;
			return;
		}
		for(int i = 0; i < 4; i++)
		{
			tx = tmp.x + dx[i];
			ty = tmp.y + dy[i];
			if (tx >= 0 && tx <= R-1 && ty >= 0 && ty <= C-1 && visited[tx][ty] == false && map[tx][ty] == '.' && tmp.step+1 < fireMap[tx][ty])
			{
				visited[tx][ty] = true;
				enQueue(tx, ty, tmp.step+1);
			}
		}
	}
	return;
}