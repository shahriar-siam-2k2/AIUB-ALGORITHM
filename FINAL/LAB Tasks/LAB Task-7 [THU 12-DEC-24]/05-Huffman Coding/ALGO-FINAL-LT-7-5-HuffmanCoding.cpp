//ALGO-FINAL-LT-7-5-HuffmanCoding

#include <iostream>

using namespace std;

struct Node {
    char ch;
    int freq;
    Node* left;
    Node* right;

    Node(char c, int f) {
        ch = c;
        freq = f;
        left = nullptr;
        right = nullptr;
    }
};

void printCodes(Node* root, string code) {
    if (!root) {
        return;
    }

    if (!root->left && !root->right) {
        cout << root->ch << ": " << code << endl;
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

Node* createNode(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
    Node* newNode = new Node(ch, freq);
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Node* buildHuffmanTree(char chars[], int freqs[], int n) {
    Node* nodes[100];
    int size = 0;

    for (int i = 0; i < n; i++) {
        nodes[size++] = createNode(chars[i], freqs[i]);
    }

    while (size > 1) {
        int min1 = 0, min2 = 1;
        if (nodes[min1]->freq > nodes[min2]->freq) {
            swap(min1, min2);
        }
        for (int i = 2; i < size; i++) {
            if (nodes[i]->freq < nodes[min1]->freq) {
                min2 = min1;
                min1 = i;
            } else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }

        Node* left = nodes[min1];
        Node* right = nodes[min2];
        Node* newNode = createNode('~', left->freq + right->freq, left, right);

        nodes[min1] = newNode;
        nodes[min2] = nodes[--size];
    }

    return nodes[0];
}

int main() {
    int n;
    cout << "Enter the number of characters: ";
    cin >> n;

    char chars[n];
    int freqs[n];

    cout << "Enter the characters and their frequencies:\n";
    for (int i = 0; i < n; i++) {
        cout << "Character " << i + 1 << ": ";
        cin >> chars[i];
        cout << "Frequency of " << chars[i] << ": ";
        cin >> freqs[i];
    }

    Node* root = buildHuffmanTree(chars, freqs, n);

    cout << "Huffman Codes:\n";
    printCodes(root, "");

    return 0;
}