/* Greedy algorithm
	Sorting the input first
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int knights, dragons;
	int currentHeadDiameter, currentKnightHeight;
	int gold, d, k;
	int i;
	vector<int> headDiameters, knightHeights;
	while (true)
	{
		cin >> dragons >> knights;
		if (dragons == 0 && knights == 0)
		{
			break;
		}

		// Input
		headDiameters.clear();
		knightHeights.clear();
		for (i = 0; i < dragons; i++)
		{
			cin >> currentHeadDiameter;
			headDiameters.push_back(currentHeadDiameter);
		}
		for (i = 0; i < knights; i++)
		{
			cin >> currentKnightHeight;
			knightHeights.push_back(currentKnightHeight);
		}

		// Sort
		sort(headDiameters.begin(), headDiameters.end());
		sort(knightHeights.begin(), knightHeights.end());

		gold = d = k = 0;
		while (k != knights && d != dragons)
		{
			while (k < knights && headDiameters[d] > knightHeights[k])
			{
				k++;
			}
			if (k == knights)
			{
				break;
			}
			else
			{
				gold += knightHeights[k];
				k++;
				d++;
			}
		}
		if (d == dragons)
		{
			cout << gold << endl;
		}
		else
		{
			cout << "Loowater is doomed!" << endl;
		}
	}
	return 0;
}