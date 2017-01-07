// One linear scan to find the max value
#include <stdio.h>

int main()
{
	int testCase;
	int studentSpeed;
	int numberOfStudents;
	int Case = 0;
	
	scanf("%d",&testCase);
	while (testCase)
	{
		Case = Case + 1;
		int maxSpeed = 0;
		
		scanf("%d",&numberOfStudents);
		for (int i = 0; i < numberOfStudents; i++)
		{
			scanf("%d",&studentSpeed);
			if (studentSpeed > maxSpeed)
				maxSpeed = studentSpeed;
		}
		printf("Case %d: %d\n",Case,maxSpeed);
		testCase--;
	}
	return 0;
}
