// Easy
#include <stdio.h>
int a, b, c, d, e;
int num[5];
bool visited[5];
bool found;
void DFS(int count, int total)
{
	if (count == 5)
	{
		if (total == 23)
		{
			found = true;
		}
		return;
	}
	for(int i = 0; i < 5; i++)
	{
		if (visited[i])
		{
			continue;
		}
		visited[i] = true;
		DFS(count+1, total * num[i]);
		DFS(count+1, total + num[i]);
		DFS(count+1, total - num[i]);
		visited[i] = false;
	}
}
int main()
{
	//freopen("input.txt", "r", stdin);
	while (scanf("%d %d %d %d %d", &a, &b, &c, &d, &e))
	{
		if (a == 0 && b == 0 && c == 0 && d == 0 && e == 0)
		{
			break;
		}
		num[0] = a;
		num[1] = b;
		num[2] = c;
		num[3] = d;
		num[4] = e;
		found = false;
		for(int i = 0; i < 5; i++)
		{
			if (found)
			{
				break;
			}
			visited[i] = true;
			DFS(1, num[i]);
			visited[i] = false;
		}
		if (found)
		{
			printf("Possible\n");
		}
		else
		{
			printf("Impossible\n");
		}
	}
	return 0;
}