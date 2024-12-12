//ALGO-FINAL-LT-7-2-MinMaxHeap

#include <iostream>
#include <conio.h>
using namespace std;

int count = 0;

struct node {
    int data;
    node* Lchild;
    node* Rchild;
};

void SwapVal(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

node* Heapify(node* &root, node* newNode, bool isMin) {
    if (newNode == nullptr || root == nullptr) {
        return root;
    }

    node* current = root;

    while (current != nullptr) {
        if( (isMin && (newNode->data < current->data)) || (!isMin && (newNode->data > current->data)) ) {
            SwapVal(&newNode->data, &current->data);

            if (current->Lchild == nullptr) {
                current->Lchild = newNode;
                break;
            }
            else if (current->Rchild == nullptr) {
                current->Rchild = newNode;
                break;
            }
            else {
                current = current->Lchild;
            }
        }
        else {
            if (current->Lchild == nullptr) {
                current->Lchild = newNode;
                break;
            }
            else if (current->Rchild == nullptr) {
                current->Rchild = newNode;
                break;
            }
            else {
                current = current->Lchild;
            }
        }
    }

    return root;
}

node* CreateHeap(node* &root, int data, bool isMin) {
    if (root == nullptr) {
        root = createNode(data);
    }
    else {
        node* newNode = createNode(data);
        root = Heapify(root, newNode, isMin);
    }

    return root;
}

void PrintHeap(node* root) {
    if (root == nullptr) {
        return;
    }
    cout << root->data << " ";
    PrintHeap(root->Lchild);
    PrintHeap(root->Rchild);
}

string HeapType(bool isMin) {
    if(isMin) {
        return "Min-Heap";
    }
    else {
        return "Max-Heap";
    }
}

int main() {
    node* root = nullptr;
    int size;
    bool isMin;
    char op;

    cout << endl << "Enter array size: ";
    cin >> size;

    while(true) {
        cout << endl << "1. Min Heap." << endl
                << "2. Max Heap." << endl
                << "Choose your heap: ";
        cin >> op;

        if(op == '1') {
            isMin = true;
            cout << endl << "\t " << HeapType(isMin) << endl;
            break;
        }
        else if(op == '2') {
            isMin = false;
            cout << endl << "\t " << HeapType(isMin) << endl;
            break;
        }
        else {
            cout << endl << "INVALID INPUT!" << endl;
        }
    }

    int *arr = new int[size];
    
    for (int i = 0; i < size; i++) {
        cout << endl << "Enter data-" << i+1 << ": ";
        cin >> arr[i];

        cout << "\t* Inserting " << arr[i] << " into the heap." << endl;
        root = CreateHeap(root, arr[i], isMin);

        cout << endl << HeapType(isMin) << " after insertion: ";
        PrintHeap(root);
        cout << endl;
    }

    cout << endl << "Final " << HeapType(isMin) << ": ";
    PrintHeap(root);
    cout << endl;

    delete[] arr;

    cout << endl << "\t* Program returned!" << endl;
    cout << endl << "Press any key to exit...";

    getch();

    return 0;
}