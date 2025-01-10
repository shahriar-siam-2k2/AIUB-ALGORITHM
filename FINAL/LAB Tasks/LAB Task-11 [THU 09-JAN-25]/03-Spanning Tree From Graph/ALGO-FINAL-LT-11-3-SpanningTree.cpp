// ALGO-FINAL-LT-11-3-SpanningTree

#include <iostream>
using namespace std;

const int maxVertice = 100;
bool visited[maxVertice];
int spTree[maxVertice][maxVertice];
int adjList[maxVertice][maxVertice];

void SetTree(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            spTree[i][j] = 0;
            adjList[i][j] = 0;
        }
        visited[i] = false;
    }
    cout << endl << "\tTree Initialized!" << endl;
}

bool SetAdjList(int vertices) {
    cout << endl << "Enter the adjacency list of the tree:" << endl;
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++) {
            cin >> adjList[i][j];
            if(adjList[i][j] != 0 && adjList[i][j] != 1) {
                return false;
            }
        }
    }
    return true;
}

void DFS(int currVertice, int vertices) {
    visited[currVertice] = true;

    for(int i=0; i<vertices; i++) {
        if(adjList[currVertice][i] == 1 && !visited[i]) {
            spTree[currVertice][i] = 1;
            spTree[i][currVertice] = 1;
            DFS(i, vertices);
        }
    }
}

void ShowSpanningTree(int vertices) {
    cout << endl << "Spanning tree adjacency list:" << endl;
    for(int i=0; i<vertices; i++) {
        for(int j=0; j<vertices; j++) {
            cout << spTree[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int vertices;

    cout << endl << "Enter the number of vertices in the graph: ";
    cin >> vertices;

    if(vertices <= 0 || vertices > maxVertice) {
        cout << endl << "\tInvalid number of vertices! Must be between 1 and " << maxVertice << "." << endl;
        return 0;
    }

    SetTree(vertices);

    if(SetAdjList(vertices)) {
        cout << endl << "\tAdjacency List set!" << endl;
    }
    else {
        cout << endl << "Invalid input! Adjacency List can only contain 0 or 1." << endl;
        return 0;
    }
    
    DFS(0, vertices);

    ShowSpanningTree(vertices);

    return 0;
}