// 8-queen chess problem
#include <stdio.h>
int k;
int chess[10][10];
int col[10];
int result;
void readInput();
void findMaxPoint(int);
void showOutput();
void resetArray();
bool canPlace(int, int);
void placeQueen(int);
int absolute(int, int);
int findTotal();
int main()
{
	//freopen("input.txt", "r", stdin);
	scanf("%d", &k);
	for(int i = 1; i <= k; i++)
	{
		readInput();
		result = 0;
		resetArray();
		findMaxPoint(0);
		showOutput();
	}
	return 0;
}
void readInput()
{
	for(int r = 0; r < 8; r++)
	{
		for(int c = 0; c < 8; c++)
		{
			scanf("%d", &chess[r][c]);
		}
	}
}
void findMaxPoint(int r)
{
	if (r == 8)
	{
		int sum = findTotal();
		result = result < sum ? sum : result;
		return;
	}
	for(int c = 0; c < 8; c++)
	{
		if (canPlace(r, c))
		{
			col[r] = c;
			findMaxPoint(r+1);
		}
	}
}
bool canPlace(int row, int column)
{
	for(int r = row-1; r >= 0; r--)
	{
		if (col[r] == column) return false;
		if (absolute(col[r],column) == absolute(r,row)) return false;
	}
	return true;
}
void showOutput()
{
	printf("%5d\n", result);
}
void resetArray()
{
	for(int i = 0; i < 8; i++)
	{
		col[i] = 0;
	}
}
int absolute(int a, int b)
{
	if (a < b)
		return b - a;
	return a - b;
}
int findTotal()
{
	int sum = 0;
	for(int i = 0; i < 8; i++)
	{
		sum += chess[i][col[i]];
	}
	return sum;
}