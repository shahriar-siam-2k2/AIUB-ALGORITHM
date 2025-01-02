// ALGO-FINAL-LT-9-3-GraphClsDFS

#include <iostream>
using namespace std;

const int maxNode = 100;
bool adjList[maxNode][maxNode];
bool visited[maxNode];
int state[maxNode];

struct Stack {
    int data[maxNode];
    int top;

    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
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

void SetGraph(int nodes) {
    for(int i=0; i<nodes; i++) {
        for(int j=0; j<nodes; j++) {
            adjList[i][j] = false;
        }
        visited[i] = false;
        state[i] = 0;
    }
    cout << endl << "\tGraph set!" << endl;
}

void AddEdge(int u, int v, int nodes) {
    if(u < 0 || u >= nodes || v < 0 || v >= nodes) {
        cout << endl << "\tInvalid edge! Nodes should be between 0 and " << nodes - 1 << "." << endl;
        return;
    }

    adjList[u][v] = true;
    adjList[v][u] = true;

    cout << endl << "\tEdge Added!" << endl << endl;
}

void DFS(int u, int nodes) {
    Stack s;
    s.push(u);
    state[u] = 1;

    while(!s.isEmpty()) {
        int curr = s.topElement();
        bool hasUnvisited = false;

        for(int v=0; v<nodes; v++) {
            if(adjList[curr][v]) {
                if(state[v] == 0) {
                    cout << "Tree Edge: (" << curr << ", " << v << ")" << endl;
                    s.push(v);
                    state[v] = 1;
                    hasUnvisited = true;
                    break;
                }
                else if(state[v] == 1) {
                    cout << "Back Edge: (" << curr << ", " << v << ")" << endl;
                }
                else if(state[v] == 2) {
                    cout << "Forward/Cross Edge: (" << curr << ", " << v << ")" << endl;
                }
            }
        }

        if(!hasUnvisited) {
            state[curr] = 2;
            s.pop();
        }
    }
}

void ClassifyEdges(int nodes) {
    for(int u=0; u<nodes; u++) {
        if(state[u] == 0) {
            DFS(u, nodes);
        }
    }
}

int main() {
    int u, v, nodes, edges;

    cout << endl << "Enter the number of nodes: ";
    cin >> nodes;

    if(nodes <= 0 || nodes > maxNode) {
        cout << endl << "\tInvalid number of nodes! Must be between 1 and " << maxNode << "." << endl;
        return 0;
    }

    SetGraph(nodes);

    cout << endl << "Enter the number of edges: ";
    cin >> edges;

    cout << endl << "Enter the starting point and ending point of following edges-" << endl << endl;
    for(int i=0; i<edges; i++) {
        cout << "Edge-" << i + 1 << ": ";
        cin >> u >> v;
        AddEdge(u, v, nodes);
    }

    cout << endl << "Classify of Edges-" << endl;
    ClassifyEdges(nodes);

    cout << endl;

    return 0;
}