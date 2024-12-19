// ALGO-FINAL-LT-8-2-GraphsAdjListLinkedList

#include <iostream>
using namespace std;

struct Node {
    int data;
    int weight;
    Node* next;

    Node(int d, int w) {
        data = d;
        weight = w;
        next = nullptr;
    }
};

void InitializeAdjList(Node* adjList[], int vertices) {
    for(int i=0; i<vertices; i++) {
        adjList[i] = nullptr;
    }
}

int InputVertices() {
    int vertices;
    cout << endl << "Enter total vertices: ";
    cin >> vertices;
    return vertices;
}
int InputSource() {
    int source;
    cout << "Enter source: ";
    cin >> source;
    return source;
}
int InputDestination() {
    int destination;
    cout << "Enter destination: ";
    cin >> destination;
    return destination;
}
int InputWeight() {
    int weight;
    cout << "Enter weight: ";
    cin >> weight;
    return weight;
}


void AddEdge(Node* adjList[], int source, int destination, int weight) {
    Node* newNode = new Node(destination, weight);
    newNode->next = adjList[source];
    adjList[source] = newNode;
}

void ShowGraph(Node* adjList[], int vertices, string type) {
    
    cout << endl << "Showing Graph (" << type << ")-" << endl;

    for (int i = 0; i < vertices; i++) {

        cout << "Vertex " << i << ": ";
        Node* temp = adjList[i];
        while (temp != nullptr) {
            cout << temp->data;
            if (temp->weight != 0) {
                cout << "(" << temp->weight << ")";
            }
            cout << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;

    }

}

int main() {
    char op;

    while(true) {

        cout << endl << "1. Directed Graph" << endl
                    << "2. Undirected Graph" << endl
                    << "3. Directed Weighted Graph" << endl
                    << "4. Undirected Weighted Graph" << endl
                    << "5. Exit" << endl;
        cout << "Select your graph: ";
        cin >> op;

        if(op == '1') {
            int vertices = InputVertices();

            Node* adjList[vertices];
            InitializeAdjList(adjList, vertices);

            for(int i=0; i<vertices; i++) {
                cout << endl << "Vertice-" << i+1 << endl;
                int source = InputSource();
                int destination = InputDestination();
                AddEdge(adjList, source, destination, 1);
            }

            ShowGraph(adjList, vertices, "Directed");
        }
        else if(op == '2') {
            int vertices = InputVertices();

            Node* adjList[vertices];
            InitializeAdjList(adjList, vertices);

            for(int i=0; i<vertices; i++) {
                cout << endl << "Vertice-" << i+1 << endl;
                int source = InputSource();
                int destination = InputDestination();
                AddEdge(adjList, destination, source, 1);
            }
            
            ShowGraph(adjList, vertices, "Undirected");
        }
        else if(op == '3') {
            int vertices = InputVertices();

            Node* adjList[vertices];
            InitializeAdjList(adjList, vertices);

            for(int i=0; i<vertices; i++) {
                cout << endl << "Vertice-" << i+1 << endl;
                int source = InputSource();
                int destination = InputDestination();
                int weight = InputWeight();
                AddEdge(adjList, source, destination, weight);
            }

            ShowGraph(adjList, vertices, "Directed Weighted");
        }
        else if(op == '4') {
            int vertices = InputVertices();

            Node* adjList[vertices];
            InitializeAdjList(adjList, vertices);

            for(int i=0; i<vertices; i++) {
                cout << endl << "Vertice-" << i+1 << endl;
                int source = InputSource();
                int destination = InputDestination();
                int weight = InputWeight();
                AddEdge(adjList, destination, source, weight);
            }

            ShowGraph(adjList, vertices, "Undirected Weighted");
        }
        else if(op == '5') {
            cout << endl << "Exited" << endl;
            break;
        }
        else{
            cout << endl << "INAVLID INPUT" << endl;
        }

    }
}