//ALGO-FINAL-LT-7-4-BinarySearchTree

#include <iostream>
#include <conio.h>
using namespace std;

int c = 0;

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

    c++;

    cout << endl << "\t* New Node (node-" << c << ") Created!" << endl;
    cout << endl << "\t* " << data << " Added to Node-" << c << "!" << endl;

    return newNode;
}

node* createBST(node* &root, int data) {
    if(root == nullptr) {
        root = createNode(data);
    }
    else {
        if(data < root->data) {
            root->Lchild = createBST(root->Lchild, data);
        }
        else if(data > root->data) {
            root->Rchild = createBST(root->Rchild, data);
        }
        else {
            cout << endl << "\t* " << data << " already exists!" << endl;
        }
    }

    return root;
}

void preOrder(node* root) {
    if(root != nullptr) {
        cout << root->data << endl;
        preOrder(root->Lchild);
        preOrder(root->Rchild);
    }
}
void inOrder(node* root) {
    if(root != nullptr) {
        inOrder(root->Lchild);
        cout << root->data << endl;
        inOrder(root->Rchild);
    }
}
void postOrder(node* root) {
    if(root != nullptr) {
        postOrder(root->Lchild);
        postOrder(root->Rchild);
        cout << root->data << endl;
    }
}

bool searchBST(node* root, int ref) {
    if(root != nullptr) {
        if(ref < root->data) {
            return searchBST(root->Lchild, ref);
        }
        else if(ref > root->data) {
            return searchBST(root->Rchild, ref);
        }
        else {
            return true;
        }
    }
    else {
        return false;
    }
}

int main() {
    int* data = new int;
    char* op = new char;
    node* root = nullptr;

    while(true) {
        cout << endl << endl << "\tBinary Search Tree (BST)" << endl;

        cout << endl << "1. Add Data." << endl
                    << "2. Traverse Tree." << endl
                    << "3. Search Data." << endl
                    << "4. Exit." << endl;
        cout << "Choose operation: ";
        cin >> *op;

        if(*op == '1') {
            cout << endl << "Enter data-" << (c+1) << ": ";
            cin >> *data;
            createBST(root, *data);
        }
        else if(*op == '2') {
            if(root != nullptr) {
                while(true) {
                    cout << endl << endl << "\tTraverse Tree" << endl;

                    cout << endl << "1. Pre-Order." << endl
                                << "2. In-Order." << endl
                                << "3. Post-Order." << endl
                                << "4. Back." << endl;
                    cout << "Choose operation: ";
                    cin >> *op;
                    if(*op == '1') {
                        cout << endl << "Traversing BST in Pre-Order:" << endl;
                        preOrder(root);
                        break;
                    }
                    else if(*op == '2') {
                        cout << endl << "Traversing BST in In-Order:" << endl;
                        inOrder(root);
                        break;
                    }
                    else if(*op == '3') {
                        cout << endl << "Traversing BST in Post-Order:" << endl;
                        postOrder(root);
                        break;
                    }
                    else if(*op == '4') {
                        break;
                    }
                    else {
                        cout << endl << "\t* Invalid operation!" << endl;
                    }
                }
            }
            else {
                cout << endl << "\t* Tree is empty!" << endl;
            }
        }
        else if(*op == '3') {
            if(root != nullptr) {
                cout << endl << "Enter data to search: ";
                cin >> *data;

                if(searchBST(root, *data)) {
                    cout << endl << "\t* " << *data << " Found!" << endl;
                }
                else {
                    cout << endl << "\t* " << *data << " Not Found!" << endl;
                }
            }
            else {
                cout << endl << "\t* Tree is empty!" << endl;
            }
        }
        else if(*op == '4') {
            break;
        }
        else {
            cout << endl << "\t* Invalid operation!" << endl;
        }
    }

    delete data;
    delete op;

    cout << endl << "\t* Program returned!" << endl;
    cout << endl << "Press any key to exit...";

    getch();

    return 0;
}