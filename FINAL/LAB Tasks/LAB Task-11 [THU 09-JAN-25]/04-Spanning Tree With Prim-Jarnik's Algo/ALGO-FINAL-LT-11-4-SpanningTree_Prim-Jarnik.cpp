// ALGO-FINAL-LT-11-4-SpanningTree_Prim-Jarnik

#include <iostream>
#include <climits>
using namespace std;

const int maxVertice = 100;
int adjList[maxVertice][maxVertice];
int parent[maxVertice];
int key[maxVertice];
int totalV;
bool spTree[maxVertice];

void SetTree(int vertices) {
    totalV = vertices;
    for(int i=0; i<totalV; i++) {
        key[i] = INT_MAX;
        spTree[i] = false;
    }
    cout << endl << "\tTree Initialized!" << endl;
}

void SetAdjList() {
    cout << endl << "Enter the adjacency list (use 0 for no edge):" << endl;
    for (int i=0; i<totalV; i++) {
        for(int j=0; j<totalV; j++) {
            cin >> adjList[i][j];
        }
    }
    cout << endl << "\tAdjacency List set!" << endl;
}

int FindMinKey() {
    int min = INT_MAX, minIndex;

    for(int i=0; i<totalV; i++) {
        if (!spTree[i] && key[i] < min) {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void PrimMST() {
    key[0] = 0;
    parent[0] = -1;

    for(int i=0; i<totalV-1; i++) {
        int minIndex = FindMinKey();
        spTree[minIndex] = true;

        for(int j=0; j<totalV; j++) {
            if(adjList[minIndex][j] && !spTree[j] && adjList[minIndex][j] < key[j]) {
                parent[j] = minIndex;
                key[j] = adjList[minIndex][j];
            }
        }
    }
}

void ShowMST() {
    cout << endl << "Minimum Spanning Tree:" << endl;
    cout << " Edge \tWeight" << endl;
    for(int i=1; i<totalV; i++) {
        cout << parent[i] << " - " << i << " \t  " << adjList[i][parent[i]] << endl;
    }
}

int main() {
    int vertices;

    cout << endl << "Enter the number of vertices: ";
    cin >> vertices;

    if(vertices <= 0 || vertices > maxVertice) {
        cout << endl << "\tInvalid number of vertices! Must be between 1 and " << maxVertice << "." << endl;
        return 0;
    }

    SetTree(vertices);
    SetAdjList();    
    PrimMST();
    ShowMST();

    return 0;
}