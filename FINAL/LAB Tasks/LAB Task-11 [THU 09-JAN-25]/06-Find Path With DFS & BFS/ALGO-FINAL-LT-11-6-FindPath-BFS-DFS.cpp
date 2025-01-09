// ALGO-FINAL-LT-11-6-FindPath-BFS-DFS

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
        path[i] = -1;
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
    path[start] = -1;

    while(!q.isEmpty()) {
        int curr = q.dequeue();

        if(curr == dest) {
            return true;
        }

        for(int i = 0; i < nodes; i++) {
            if(adjList[curr][i] && !visited[i]) {
                q.enqueue(i);
                visited[i] = true;
                path[i] = curr;
            }
        }
    }

    return false;
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

void showPath(int start, int dest, char type) {
    cout << endl << "Path: ";

    if(type == 'B') {
        int tempPath[maxNode];
        int tempIndex = 0;

        int curr = dest;
        while(curr != -1) {
            tempPath[tempIndex++] = curr;
            curr = path[curr];
        }

        for(int i = tempIndex - 1; i >= 0; i--) {
            cout << tempPath[i];
            if(i > 0) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
    else if(type == 'D') {
        for(int i = 0; i < pathIndex; i++) {
            cout << path[i];
            if(i < pathIndex - 1) {
                cout << " -> ";
            }
        }
        cout << endl;
    }
}

void UserMessage(bool found, int start, int dest, char type) {
    if(found) {
        cout << endl << "\tPath Found!" << endl;
        showPath(start, dest, type);
    }
    else {
        cout << endl << "\tNo path found from node " << start << " to node " << dest << endl;
    }
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

    char op;
    while(true) {
        cout << endl << "1. BFS" << endl
                    << "2. DFS" << endl;
        cout << "Choose path finding method: ";
        cin >> op;

        if(op == '1') {
            cout << endl << "\tApplying BFS..." << endl;
            UserMessage(BFS(start, dest, nodes), start, dest, 'B');
            break;
        }
        else if(op == '2') {
            cout << endl << "\tApplying DFS..." << endl;
            UserMessage(DFS(start, dest, nodes), start, dest, 'D');
            break;
        }
        else {
            cout << endl << "\tINVALID INPUT!" << endl;
        }
    }

    cout << endl;

    return 0;
}