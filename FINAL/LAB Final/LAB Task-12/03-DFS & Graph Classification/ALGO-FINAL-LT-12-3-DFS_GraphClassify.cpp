// ALGO-FINAL-LT-12-3-DFS_GraphClassify

#include <iostream>
using namespace std;

const int maxNode = 100;
int totalNode;
int adjList[maxNode][maxNode];
int trAdj[maxNode][maxNode];
bool visit[maxNode];
int state[maxNode];
int unvisited = 0, visited = 1, finished = 2;

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
        if (top < maxNode - 1) {
            data[++top] = value;
        }
    }

    int pop() {
        if (!isEmpty()) {
            return data[top--];
        } else {
            return -1;
        }
    }

    int topElement() {
        if (!isEmpty()) {
            return data[top];
        } else {
            return -1;
        }
    }
};
Stack stk;

void SetGraph(int nodes) {
    totalNode = nodes;
    for(int i=0; i < totalNode; i++) {
        for(int j=0; j<totalNode; j++) {
            adjList[i][j] = 0;
            trAdj[i][j] = 0;
        }
        visit[i] = false;
        state[i] = unvisited;
    }
    cout << endl << "\tGraph Initialized!" << endl;
}

bool AddEdge(int u, int v) {
    if(adjList[u][v] == 0) {
        adjList[u][v] = 1;
        return true;
    }
    return false;
}

void DFS(int node) {
    visit[node] = true;
    for(int i=0; i<totalNode; i++) {
        if(adjList[node][i] && !visit[i]) {
            DFS(i);
        }
    }
    stk.push(node);
}

void TransposeAdj() {
    for(int i=0; i<totalNode; i++) {
        for(int j=0; j<totalNode; j++) {
            trAdj[j][i] = adjList[i][j];
        }
    }
}

void TransposeDFS(int node) {
    visit[node] = true;
    cout << node << " ";
    for(int i=0; i<totalNode; i++) {
        if(trAdj[node][i] && !visit[i]) {
            TransposeDFS(i);
        }
    }
}

void FindSCC() {
    for(int i=0; i<totalNode; i++) {
        if(!visit[i]) {
            DFS(i);
        }
    }

    TransposeAdj();

    for(int i=0; i<totalNode; i++) {
        visit[i] = false;
    }

    cout << endl << "Strongly Connected Components:" << endl;
    while(!stk.isEmpty()) {
        int node = stk.pop();

        if(!visit[node]) {
            TransposeDFS(node);
            cout << endl;
        }
    }
}

void ClassifyEdgesDFS(int u) {
    state[u] = visited;

    for(int v = 0; v < totalNode; v++) {
        if(adjList[u][v]) {
            if(state[v] == unvisited) {
                cout << endl << "Tree Edge: (" << u << ", " << v << ")" << endl;
                ClassifyEdgesDFS(v);
            }
            else if(state[v] == visited) {
                cout << endl << "Back Edge: (" << u << ", " << v << ")" << endl;
            }
            else if(state[v] == finished) {
                cout << endl << "Forward/Cross Edge: (" << u << ", " << v << ")" << endl;
            }
        }
    }

    state[u] = finished;
}

void ClassifyEdges() {
    for(int u = 0; u < totalNode; u++) {
        if(state[u] == unvisited) {
            ClassifyEdgesDFS(u);
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

    cout << endl << "Enter the number of edges: ";
    cin >> edges;

    cout << endl << "Enter the starting point and ending point of the following edges-" << endl;

    for(int i=0; i<edges; i++) {
        cout << endl << "Edge-" << i + 1 << ": ";
        cin >> u >> v;

        if(u < 0 || u >= nodes || v < 0 || v >= nodes) {
            cout << endl << "\tInvalid edge! Nodes should be between 0 and " << nodes - 1 << "." << endl;
            i--;
            continue;
        }

        if(AddEdge(u, v)) {
            cout << endl << "\tEdge Added!" << endl;
        }
        else {
            cout << endl << "\tEdge Addition Failed! (Multiple edge detected)" << endl;
        }
    }

    cout << endl << "Classifying Edges:" << endl;
    ClassifyEdges();

    FindSCC();

    return 0;
}
