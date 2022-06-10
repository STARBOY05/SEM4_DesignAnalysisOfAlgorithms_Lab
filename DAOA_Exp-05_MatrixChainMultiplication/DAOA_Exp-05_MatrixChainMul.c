// MATRIX MULTIPLICATION USING DP
#include <stdio.h>
#include <limits.h> // Imported Max Short Int Number
#define MAX 10
int n, P[MAX], kval[MAX][MAX] = {0}, cost[MAX][MAX] = {0}, i, j, k, min, diff, q, x, temp;
void print_optimal(int i, int j)
{
	if (i == j)
		printf(" M%d ", i);
	else
	{
		printf("( ");
		print_optimal(i, kval[i][j]);
		printf(" x ");
		print_optimal(kval[i][j] + 1, j);
		printf(" )");
	}
}

int main()
{
	//	Input for Sequence
	printf(" Enter the number of sequences: ");
	scanf("%d", &n);
	printf(" Enter the Sequence: ");
	for (i = 0; i < n; i++)
		scanf("%d", &P[i]);
	printf("\n Sequence: ");
	for (i = 0; i < n; i++)
		printf("%d ", P[i]);
	printf("\n");
	//	Initialising Cost to 0 for main diagonal, lower diagonal to -1
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (i > j)
			{
				cost[i][j] = -1;
				kval[i][j] = -1;
			}
			else
			{
				cost[i][j] = 0;
				kval[i][j] = 0;
			}
		}
	}
	// Matrix Chain Multiplication
	// diff => diagonals above main diagonal d = j - i (difference between i and j)
	// i for rows, j for cols
	for (diff = 1; diff < n - 1; diff++)
	{
		for (i = 1; i < n - diff; i++)
		{
			j = i + diff;
			min = SHRT_MAX;
			temp = 0;
			for (k = i; k <= j - 1; k++)
			{
				// Main Formula
				x = cost[i][k] + cost[k + 1][j] + (P[i - 1] * P[k] * P[j]);
				if (x < min)
				{
					min = x;
					temp = k;
				}
			}
			cost[i][j] = min;
			kval[i][j] = temp;
		}
	}
	printf("\n");
	// Display Table
	for (i = 1; i < n; i++)
	{
		printf(" |");
		for (j = 1; j < n; j++)
		{
			printf("\t%d\t", cost[i][j]);
		}
		printf("|\n");
	}
	printf("\n");
	printf(" Minimum number of multiplications required to multiply is %d", cost[1][n - 1]);
	printf("\n\n");
	// Display Table
	for (i = 1; i < n; i++)
	{
		printf(" |");
		for (j = 1; j < n; j++)
		{
			printf("\t%d\t", kval[i][j]);
		}
		printf("|\n");
	}
	printf("\n Optimal Parenthesization : ");
	print_optimal(0, n - 1);
	return 0;
}