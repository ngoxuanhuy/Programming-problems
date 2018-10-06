#include <stdio.h>
int N;
int n;
int matrix[15][15];
int numOfZeros;
bool found;
void backtrack(int, int, int);
bool canFillRow(int, int);
bool canFillCol(int, int);
bool canFillSquare(int, int, int, int);
int main()
{
	//freopen("input.txt", "r", stdin);
	int tc = 0;
	while (scanf("%d", &n) == 1)
	{
		N = n * n;
		tc++;
		if (tc != 1)
			printf("\n");
		numOfZeros = 0;
		for(int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				scanf("%d", &matrix[i][j]);
				if (matrix[i][j] == 0)
					numOfZeros++;
			}
		}
		found = false;
		backtrack(1, 1, numOfZeros);
		if (found == false)
			printf("NO SOLUTION\n");
		else
		{
			for(int i = 1; i <= N; i++)
			{
				printf("%d", matrix[i][1]);
				for(int j = 2; j <= N; j++)
					printf(" %d", matrix[i][j]);
				printf("\n");
			}
		}
	}
	return 0;
}
void backtrack(int x, int y, int num)
{
	if(found) return;
	if (num == 0)
	{
		found = true;
		return;
	}
	if (y == N+1)
	{
		y =  1;
		x++;
		if (x == N+1)
			return;
	}
	if (matrix[x][y] != 0)
	{
		backtrack(x, y+1, num);
	}
	else
	{
		for(int i = 1; i <= N; i++)
		{
			if (canFillRow(x, i) && canFillCol(y, i) && canFillSquare(x, y, i, n))
			{
				matrix[x][y] = i;
				backtrack(x, y+1, num-1);
				if (found == true) return;
				matrix[x][y] = 0;
			}
		}
	}
}
bool canFillRow(int x, int value)
{
	for(int j = 1; j <= N; j++)
	{
		if (matrix[x][j] == value)
			return false;
	}
	return true;
}
bool canFillCol(int y, int value)
{
	for(int i = 1; i <= N; i++)
	{
		if (matrix[i][y] == value)
			return false;
	}
	return true;
}
bool canFillSquare(int x, int y, int value, int size)
{
	if (size == 1)
		return true;
	if (size == 2)
	{
		int remain_x = x % n;
		int remain_y = y % n;
		if (remain_x == 1)
		{
			if (remain_y == 1)
			{
				for(int i = x; i <= x+1; i++)
					for(int j = y; j <= y+1; j++)
						if (matrix[i][j] == value) return false;
			}
			else
			{
				for(int i = x; i <= x+1; i++)
					for(int j = y-1; j <= y; j++)
						if (matrix[i][j] == value) return false;
			}
		}
		else
		{
			if (remain_y == 1)
			{
				for(int i = x-1; i <= x; i++)
					for(int j = y; j <= y+1; j++)
						if (matrix[i][j] == value) return false;
			}
			else
			{
				for(int i = x-1; i <= x; i++)
					for(int j = y-1; j <= y; j++)
						if (matrix[i][j] == value) return false;
			}
		}
		return true;
	}
	else
	{
		int remain_x = x % n;
		int remain_y = y % n;
		if (remain_x == 1)
		{
			if (remain_y == 1)
			{
				for(int i = x; i <= x+2; i++)
					for(int j = y; j <= y+2; j++)
						if (matrix[i][j] == value) return false;
			}
			else if (remain_y == 2)
			{
				for(int i = x; i <= x+2; i++)
					for(int j = y-1; j <= y+1; j++)
						if (matrix[i][j] == value) return false;
			}
			else
			{
				for(int i = x; i <= x+2; i++)
					for(int j = y-2; j <= y; j++)
						if (matrix[i][j] == value) return false;
			}
		}
		else if (remain_x == 2)
		{
			if (remain_y == 1)
			{
				for(int i = x-1; i <= x+1; i++)
					for(int j = y; j <= y+2; j++)
						if (matrix[i][j] == value) return false;
			}
			else if (remain_y == 2)
			{
				for(int i = x-1; i <= x+1; i++)
					for(int j = y-1; j <= y+1; j++)
						if (matrix[i][j] == value) return false;
			}
			else
			{
				for(int i = x-1; i <= x+1; i++)
					for(int j = y-2; j <= y; j++)
						if (matrix[i][j] == value) return false;
			}
		}
		else
		{
			if (remain_y == 1)
			{
				for(int i = x-2; i <= x; i++)
					for(int j = y; j <= y+2; j++)
						if (matrix[i][j] == value) return false;
			}
			else if (remain_y == 2)
			{
				for(int i = x-2; i <= x; i++)
					for(int j = y-1; j <= y+1; j++)
						if (matrix[i][j] == value) return false;
			}
			else
			{
				for(int i = x-2; i <= x; i++)
					for(int j = y-2; j <= y; j++)
						if (matrix[i][j] == value) return false;
			}
		}
		return true;
	}
	
	 
}