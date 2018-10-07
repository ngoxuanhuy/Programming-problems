#include <stdio.h>
int T;
int N;

int count[10];
void reset();
void counting();
void showOutput();

int main()
{
	scanf("%d", &T);
	while(T > 0)
	{
		reset();
		scanf("%d", &N);
		counting();
		showOutput();
		T--;
	}
	return 0;
}

void reset()
{
	for(int i = 0; i <= 9; i++)
		count[i] = 0;
}

void counting()
{
	int number = 1;
	int temp;
	while (number <= N)
	{
		temp = number;
		while (temp != 0)
		{
			count[temp % 10]++;
			temp /= 10;
		}
		number++;
	}
}

void showOutput()
{
	printf("%d", count[0]);
	for(int i = 1; i <= 9; i++)
		printf(" %d", count[i]);
	printf("\n");
}
