#include <iostream>
using namespace std;

int count = 0;

struct node {
    int data;
    node* Lchild;
    node* Rchild;
};

node* createNode(int data) {
    node* newNode = new node;
    newNode->data = data;
    newNode->Lchild = nullptr;
    newNode->Rchild = nullptr;
    
    count++;

    cout << endl << "\t* New Node (node-" << count << ") Created!" << endl;
    cout << endl << "\t* " << data << " Added to Node-" << count << "!" << endl;

    return newNode;
}

node* heapifyUp(node* &root, node* newNode) {
    if (newNode == nullptr || root == nullptr) {
        return newNode;
    }

    node* parent = root;
    node* current = root;

    while (current != nullptr) {
        
        if (newNode->data < current->data) {
            swap(newNode->data, current->data);
            if (current->Lchild != nullptr && current->Lchild->data == newNode->data) {
                parent = current;
                current = current->Lchild;
            } else {
                current = current->Rchild;
            }
        }
        break;
    }

    return parent;
}

node* createMinHeap(node* &root, int data) {
    if (root == nullptr) {
        root = createNode(data);
    }
    else {
        node* newNode = createNode(data);
        root = heapifyUp(root, newNode);
    }

    return root;
}

void printHeap(node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    printHeap(root->Lchild);
    printHeap(root->Rchild);
}

int main() {
    node* root = nullptr;

    int values[] = {15, 25, 10, 30, 20, 40, 50, 5};

    cout << "\t* Inserting nodes into Min-Heap..." << endl;
    
    for (int i = 0; i < 8; i++) {
        int value = values[i];
        cout << "\t* Inserting " << value << " into the heap." << endl;
        root = createMinHeap(root, value);
        cout << "\t* Min-Heap after insertion: ";
        printHeap(root);
        cout << endl;
    }

    cout << endl << "\t* Final Min-Heap: ";
    printHeap(root);
    cout << endl;

    cout << endl << "\t* Program returned!" << endl;

    return 0;
}