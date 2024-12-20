// ALGO-FINAL-LT-8-3-BfsAlgo

#include <iostream>
using namespace std;

void AddEdge(int x, int y, int** adjList) {
    adjList[x][y] = 1;
    adjList[y][x] = 1;
}

void ShowPath(int nodes, int temp, int* origin) {
    if (temp == -1) {
        cout << endl << "No path exists." << endl;
        return;
    }

    int* path = new int [nodes];
    int pathLen = 0;

    while(temp != -1) {
        path[pathLen] = temp;
        temp = origin[temp];
        pathLen++;
    }

    cout << endl << "Path: ";
    for(int i=pathLen-1; i>=0; i--) {

        cout << path[i]+1;

        if(i != 0) {
            cout << " -> ";
        }

    }
    cout << endl;

    delete[] path;
}

void BFS(int start, int dest, int nodes, int** adjList) {
    if(start < 0 || start >= nodes || dest < 0 || dest >= nodes) {
        cout << endl << "Invalid node input." << endl;
        return;
    }

    bool* visited = new bool [nodes] {false};
    int* origin = new int [nodes] {-1};
    int* queue = new int [nodes];
    int front = 0, rear = 0;

    queue[rear] = start;
    visited[start] = true;
    rear++;

    while(front < rear) {

        int curr = queue[front];

        if(curr == dest) {
            ShowPath(nodes, dest, origin);

            delete[] visited;
            delete[] origin;
            delete[] queue;

            return;
        }

        for(int i=0; i<nodes; i++) {

            if(adjList[curr][i] == 1 && !visited[i]) {
                visited[i] = true;
                origin[i] = curr;
                queue[rear] = i;
                rear++;
            }

        }

        front++;

    }

    cout << endl << "No paths exists from " << start+1 << " to " << dest+1 << "." << endl;

    delete[] visited;
    delete[] origin;
    delete[] queue;

    return;
}

int main() {
    int vertices, edges, x, y, start, dest;

    cout << endl << "Enter total vertices: ";
    cin >> vertices;
    cout << "Enter total edges: ";
    cin >> edges;

    int** adjList = new int* [vertices];
    for(int i=0; i<vertices; i++) {
        adjList[i] = new int [vertices] {0};
    }

    cout << endl << "Enter edges (x y)-" << endl;
    for(int i=0; i<edges; i++) {
        cout << "Edge-" << i+1 << ": ";
        cin >> x >> y;
        AddEdge(x-1, y-1, adjList);
    }

    cout << endl << "Enter starting node: ";
    cin >> start;
    cout << "Enter destination node: ";
    cin >> dest;

    BFS(start-1, dest-1, vertices, adjList);

    for(int i=0; i<vertices; i++) {
        delete[] adjList[i];
    }
    delete[] adjList;

    return 0;
}