#include <stdio.h>

int parent[100];

int find(int v)
{
    while(parent[v] != v)
        v = parent[v];

    return v;
}

void unionSet(int u, int v)
{
    parent[v] = u;
}

int main()
{
    int n, e;
    int src[100], dest[100], wt[100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("\nEnter Source Destination Weight:\n");

    for(int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &src[i], &dest[i], &wt[i]);
    }

    // Initialize parent array
    for(int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    // Sort edges according to weight
    for(int i = 0; i < e - 1; i++)
    {
        for(int j = 0; j < e - i - 1; j++)
        {
            if(wt[j] > wt[j + 1])
            {
                int temp;

                temp = wt[j];
                wt[j] = wt[j + 1];
                wt[j + 1] = temp;

                temp = src[j];
                src[j] = src[j + 1];
                src[j + 1] = temp;

                temp = dest[j];
                dest[j] = dest[j + 1];
                dest[j + 1] = temp;
            }
        }
    }

    int minCost = 0;

    printf("\nEdges in MST:\n");

    for(int i = 0; i < e; i++)
    {
        int u = find(src[i]);
        int v = find(dest[i]);

        if(u != v)
        {
            printf("%d -- %d = %d\n",
                   src[i],
                   dest[i],
                   wt[i]);

            minCost += wt[i];

            unionSet(u, v);
        }
    }

    printf("\nMinimum Cost = %d\n", minCost);

    return 0;
}