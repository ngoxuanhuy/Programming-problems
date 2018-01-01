/* Greedy algorithm
	classical problem: Load Balancing
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, d, r;
	int i;
	int inputRoute;
	int overtime;
	int exceed;
	vector<int> morning_route, afternoon_route;
	while (1)
	{
		scanf("%d %d %d", &n, &d, &r);
		if ((n == 0) && (d == 0) && (r == 0))
		{
			return 0;
		}
		morning_route.clear();
		afternoon_route.clear();
		overtime = 0;
		
		// Input
		for (i = 0; i < n; i++)
		{
			cin >> inputRoute;
			morning_route.push_back(inputRoute);
		}
		for (i = 0; i < n; i++)
		{
			cin >> inputRoute;
			afternoon_route.push_back(inputRoute);
		}

		// Sort
		sort(morning_route.begin(), morning_route.end());
		sort(afternoon_route.rbegin(), afternoon_route.rend());

		// Find result
		for (i = 0; i < n; i++)
		{
			exceed = morning_route[i] + afternoon_route[i] - d;
			if (exceed > 0)
			{
				overtime += exceed;
			}
		}

		// Print result
		cout << overtime * r << endl;
	}
}