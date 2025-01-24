#include <iostream>
#include <climits>
using namespace std;

const int MAX_NODES = 100;
const int INF = INT_MAX;

int graph[MAX_NODES][MAX_NODES];

void InitializeGraph(int nodes) {
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (i == j)
                graph[i][j] = 0;
            else
                graph[i][j] = INF;
        }
    }
}

void FloydWarshall(int nodes) {
    int dist[MAX_NODES][MAX_NODES];

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    for (int k = 0; k < nodes; k++) {
        for (int i = 0; i < nodes; i++) {
            for (int j = 0; j < nodes; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    cout << "Shortest distances between every pair of vertices:" << endl;
    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < nodes; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
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

    FloydWarshall(nodes);

    return 0;
}