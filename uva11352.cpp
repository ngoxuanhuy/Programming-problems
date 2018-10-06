// pre-calculate every trap positions first
#include <stdio.h>
int T, M, N;
int forest[110][110];
int trap[110][110];
int visited[110][110];
int first, last;
int result;
int knight_dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int knight_dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int king_dx[] = {-1, -1, -1, 0, 1, 1, 1, 0};
int king_dy[] = {-1, 0, 1, 1, 1, 0, -1, -1};
int A_x, A_y, B_x, B_y;
struct Point
{
	int x;
	int y;
	int step;
};
Point pQueue[10010];
void initQueue();
Point deQueue();
void enQueue(int, int, int);
bool isEmpty();
void readInput();
void findPath();
void showOutput();
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		readInput();
		result = -1;
		findPath();
		showOutput();
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
void readInput()
{
	scanf("%d %d", &M, &N);
	char t;
	int tx, ty;
	scanf("%c", &t);
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			trap[i][j] = 0;
		}
	}
	for(int i = 0; i < M; i++)
	{
		for(int j = 0; j < N; j++)
		{
			visited[i][j] = false;
			scanf("%c", &forest[i][j]);
			if (forest[i][j] == 'Z')
			{
				trap[i][j] = 1;
				for(int k = 0; k < 8; k++)
				{
					tx = i + knight_dx[k];
					ty = j + knight_dy[k];
					if (tx >= 0 && tx < M && ty >= 0 && ty < N)
					{
						trap[tx][ty] = 1;
					}
				}
			}
			else if (forest[i][j] == 'A')
			{
				A_x = i;
				A_y = j;
			}
			else if (forest[i][j] == 'B')
			{
				B_x = i;
				B_y = j;
			}
		}
		scanf("%c", &t);
	}
}
void findPath()
{
	initQueue();
	enQueue(A_x, A_y, 0);
	visited[A_x][A_y] = true;
	Point tmp;
	int tx, ty;
	while (!isEmpty())
	{
		tmp = deQueue();
		for(int k = 0; k < 8; k++)
		{
			tx = tmp.x + king_dx[k];
			ty = tmp.y + king_dy[k];
			if (tx == B_x && ty == B_y)
			{
				result = tmp.step+1;
				return;
			}
			if (tx >= 0 && tx <= M-1 && ty >= 0 && ty <= N-1 && visited[tx][ty] == false && trap[tx][ty] == 0)
			{
				visited[tx][ty] = true;
				enQueue(tx, ty, tmp.step+1);
			}
		}
	}
}
void showOutput()
{
	if (result == -1)
	{
		printf("King Peter, you can't go now!\n");
	}
	else
	{
		printf("Minimal possible length of a trip is %d\n", result);
	}
}