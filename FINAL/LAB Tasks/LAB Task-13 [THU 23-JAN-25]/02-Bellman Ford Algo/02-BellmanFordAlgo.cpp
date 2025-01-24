#include <iostream>
#include <climits>
using namespace std;

const int MAX_EDGES = 1000;

struct Edge {
    int source, destination, weight;
};

Edge edges[MAX_EDGES];
int dist[MAX_EDGES];

void InitializeGraph(int edgesCount) {
    for (int i = 0; i < edgesCount; i++) {
        edges[i].source = 0;
        edges[i].destination = 0;
        edges[i].weight = 0;
    }
}

void BellmanFord(int nodes, int edgesCount, int source, int destination) {
    for (int i = 0; i < nodes; i++) {
        dist[i] = INT_MAX;
    }
    dist[source] = 0;

    for (int i = 0; i < nodes - 1; i++) {
        for (int j = 0; j < edgesCount; j++) {
            int u = edges[j].source;
            int v = edges[j].destination;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }

    for (int j = 0; j < edgesCount; j++) {
        int u = edges[j].source;
        int v = edges[j].destination;
        int w = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            cout << "Graph contains a negative weight cycle." << endl;
            return;
        }
    }

    if (dist[destination] == INT_MAX) {
        cout << "No path exists from node " << source << " to node " << destination << "." << endl;
    }
    else {
        cout << "Shortest path from node " << source << " to node " << destination << " is " << dist[destination] << "." << endl;
    }
}

int main() {
    int nodes, edgesCount;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edgesCount;

    InitializeGraph(edgesCount);

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < edgesCount; i++) {
        cin >> edges[i].source >> edges[i].destination >> edges[i].weight;
        edges[edgesCount + i] = {edges[i].destination, edges[i].source, edges[i].weight};
    }

    int source, destination;
    cout << "Enter the source node: ";
    cin >> source;
    cout << "Enter the destination node: ";
    cin >> destination;

    BellmanFord(nodes, edgesCount, source, destination);

    return 0;
}