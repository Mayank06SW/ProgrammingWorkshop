#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

int V = 5;
int E = 5;

int adj[MAX][MAX];

int disc[MAX];
int low[MAX];
int parent[MAX];
int ap[MAX];
int visited[MAX];

int time = 0;

void DFS(int u) {

    int children = 0;

    visited[u] = 1;
    disc[u] = low[u] = ++time;

    for (int v = 0; v < V; v++) {

        if (adj[u][v]) {

            if (!visited[v]) {

                parent[v] = u;
                children++;

                DFS(v);

                low[u] = (low[u] < low[v]) ? low[u] : low[v];

                if (parent[u] == -1 && children > 1)
                    ap[u] = 1;

                if (parent[u] != -1 && low[v] >= disc[u])
                    ap[u] = 1;
            }

            else if (v != parent[u]) {

                low[u] = (low[u] < disc[v]) ? low[u] : disc[v];
            }
        }
    }
}

int main() {

    for (int i = 0; i < V; i++) {

        disc[i] = -1;
        low[i] = -1;
        parent[i] = -1;
        ap[i] = 0;
        visited[i] = 0;

        for (int j = 0; j < V; j++)
            adj[i][j] = 0;
    }

    adj[0][1] = adj[1][0] = 1;
    adj[1][2] = adj[2][1] = 1;
    adj[2][3] = adj[3][2] = 1;
    adj[3][4] = adj[4][3] = 1;
    adj[1][4] = adj[4][1] = 1;

    for (int i = 0; i < V; i++) {

        if (!visited[i])
            DFS(i);
    }

    int found = 0;

    for (int i = 0; i < V; i++) {

        if (ap[i]) {

            printf("%d ", i);
            found = 1;
        }
    }

    if (!found)
        printf("None");

    printf("\n");

    return 0;
}
