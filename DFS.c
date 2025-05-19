#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 6

struct Vertex {
    char label;
    bool visited;
};

int stack[MAX];
int top = -1;

// list of vertices
struct Vertex* lstVertices[MAX];
int adjMatrix[MAX][MAX];

int vertexCount = 0;


// stack functions

void push(int item) {
    stack[++top] = item;
}

int pop() {
    return stack[top--];
}

int peek() {
    return stack[top];
}

bool isStackEmpty() {
    return top == -1;
}

// graph functions

// add vertex to the vertex list
void addVertex(char label) {
    struct Vertex* vertex = (struct Vertex*)malloc(sizeof(struct Vertex));
    vertex->label = label;
    vertex->visited = false;
    lstVertices[vertexCount++] = vertex;
}

// add edge to edge array
void addEdge(int start, int end) {
    adjMatrix[start][end] = 1;
    adjMatrix[end][start] = 1;
}

// display the vertext
void displayVertex(int vertexIndex) {
    printf("%c ",lstVertices[vertexIndex]->label);
}

// get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
    int i;
    for(i = 0; i < vertexCount; i++) {
        if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
            return i;
        }
    }
    return -1;
}

void depthFirstSearch() {
    int i;
    
    // mark first node as visited
    lstVertices[0]->visited = true;

    // display the vertex
    displayVertex(0);

    // push vertex index in stack
    push(0);

    while(!isStackEmpty()) {
        // get the invisited vertex of vertex which is at top of the stack
        int unvisitedVertex = getAdjUnvisitedVertex(peek());

        // no adjecent vertex found
        if(unvisitedVertex == -1) {
            pop();
        } else {
            lstVertices[unvisitedVertex]->visited = true;
            displayVertex(unvisitedVertex);
            push(unvisitedVertex);
        }
    }

    // stack is empty, search was completed, reset the visited flag
    for(i = 0; i < vertexCount; i++) {
        lstVertices[i]->visited = false;
    }
}

int main() {

    int i, j;

    for(i = 0; i < MAX; i++) {
        for(j = 0; j < MAX; j++)
            adjMatrix[i][j] = 0;
    }
    addVertex('S'); // 0
    addVertex('A'); // 1
    addVertex('B'); // 2
    addVertex('C'); // 3
    addVertex('D'); // 4
    addVertex('F'); // 5

    addEdge(0, 1); // S - A
    addEdge(0, 2); // S - B
    addEdge(0, 3); // S - C
    addEdge(1, 4); // A - D
    addEdge(2, 4); // B - D
    addEdge(3, 4); // C - D
    addEdge(3, 5); // C - F
    printf("Depth First Search: ");
    depthFirstSearch();


    return 0;
}
/*
    S
   /|\
  A B C
   \|/ \
    D   F
*/