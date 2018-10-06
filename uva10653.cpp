// Use BFS to find the shortest path
#include <stdio.h>

int R, C;
int r, c;
int start_x, start_y, end_x, end_y;
int numOfBombs;
int result;
int numOfRowsHasBombs;
int map[1000+1][1000+1];
bool visited[1000+1][1000+1];
struct Point
{
	int x;
	int y;
	int step;
};
Point pQueue[1000003];
int first, last;
void initQueue();
void enQueue(int, int, int);
Point deQueue();
bool isEmpty();

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main()
{
	//freopen("input.txt", "r", stdin);
	while (1)
	{
		scanf("%d %d", &R, &C);
		if (R == 0 && C == 0) break;
		scanf("%d", &numOfRowsHasBombs);
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				map[i][j] = 0;
				visited[i][j] = false;
			}
		}
		for(int i = 1; i <= numOfRowsHasBombs; i++)
		{
			scanf("%d", &r);
			scanf("%d", &numOfBombs);
			for(int j = 1; j <= numOfBombs; j++)
			{
				scanf("%d", &c);
				map[r][c] = 1;
			}
		}
		scanf("%d %d", &start_x, &start_y);
		scanf("%d %d", &end_x, &end_y);
		result = -1;
		// Find min path
		initQueue();
		enQueue(start_x, start_y, 0);
		Point tmp;
		int tx, ty;
		while (!isEmpty())
		{
			tmp = deQueue();
			if (tmp.x == end_x && tmp.y == end_y)
			{
				result = tmp.step;
				break;
			}
			for(int k = 0; k < 4; k++)
			{
				tx = tmp.x + dx[k];
				ty = tmp.y + dy[k];
				if (tx >= 0 && tx < R && ty >= 0 && ty < C && map[tx][ty] == 0 && visited[tx][ty] == false)
				{
					visited[tx][ty] = true;
					enQueue(tx, ty, tmp.step+1);
				}
			}
		}
		printf("%d\n", result);
	}
	return 0;
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