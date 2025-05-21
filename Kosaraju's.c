#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

int adj[MAX][MAX] = {
    {0, 1, 0, 0, 0},
    {0, 0, 1, 0, 0},
    {1, 0, 0, 1, 0},
    {0, 0, 0, 0, 1},
    {0, 0, 0, 1, 0}
};
/*
    0 0 1 0 0
    1 0 0 0 0
    0 1 0 0 0
    0 0 1 0 1
    0 0 0 1 0
*/

int visited[MAX] = {0};
int finishing_time[MAX]; // 4, 3, 2, 1, 0
int finish_index = 0;

char map[MAX] = {'A', 'B', 'C', 'D', 'E'};

void DFS(int vertex, int print) {
    visited[vertex] = 1;
    if (print)
        printf("%c ", map[vertex]);
    
    for(int v = 0; v < MAX; v++) {
        if(adj[vertex][v] && !visited[v]) {
            DFS(v, print);
        }
    }

    if(!print)
        finishing_time[finish_index++] = vertex;
}

void reverse_graph() {
    int temp[MAX][MAX];

    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            temp[i][j] = adj[i][j];
        }
    }

    // Transpose the graph
    for(int i = 0; i < MAX; i++) {
        for(int j = 0; j < MAX; j++) {
            adj[i][j] = temp[j][i];
        }
    }
}

void find_scc() {

    // step 1: compute finishing times in the original graph
    for(int v = 0; v < MAX; v++) {
        if(!visited[v]) {
            DFS(v, 0); // first pass DFS (store finish times)
        }
    }

    // step 2: revers the graph
    reverse_graph();

    // step 3: second DFS based on decreasing finishing times
    memset(visited, 0, sizeof(visited)); // reset visited array

    printf("Strongly Connected Components:\n");
    for(int i = MAX - 1; i >= 0; i--) {
        int vertex = finishing_time[i];
        if(!visited[vertex]) {
            printf("SCC: ");
            DFS(vertex, 1); // second pass DFS (print SCC)
            printf("\n");
        }
    }
}

int main() {
    find_scc();
    
    return 0;
}