// ALGO-FINAL-LT-9-1-FindPathBFS

#include <iostream>
using namespace std;

const int maxNode = 100;
bool adjList[maxNode][maxNode];
bool visited[maxNode];
int parent[maxNode];

struct Queue {
    int data[maxNode];
    int front, rear;

    Queue() {
        front = 0;
        rear = 0;
    }

    bool isEmpty() {
        if(front == rear) {
            return true;
        }
        else {
            return false;
        }
    }

    void enqueue(int value) {
        if(rear >= maxNode) {
            cout << endl << "\tQueue Overflow!" << endl;
        }
        data[rear++] = value;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << endl << "\tQueue underflow!" << endl;
            return -1;
        }
        return data[front++];
    }
};

void setGraph(int nodes) {
    for(int i=0; i<nodes; i++) {
        for(int j=0; j<nodes; j++) {
            adjList[i][j] = false;
        }
        visited[i] = false;
        parent[i] = -1;
    }
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

bool BFS(int start, int dest, int nodes) {
    Queue q;

    q.enqueue(start);
    visited[start] = true;

    while(!q.isEmpty()) {
        int curr = q.dequeue();

        if(curr == dest) {
            return true;
        }

        for(int i=0; i<nodes; i++) {
            if(adjList[curr][i] && !visited[i]) {
                q.enqueue(i);
                visited[i] = true;
                parent[i] = curr;
            }
        }
    }

    return false;
}

void showPath(int start, int dest) {
    int path[maxNode];
    int pathIndex = 0;

    int curr = dest;
    while(curr != -1) {
        path[pathIndex++] = curr;
        curr = parent[curr];
    }

    for(int i=pathIndex-1; i>=0; i--) {
        cout << path[i];
        if(i > 0) {
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

    if(BFS(start, dest, nodes)) {
        cout << endl << "\tPath Found!" << endl << endl << "Path: ";
        showPath(start, dest);
    }
    else {
        cout << endl << "\tNo path found from node " << start << " to node " << dest << endl;
    }

    cout << endl;

    return 0;
}