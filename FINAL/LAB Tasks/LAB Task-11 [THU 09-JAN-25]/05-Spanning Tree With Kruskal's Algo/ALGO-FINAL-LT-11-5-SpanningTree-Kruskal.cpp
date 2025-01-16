// ALGO-FINAL-LT-11-5-SpanningTree-Kruskal

#include <iostream>
using namespace std;

struct Edge {
    int src, dest, weight;
};

const int maxVertice = 100;
int totalV, totalE, spTreeC = 0;
Edge edges[maxVertice * maxVertice];
Edge spTree[maxVertice];
int parent[maxVertice], rankV[maxVertice];

void SetTree(int vertices, int edgesC) {
    totalV = vertices;
    totalE = edgesC;
    for(int i=0; i<totalV; i++) {
        parent[i] = i;
        rankV[i] = 0;
    }
    cout << endl << "\tTree Initialized!" << endl;
}

void SetEdges() {
    int src, dest, weight, i=0;
    
    cout << endl << "Enter edge informations-" << endl;
    while(i<totalE) {
        cout << endl << "Edge-" << i+1 << endl;

        cout << "Source: ";
        cin >> src;
        cout << "Destination: ";
        cin >> dest;
        cout << "Weight: ";
        cin >> weight;

        if(src < 0 || src >= totalV || dest < 0 || dest >= totalV) {
            cout << endl << "\tInvalid edge endpoints! Vertices must be between 0 and " << totalV - 1 << "." << endl;
            continue;
        }

        if(weight < 0) {
            cout << endl << "\tError: Edge weight must be non-negative." << endl;
            continue;
        }

        edges[i].src = src;
        edges[i].dest = dest;
        edges[i].weight = weight;
        cout << endl << "\tEdge-" << i+1 << " set!" << endl;

        i++;
    }
}

int FindSet(int v) {
    if(v != parent[v]) {
        parent[v] = FindSet(parent[v]);
    }
    return parent[v];
}

void UnionSets(int u, int v) {
    int rootU = FindSet(u);
    int rootV = FindSet(v);

    if(rootU != rootV) {
        if(rankV[rootU] < rankV[rootV]) {
            parent[rootU] = rootV;
        }
        else if (rankV[rootU] > rankV[rootV]) {
            parent[rootV] = rootU;
        }
        else {
            parent[rootV] = rootU;
            rankV[rootU]++;
        }
    }
}

void KruskalMST() {
    for(int i=0; i<totalE-1; i++) {
        for(int j=0; j<(totalE-i-1); j++) {
            if(edges[j].weight > edges[j+1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    for(int i=0; i<totalE && (spTreeC < totalV-1); i++) {
        Edge currE = edges[i];

        int setU = FindSet(currE.src);
        int setV = FindSet(currE.dest);

        if(setU != setV) {
            spTree[spTreeC++] = currE;
            UnionSets(setU, setV);
        }
    }
}

void ShowMST() {
    cout << endl << "Minimum Spanning Tree:" << endl;
    cout << " Edge \tWeight" << endl;
    for(int i=0; i<spTreeC; i++) {
        cout << spTree[i].src << " - " << spTree[i].dest << " \t  " << spTree[i].weight << endl;
    }
}

int main() {
    int vertices, edgesC;

    cout << endl << "Enter the number of vertices: ";
    cin >> vertices;
    
    if(vertices <= 0 || vertices > maxVertice) {
        cout << endl << "\tInvalid number of vertices! Must be between 1 and " << maxVertice << "." << endl;
        return 0;
    }

    cout << "Enter the number of edges: ";
    cin >> edgesC;

    if(edgesC <= 0 || edgesC > (maxVertice * maxVertice)) {
        cout << endl << "\tInvalid number of edges! Must be between 1 and " << maxVertice * maxVertice << "." << endl;
        return 0;
    }

    SetTree(vertices, edgesC);
    SetEdges();
    KruskalMST();
    ShowMST();

    return 0;
}