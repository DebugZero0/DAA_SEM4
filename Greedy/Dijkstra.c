#include <stdio.h>

#define INF 9999

int main() {
    int n, i, j, source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int graph[n][n];

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if(i != j && graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &source);

    int dist[n], visited[n];

    for(i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(i = 0; i < n - 1; i++) {

        int min = INF;
        int u = -1;

        // Find unvisited vertex with minimum distance
        for(j = 0; j < n; j++) {
            if(!visited[j] && dist[j] < min) {
                min = dist[j];
                u = j; // Store the vertex with minimum distance
            }
        }

        visited[u] = 1;

        // Update distances of neighbors
        for(j = 0; j < n; j++) {
            if(!visited[j] &&
               graph[u][j] != INF &&
               dist[u] + graph[u][j] < dist[j]) {

                dist[j] = dist[u] + graph[u][j];
            }
        }
    }

    printf("\nShortest distances from vertex %d:\n", source);

    for(i = 0; i < n; i++) {
        printf("%d -> %d = %d\n", source, i, dist[i]);
    }

    return 0;
}

// Time Complexity: O(V^2) where V is the number of vertices. This is because we have two nested loops: one for finding the minimum distance vertex and another for updating the distances of its neighbors.

// space Complexity: O(V) for storing the distance and visited arrays.