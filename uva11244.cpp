// Flood Fill
#include <stdio.h>

int dx[]={1, 1, 0, -1, -1, -1, 0, 1};
int dy[]={0, 1, 1, 1, 0, -1, -1, -1};

int R, C;
int result;
char sky[101+2][101+2];

bool isNotAStart(int, int);

int main()
{
	while (scanf("%d %d", &R, &C) == 2)
	{
		if (R == 0 || C == 0)
			break;
		for(int i = 0; i < R; i++)
		{
			scanf("%s", &sky[i]);
		}
		result = 0;
		for(int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				if (sky[i][j] == '*' && !isNotAStart(i, j))
					result++;
			}
		}
		printf("%d\n", result);
	}
	return 0;
}

bool isNotAStart(int x, int y)
{
	int tx, ty;
	for(int k = 0; k < 8; k++)
	{
		tx = x + dx[k];
		ty = y + dy[k];
		if (tx >= 0 && tx < R && ty >= 0 && ty < C)
		{
			if (sky[tx][ty] == '*')
				return true;
		}
	}
	return false;
}