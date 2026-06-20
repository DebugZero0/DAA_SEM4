#include <stdio.h>

#define MAX 20
#define INF 999999

int main()
{
    int n;
    int graph[MAX][MAX];
    int visited[MAX] = {0}; // {0} means all elements are initialized to 0

    int i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);

            if(graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    visited[0] = 1;

    int edges = 0;
    int minCost = 0;

    printf("\nEdges in MST:\n");

    while(edges < n - 1) // Since a minimum spanning tree has (V - 1) edges
    {
        int min = INF;
        int u = -1;
        int v = -1;

        for(i = 0; i < n; i++)
        {
            // To prevent cycles, we only consider edges from visited vertices
            if(visited[i]) 
            {
                for(j = 0; j < n; j++)
                {
                    // Find the minimum edge from the visited vertices to the unvisited vertices
                    if(!visited[j] && graph[i][j] < min) 
                    {
                        min = graph[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d : %d\n", u, v, min);

        minCost += min;
        visited[v] = 1;
        edges++;
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}

// Time Complexity: O(V^2), where V is the number of vertices in the graph. This is because we have two nested loops that iterate over the vertices to find the minimum edge at each step.

// Space Complexity: O(V^2), where V is the number of vertices in the graph. This is because we are using an adjacency matrix to represent the graph, which requires O(V^2) space. Additionally, we use an array to keep track of visited vertices, which requires O(V) space.