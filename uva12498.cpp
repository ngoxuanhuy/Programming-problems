/* Not done */
#include <math.h>
#include <iostream>

using namespace std;
char position[55][55];

int main()
{
	int T;
	int R, C;
	int i, j, k, temp;
	int testCase;
	int left, right;
	int result, num_of_moves;
	cin >> T;
	for (testCase = 1; testCase <= T; i++)
	{
		cin >> R >> C;
		for (i = 0; i < R; i++)
		{
			for (j = 0; j < C; j++)
			{
				cin >> position[i][j];
			}
		}
		result = 100000;
		for (j = 0; j < C; j++)
		{
			num_of_moves = 0;
			k = 0;
			while (k < R)
			{
				if (position[k][j] == '0')
				{
					k++;
				}
				else
				{
					for (left = (j - 1); left >= 0; left--)
					{
						if (position[k][left] == '0')
							break;
					}
					for (right = (j + 1); right < C; right++)
					{
						if (position[k][right] == '0')
							break;
					}
					if (left >= 0)
					{
						if (right == C)
						{
							k++;
							num_of_moves += (j - left);
							continue;
						}
						else
						{
							k++;
							num_of_moves += ((j - left) < (right - j) ? (j-left) : (right - j));
						}
					}
					else
					{
						if (right == C)
							break;
						else
						{
							k++;
							num_of_moves += (right - j);
						}
					}
				}
			}
			if (k == R)
			{
				result = num_of_moves < result ? num_of_moves: result;
			}
		}
		if (result == 100000)
		{
			cout << "Case " << testCase << ": " << -1 << endl;
		}
		else
		{
			cout << "Case " << testCase << ": " << result << endl;
		}
	}
	return 0;
}