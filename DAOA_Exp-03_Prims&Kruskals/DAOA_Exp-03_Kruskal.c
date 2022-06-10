// UNION-FIND --> Data structure that keeps track of elements which are split into one or more disjoint sets
// FIND - RETURNS THE SET OF ELEMENT TO WHICH THE GIVEN ELEMENT BELONGS
// UNION - MERGES TWO DISJOINT SETS

#include <stdio.h>
#define MAX 15

// Structure storing information of each edge
typedef struct edge
{
	int u, v, weight;
} edge;

// Structure for storing all the edges of the graph.
typedef struct Edge_list
{
	edge data[MAX];
	int n;
} Edge_list;

int G[MAX][MAX], n;
Edge_list E1;		 // to store the data of graph
Edge_list span_tree; // to store the data of Minimum Spanning Tree

// To check whether the given vertex forms a cycle
int find(int included[], int vertexno)
{
	return (included[vertexno]);
}

void union1(int included[], int c1, int c2)
{
	int i;
	for (i = 0; i < n; i++)
	{
		if (included[i] == c2)
			included[i] = c1;
	}
}

// Sort Function to sort the weights in ascending order
void sort()
{
	int i, j;
	edge temp;
	for (i = 0; i < E1.n - 1; i++)
	{
		for (j = 0; j < E1.n - i - 1; j++)
		{
			if (E1.data[j].weight > E1.data[j + 1].weight)
			{
				temp = E1.data[j];
				E1.data[j] = E1.data[j + 1];
				E1.data[j + 1] = temp;
			}
		}
	}
}

void print()
{
	int i, cost = 0;
	printf("\n--------------Spanning Tree---------------\n");
	for (i = 0; i < span_tree.n; i++)
	{
		printf("\n%d-->%d  Cost=%d", span_tree.data[i].u, span_tree.data[i].v, span_tree.data[i].weight);
		cost += span_tree.data[i].weight;
	}
	printf("\n\nCost of the Minimum spanning tree = %d", cost);
}

// Kruskal's Algorithm
void kruskal()
{
	int i, j, cno1, cno2, included[MAX];
	E1.n = 0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < i; j++)
		{
			// Weight is not 0 then include in edgelist E1 else discard
			if (G[i][j] != 0)
			{
				E1.data[E1.n].u = i;
				E1.data[E1.n].v = j;
				E1.data[E1.n].weight = G[i][j];
				E1.n++;
			}
		}
	}
	sort();
	for (i = 0; i < n; i++)
		included[i] = i;
	//	Initialise the spanning list to 0
	span_tree.n = 0;
	for (i = 0; i < E1.n; i++)
	{
		cno1 = find(included, E1.data[i].u);
		cno2 = find(included, E1.data[i].v);
		//  If find() returns the same value that means they have the same parent (vertex when added forms a cycle)
		if (cno1 != cno2)
		{
			span_tree.data[span_tree.n] = E1.data[i];
			span_tree.n++;
			union1(included, cno1, cno2);
		}
	}
}

void main()
{
	int i, j;
	printf("\nEnter number of vertices:");
	scanf("%d", &n);
	printf("\nEnter the adjacency matrix:\n");
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			scanf("%d", &G[i][j]);
	}
	kruskal();
	print();
}
