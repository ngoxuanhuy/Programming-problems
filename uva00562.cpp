/* 0-1 Knapsack (Subset Sum)
use min() function*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

using namespace std;

int memo[110][50000];
int TC, m, i, sum, ans;
int cointValue[110];

int backtrack(int type, int amountOfMoney)
{
	if (type == m)
		return abs((sum - amountOfMoney) - amountOfMoney);
	if (memo[type][amountOfMoney] != -1)
		return memo[type][amountOfMoney];
	memo[type][amountOfMoney] = min(backtrack(type + 1, amountOfMoney + cointValue[type]), backtrack(type + 1, amountOfMoney));
	return memo[type][amountOfMoney];
}

int main()
{
	scanf("%d", &TC);
	while (TC--)
	{
		sum = 0;
		memset(memo, -1, sizeof memo);
		scanf("%d", &m);
		for (i = 0; i < m; i++)
		{
			scanf("%d", &cointValue[i]);
			sum += cointValue[i];
		}
		ans = backtrack(0, 0);
		printf("%d\n", ans);
	}
	return 0;
}