#include <stdio.h>
#include <limits.h>
#define MAX 10

int dist[MAX][MAX], visited[MAX], n, distance = 0;
int least(int c)
{
	int i, nc = SHRT_MAX;
	int min = SHRT_MAX, kmin;
	for (i = 0; i < n; i++)
	{
		if ((dist[c][i] != 0) && (visited[i] == 0))
		{
			if (dist[c][i] < min)
			{
				min = dist[i][0] + dist[c][i];
				kmin = dist[c][i];
				nc = i;
			}
		}
	}
	if (min != SHRT_MAX)
		distance += kmin;
	return nc;
}

void mindistance(int city)
{
	int i, ncity;
	visited[city] = 1;
	printf("%d-->", city + 1);
	ncity = least(city);
	if (ncity == SHRT_MAX)
	{
		ncity = 0;
		printf("%d", ncity + 1);
		distance += dist[city][ncity];
		return;
	}
	mindistance(ncity);
}

void main()
{
	int i, j;
	printf("Enter No. of Cities: ");
	scanf("%d", &n);
	printf("\nEnter Distance Matrix\n");
	for (i = 0; i < n; i++)
	{
		printf("\nEnter Elements of Row %d:\n", i + 1);
		for (j = 0; j < n; j++)
			scanf("%d", &dist[i][j]);
		visited[i] = 0;
	}
	printf("\nThe Distance matrix is:\n");
	for (i = 0; i < n; i++)
	{
		printf("\n\n");
		for (j = 0; j < n; j++)
			printf("%d\t", dist[i][j]);
	}
	printf("\n\nThe Path is:\n\n");
	mindistance(0);
	printf("\n\nMinimum Distance:");
	printf("%d", distance);
}