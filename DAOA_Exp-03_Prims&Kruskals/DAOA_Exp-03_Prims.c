#include<stdio.h>
#define MAX 10
int cost[MAX][MAX], visited[MAX]={0}, i, j, n, no_of_edges=1, min, a, b, min_cost=0;                                                                                    

int prims()
{
	// logic for finding minimum cost of spanning tree                                                                                               
    visited[0]=1; // visited first node
    printf("----------Spanning Tree----------");
    while(no_of_edges < n)
    {
        min = 1000;
        // Looping and finding the minimum cost 
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
//            	if cost is minimum and vertex is not visited
                if(cost[i][j]<min)
                {
                    if(visited[i] != 0)
                    {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }
        // if destination vertex is not visited, include the edge in min. spanning tree
        if(visited[b]==0)
        {
            printf("\n%d-->%d  cost = %d",a,b,min);
            min_cost += min;
            no_of_edges++;
        }
        visited[b]=1;
        // initialize with maximum value.
        cost[a][b] = cost[b][a] = 1000; 
    }
    return min_cost;
}

int main()
{   
	printf("Enter number of vertices: ");
    scanf("%d",&n);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&cost[i][j]);
            // if cost = 0 then initialize it by maximum value
            if(cost[i][j]==0)
              cost[i][j]=1000;
        }
    }
	min_cost = prims();
    printf("\n\nCost of the Minimum spanning tree = %d",min_cost);
    return 0;
}
