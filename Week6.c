#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char dest[MAX][10];
    int size;
} AdjList;

AdjList graph[MAX];
char nodes[MAX][10];
int nodeCount = 0;

char result[MAX][10];
int resultSize = 0;

int getIndex(char *name) {
    for (int i = 0; i < nodeCount; i++) {
        if (strcmp(nodes[i], name) == 0)
            return i;
    }
    strcpy(nodes[nodeCount], name);
    nodeCount++;
    return nodeCount - 1;
}

void sortAdj(int idx) {
    for (int i = 0; i < graph[idx].size - 1; i++) {
        for (int j = i + 1; j < graph[idx].size; j++) {
            if (strcmp(graph[idx].dest[i], graph[idx].dest[j]) > 0) {
                char temp[10];
                strcpy(temp, graph[idx].dest[i]);
                strcpy(graph[idx].dest[i], graph[idx].dest[j]);
                strcpy(graph[idx].dest[j], temp);
            }
        }
    }
}

void DFS(int u) {
    while (graph[u].size > 0) {
        char next[10];
        strcpy(next, graph[u].dest[0]);

        for (int i = 1; i < graph[u].size; i++) {
            strcpy(graph[u].dest[i - 1], graph[u].dest[i]);
        }
        graph[u].size--;

        int v = getIndex(next);
        DFS(v);
    }

    strcpy(result[resultSize++], nodes[u]);
}

int main() {

    char tickets[][2][10] = {
        {"JFK", "SFO"},
        {"JFK", "ATL"},
        {"SFO", "ATL"},
        {"ATL", "JFK"},
        {"ATL", "SFO"}
    };

    int n = 5;

    for (int i = 0; i < n; i++) {
        int u = getIndex(tickets[i][0]);
        getIndex(tickets[i][1]);
        strcpy(graph[u].dest[graph[u].size++], tickets[i][1]);
    }

    for (int i = 0; i < nodeCount; i++) {
        sortAdj(i);
    }

    int start = getIndex("JFK");
    DFS(start);

    for (int i = resultSize - 1; i >= 0; i--) {
        printf("%s ", result[i]);
    }

    return 0;
}
