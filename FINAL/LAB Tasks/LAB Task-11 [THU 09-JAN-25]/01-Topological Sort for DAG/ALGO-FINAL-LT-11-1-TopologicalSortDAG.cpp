// ALGO-FINAL-LT-11-1-TopologicalSortDAG

#include <iostream>
using namespace std;

const int maxNode = 100;
int sortCount = 0;
int totalNode;
int adjList[maxNode][maxNode];
int indegree[maxNode];
int sorted[maxNode];
bool visited[maxNode];

void SetGraph(int nodes) {
    totalNode = nodes;
    for(int i=0; i<totalNode; i++) {
        for(int j=0; j<totalNode; j++) {
            adjList[i][j] = 0;
        }
        indegree[i] = 0;
        visited[i] = false;
    }
    cout << endl << "\tGraph Initialized!" << endl;
}

bool AddEdge(int u, int v) {
    if(adjList[u][v] == 0) {
        adjList[u][v] = 1;
        indegree[v]++;
        return true;
    }
    return false;
}

bool TopologicalSort() {
    for(int i=0; i<totalNode; i++) {
        int curr = -1;

        cout << endl << "Nodes with in-degree 0: ";
        for (int j = 0; j < totalNode; j++) {
            if (!visited[j] && indegree[j] == 0) {
                cout << j << " ";
            }
        }
        cout << endl;

        for(int j=0; j<totalNode; j++) {
            if(!visited[j] && indegree[j] == 0) {
                curr = j;
                break;
            }
        }

        if(curr == -1) {
            return false;
        }

        visited[curr] = true;
        sorted[sortCount++] = curr;

        for(int j=0; j<totalNode; j++) {
            if(adjList[curr][j] == 1) {
                indegree[j]--;
            }
        }
    }
    return true;
}

void ShowSort() {
    cout << endl << "Topological Sort: ";
    for(int i=0; i<sortCount; i++) {
        cout << sorted[i] << " ";
    }
    cout << endl;
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

    cout << endl << "Enter the starting point and ending point of following edges-" << endl;

    int i=0;
    while(i<edges) {
        cout << endl << "Edge-" << i+1 << ": ";
        cin >> u >> v;

        if(u < 0 || u >= nodes || v < 0 || v >= nodes) {
            cout << endl << "\tInvalid edge! Nodes should be between 0 and " << nodes - 1 << "." << endl;
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

    if(TopologicalSort()) {
        cout << endl << "\tSuccessful Topological Sort Apply!" << endl;
        ShowSort();
    }
    else {
        cout << endl << "\tFailed to apply topological sort. Cycle in the graph detected!" << endl;
    }

    return 0;
}