//ALGO-FINAL-LT-7-1-BinaryTree

#include <iostream>
#include <conio.h>
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


int main() {
    node* root = nullptr;

    createNode(3);

    cout << endl << "\t* Program returned!" << endl;
    cout << endl << "Press any key to exit...";

    getch();

    return 0;
}