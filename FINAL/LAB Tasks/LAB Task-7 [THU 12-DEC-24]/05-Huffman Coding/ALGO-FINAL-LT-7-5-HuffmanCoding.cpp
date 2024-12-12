//ALGO-FINAL-LT-7-5-HuffmanCoding

#include <iostream>
using namespace std;

struct Node {
    int freq;
    Node* left;
    Node* right;

    Node(int f) {
        freq = f;
        left = nullptr;
        right = nullptr;
    }
};

void SwapVal(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintCodes(Node* root, string code) {
    if (!root) {
        return;
    }

    if (!root->left && !root->right) {
        cout << endl << "Leaf Node - Frequency: " << root->freq << ", Code: " << code << endl;
    }

    PrintCodes(root->left, code + "0");
    PrintCodes(root->right, code + "1");
}

Node* CreateNode(int freq, Node* left = nullptr, Node* right = nullptr) {
    cout << endl << "Creating Node - Frequency: " << freq << endl;
    Node* newNode = new Node(freq);
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Node* CreateHuffmanTree(int freqs[], int n) {
    Node* nodes[100];
    int size = 0;

    for (int i = 0; i < n; i++) {
        cout << endl << "Inserting into nodes array - Frequency: " << freqs[i] << endl;
        nodes[size++] = CreateNode(freqs[i]);
    }

    while (size > 1) {
        int min1 = 0, min2 = 1;

        if (nodes[min1]->freq > nodes[min2]->freq) {
            SwapVal(&min1, &min2);
        }
        
        for (int i = 2; i < size; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }

        cout << endl << "Merging nodes - Left Frequency: " << nodes[min1]->freq;
        cout << endl << ", Right Frequency: " << nodes[min2]->freq << endl;

        Node* left = nodes[min1];
        Node* right = nodes[min2];
        Node* newNode = CreateNode(left->freq + right->freq, left, right);

        nodes[min1] = newNode;
        nodes[min2] = nodes[--size];
    }

    return nodes[0];
}

int main() {
    int n;
    cout << endl << "Enter the number of frequencies: ";
    cin >> n;

    int freqs[n];

    cout << endl << "Enter the frequencies:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Frequency " << i + 1 << ": ";
        cin >> freqs[i];
    }

    cout << endl << "Creating Huffman Tree:" << endl;
    Node* root = CreateHuffmanTree(freqs, n);

    cout << endl << "Huffman Codes:" << endl;
    PrintCodes(root, "");

    return 0;
}