// Quick tricky
#include <stdio.h>

int W, H;
int result;
char map[51][51];
bool visited[51][51];
bool isSafe(int, int);
int countGold(int, int);
int P_x, P_y;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int first, last;
struct Point 
{
	int x;
	int y;
};
Point pQueue[2502];
void initQueue();
void enQueue(int, int);
Point deQueue();
bool isEmpty();

int main()

	while (scanf("%d %d", &W, &H) == 2)
	{
		for(int i = 0; i < H; i++)
		{
			scanf("%s", &map[i]);
			for(int j = 0; j < W; j++)
			{
				visited[i][j] = false;
				if (map[i][j] == 'P')
				{
					P_x = i;
					P_y = j;
				}
			}
		}
		// Find number of golds the player can get without risking
		result = 0;
		initQueue();
		enQueue(P_x, P_y);
		Point tmp;
		int tx, ty;
		while (!isEmpty())
		{
			tmp = deQueue();
			if (!isSafe(tmp.x, tmp.y))
			{
				continue;
			}
			result += countGold(tmp.x, tmp.y);
			for(int k = 0; k < 4; k++)
			{
				tx = tmp.x + dx[k];
				ty = tmp.y + dy[k];
				if (tx >= 0 && tx < H && ty >= 0 && ty < W && visited[tx][ty] == false && map[tx][ty] == '.')
				{
					visited[tx][ty] = true;
					enQueue(tx, ty);
				}
			}
		}
		// Show output
		printf("%d\n", result);
	}
	return 0;
}
bool isSafe(int x, int y)
{
	int tx, ty;
	for(int k = 0; k < 4; k++)
	{
		tx = x + dx[k];
		ty = y + dy[k];
		if (tx >= 0 && tx < H && ty >= 0 && ty < W && map[tx][ty] == 'T')
		{
			return false;
		}
	}
	return true;
}
int countGold(int x, int y)
{
	int sum = 0;
	int tx, ty;
	for(int k = 0; k < 4; k++)
	{
		tx = x + dx[k];
		ty = y + dy[k];
		if (tx >= 0 && tx < H && ty >= 0 && ty < W && map[tx][ty] == 'G')
		{
			sum += 1;
			map[tx][ty] = '.';
		}
	}
	return sum;
}
void initQueue()
{
	first = -1;
	last = -1;
}
void enQueue(int x, int y)
{
	Point tmp;
	tmp.x = x;
	tmp.y = y;
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
	return (first == last);
}