#include <iostream>
#include <climits>
using namespace std;

const int MAX_NODES = 100;

int graph[MAX_NODES][MAX_NODES];
bool visited[MAX_NODES];
int dist[MAX_NODES];

void InitializeGraph(int nodes) {
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            graph[i][j] = 0;
        }
    }
}

int FindMinDistance(int nodes) {
    int minDistance = INT_MAX;
    int minIndex = -1;

    for (int i = 0; i < nodes; i++) {
        if (!visited[i] && dist[i] < minDistance) {
            minDistance = dist[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void dijkstra(int nodes, int source, int destination) {
    for (int i = 0; i < nodes; i++) {
        dist[i] = INT_MAX;
        visited[i] = false;
    }

    dist[source] = 0;

    for (int i = 0; i < nodes - 1; i++) {
        int u = FindMinDistance(nodes);

        if (u == -1) {
            break;
        }

        visited[u] = true;

        for (int v = 0; v < nodes; v++) {
            if (!visited[v] && graph[u][v] != 0 && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
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
    int nodes, edges;
    cout << "Enter the number of nodes: ";
    cin >> nodes;

    cout << "Enter the number of edges: ";
    cin >> edges;

    InitializeGraph(nodes);

    cout << "Enter the edges (source destination weight):" << endl;
    for (int i = 0; i < edges; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u][v] = w;
        graph[v][u] = w;
    }

    int source, destination;
    cout << "Enter the source node: ";
    cin >> source;
    cout << "Enter the destination node: ";
    cin >> destination;

    dijkstra(nodes, source, destination);

    return 0;
}