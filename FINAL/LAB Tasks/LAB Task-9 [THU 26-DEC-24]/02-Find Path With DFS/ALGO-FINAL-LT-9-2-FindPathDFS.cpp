// ALGO-FINAL-LT-9-2-FindPathDFS

#include <iostream>
using namespace std;

const int maxNode = 100;
bool adjList[maxNode][maxNode];
bool visited[maxNode];
int path[maxNode];
int pathIndex = 0;

struct Stack {
    int data[maxNode];
    int top;

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        if(top == -1) {
            return true;
        }
        else {
            return false;
        }
    }

    void push(int value) {
        if(top < maxNode-1) {
            data[++top] = value;
        }
    }

    int pop() {
        if(!isEmpty()) {
            return data[top--];
        }
        else {
            return -1;
        }
    }

    int topElement() {
        if(!isEmpty()) {
            return data[top];
        }
        else {
            return -1;
        }
    }
};

void setGraph(int nodes) {
    for(int i=0; i<nodes; i++) {
        for(int j=0; j<nodes; j++) {
            adjList[i][j] = false;
        }
        visited[i] = false;
        path[i] = -1;
    }
    pathIndex = 0;
    cout << endl << "\tGraph set!" << endl;
}

void addEdge(int u, int v, int nodes) {
    if(u < 0 || u >= nodes || v < 0 || v >= nodes) {
        cout << endl << "\tInvalid edge! Nodes should be between 0 and " << nodes - 1 << "." << endl;
        return;
    }
    
    adjList[u][v] = true;
    adjList[v][u] = true;

    cout << endl << "\tEdge Added!" << endl << endl;
}

bool DFS(int start, int dest, int nodes) {
    Stack s;
    pathIndex = 0;

    s.push(start);
    path[pathIndex++] = start;
    visited[start] = true;

    while(!s.isEmpty()) {
        int curr = s.topElement();

        if(curr == dest) {
            return true;
        }

        bool neighbourVisited = false;
        for(int i = 0; i < nodes; i++) {
            if(adjList[curr][i] && !visited[i]) {
                s.push(i);
                visited[i] = true;
                path[pathIndex++] = i;
                neighbourVisited = true;
                break;
            }
        }

        if (!neighbourVisited) {
            s.pop();
            pathIndex--;
        }

    }

    return false;
}

void showPath(int start, int dest) {
    cout << endl << "Path: ";

    for(int i=0; i<pathIndex; i++) {
        cout << path[i];
        if(i < pathIndex-1) {
            cout << " -> ";
        }
    }
    cout << endl;
}

int main() {
    int start, dest, u, v, nodes, edges;

    cout << endl << "Enter the number of nodes: ";
    cin >> nodes;

    if(nodes <= 0 || nodes > maxNode) {
        cout << endl << "\tInvalid number of nodes! Must be between 1 and " << maxNode << "." << endl;
        return 0;
    }

    setGraph(nodes);

    cout << endl << "Enter the number of edges: ";
    cin >> edges;

    cout << endl << "Enter the starting point and ending point of following edges-" << endl << endl;
    for(int i=0; i<edges; i++) {
        cout << "Edge-" << i+1 << ": ";
        cin >> u >> v;
        addEdge(u, v, nodes);
    }

    cout << endl << "Enter starting node: ";
    cin >> start;
    cout << "Enter destination node: ";
    cin >> dest;

    if(start < 0 || start >= nodes || dest < 0 || dest >= nodes) {
        cout << endl << "\tInvalid start or destination node! Must be between 0 and " << nodes - 1 << "." << endl;
        return 0;
    }

    if(DFS(start, dest, nodes)) {
        cout << endl << "\tPath Found!" << endl;
        showPath(start, dest);
    }
    else {
        cout << endl << "\tNo path found from node " << start << " to node " << dest << endl;
    }

    cout << endl;

    return 0;
}