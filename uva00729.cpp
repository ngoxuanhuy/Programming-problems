// Quite tricky
#include <stdio.h>
int T, N, H;
int count;
int combination[20];
int result[1000005][16];
void backtrack(int, int, int);
void printCombinations();
void pushToResultArray(int);
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &T);
	for(int tc = 1; tc <= T; tc++)
	{
		scanf("%d%d", &N, &H);
		count = 0;
		for(int i = 1; i >= 0; i--)
		{
			backtrack(1, i, i);
		}
		printCombinations();
		if (tc < T)
		{
			printf("\n");
		}
	}
	return 0;
}
void backtrack(int index, int value, int total)
{
	combination[index] = value;
	if (index == N)
	{
		if (total == H)
		{
			pushToResultArray(++count);
		}
		return;
	}
	for(int i = 1; i >= 0; i--)
	{
		backtrack(index+1, i, total+i);
	}
}
void pushToResultArray(int index)
{
	for(int i = 1; i <= N; i++)
	{
		result[index][i] = combination[i]; 
	}
}
void printCombinations()
{
	for(int index = count; index >= 1; index--)
	{
		for(int j = 1; j <= N; j++)
		{
			printf("%d", result[index][j]);
		}
		printf("\n");
	}
}