/* Very easy */
#include <stdio.h>

int main()
{
	unsigned int testCase;
	unsigned int a, b;
	unsigned int total;
	unsigned int i, j;

	scanf("%u", &testCase);
	for (i = 1; i <= testCase; i++)
	{
		total = 0;
		scanf("%u %u", &a, &b);
		for (j = a; j <= b; j++)
		{
			if (j % 2 != 0)
			{
				total += j;
			}
		}
		printf("Case %u: %u\n", i, total);
	}
	
	return 0;
}