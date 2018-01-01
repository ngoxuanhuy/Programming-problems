#include <stdio.h>

int const MAX_TRACKS = 25;
int trackLength[MAX_TRACKS];
int n, numOfTracks, i;
int bitmask, total;

void Choose(int currentTotal, int currentBitmask, int currentIndex)
{
	if (currentTotal > n)
	{
		return;
	}
	if (currentTotal > total) {
		total = currentTotal;
		bitmask = currentBitmask;
	}
	if (currentIndex >= numOfTracks)
	{
		return;
	}
	Choose(currentTotal + trackLength[currentIndex], currentBitmask | (1 << currentIndex), currentIndex + 1);
	Choose(currentTotal, currentBitmask, currentIndex + 1);
}

int main()
{
	while (scanf("%d %d", &n, &numOfTracks) != EOF)
	{
		for (i = 0; i < numOfTracks; i++)
		{
			scanf("%d", &trackLength[i]);
		}
		total = -1, bitmask = -1;
		Choose(0, 0, 0);

		for (i = 0; i < numOfTracks; i++) {
			if ((bitmask >> i) % 2)
				printf("%d ", trackLength[i]);
		}
		printf("sum:%d\n", total);
	}
	return 0;
}