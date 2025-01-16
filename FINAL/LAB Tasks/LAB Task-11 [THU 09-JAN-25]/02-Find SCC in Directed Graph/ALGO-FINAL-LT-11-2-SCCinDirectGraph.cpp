// ALGO-FINAL-LT-11-2-SCCinDirectGraph

#include <iostream>
using namespace std;

const int maxNode = 100;
int totalNode;
int adjList[maxNode][maxNode];
int trAdj[maxNode][maxNode];
bool visited[maxNode];

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
Stack stk;

void SetGraph(int nodes) {
    totalNode = nodes;
    for(int i=0; i<totalNode; i++) {
        for(int j=0; j<totalNode; j++) {
            adjList[i][j] = 0;
            trAdj[i][j] = 0;
        }
        visited[i] = false;
    }
    cout << endl << "\tGraph Initialized!" << endl << endl;
}

bool AddEdge(int u, int v) {
    if(adjList[u][v] == 0) {
        adjList[u][v] = 1;
        return true;
    }
    return false;
}

void DFS(int node) {
    visited[node] = true;
    for(int i=0; i<totalNode; i++) {
        if (adjList[node][i] && !visited[i]) {
            DFS(i);
        }
    }
    stk.push(node);
}

void TransposeAdj() {
    for (int i = 0; i < totalNode; i++) {
        for (int j = 0; j < totalNode; j++) {
            trAdj[j][i] = adjList[i][j];
        }
    }
}

void TransposeDFS(int node) {
    visited[node] = true;
    cout << node << " ";
    for (int i = 0; i < totalNode; i++) {
        if (trAdj[node][i] && !visited[i]) {
            TransposeDFS(i);
        }
    }
}

void FindSCC() {
    for(int i=0; i<totalNode; i++) {
        if (!visited[i]) {
            DFS(i);
        }
    }

    TransposeAdj();

    for(int i=0; i<totalNode; i++) {
        visited[i] = false;
    }

    cout << endl << "Strongly Connected Components:" << endl;
    while(!stk.isEmpty()) {
        int node = stk.pop();

        if (!visited[node]) {
            TransposeDFS(node);
            cout << endl;
        }
    }
}

int main() {
    int nodes, edges, u, v;

    cout << endl << "Enter the number of nodes: ";
    cin >> nodes;

    if(nodes <= 0 || nodes > maxNode) {
        cout << endl << "\tInvalid number of nodes! Must be between 1 and " << maxNode << "." << endl;
        return 0;
    }

    SetGraph(nodes);

    cout << "Enter the number of edges: ";
    cin >> edges;

    cout << endl << "Enter the starting point and ending point of following edges-" << endl;

    int i=0;
    while(i<edges) {
        cout << endl << "Edge-" << i+1 << ": ";
        cin >> u >> v;

        if(u < 0 || u >= nodes || v < 0 || v >= nodes) {
            cout << endl << "\tInvalid edge! Nodes should be between 0 and " << totalNode - 1 << "." << endl;
            continue;
        }

        if(AddEdge(u, v)) {
            cout << endl << "\tEdge Added!" << endl;
            i++;
        }
        else {
            cout << endl << "\tEdge Addition Failed!" << endl << "\t(Multiple edge detected!)" << endl;
        }
    }

    FindSCC();

    return 0;
}