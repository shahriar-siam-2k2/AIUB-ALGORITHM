//ALGO-FINAL-LT-7-5-HuffmanCoding

#include <iostream>
#include <conio.h>
using namespace std;

int alphabetC = 26;
int freqC = 26;

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

void SwapVal(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void PrintCodes(Node* root, string code) {
    if (root == nullptr) {
        return;
    }

    if (root->left == nullptr && root->right == nullptr) {
        cout << root->ch << ": ";

        if (code == "") {
            cout << "(no code required)" << endl;
        }
        else {
            cout << code << endl;
        }
    }

    PrintCodes(root->left, code + "0");
    PrintCodes(root->right, code + "1");
}

Node* CreateNode(char ch, int freq, Node* left = nullptr, Node* right = nullptr) {
    Node* newNode = new Node(ch, freq);
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

Node* CreateHuffmanTree(char chars[], int freqs[], int uniqueC )  {
    Node* nodes[100];
    int size = 0;

    for (int i = 0; i < uniqueC ;  i++) {
        nodes[size++] = CreateNode(chars[i], freqs[i]);
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
            }
            else if (nodes[i]->freq < nodes[min2]->freq) {
                min2 = i;
            }
        }

        Node* left = nodes[min1];
        Node* right = nodes[min2];
        Node* newNode = CreateNode('~', left->freq + right->freq, left, right);

        nodes[min1] = newNode;
        nodes[min2] = nodes[--size];
    }

    return nodes[0];
}

void CountFrequency(const string& str, char chars[], int freqs[], int& uniqueC )  {
    int *freqArray = new int[freqC] {0};

    for (int i = 0; i < str.length(); i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            freqArray[ch - 'a']++;
        }
    }

    for (int i = 0; i < alphabetC; i++) {
        if (freqArray[i] > 0) {
            chars[uniqueC ]  = (char)(i + 'a');
            freqs[uniqueC ]  = freqArray[i];
            uniqueC++;
        }
    }

    delete[] freqArray;
}

int main() {
    string input;
    cout << endl << "Enter the string: ";
    cin >> input;

    char *chars = new char[alphabetC];
    int *freqs = new int[freqC];
    int uniqueC = 0;

    CountFrequency(input, chars, freqs, uniqueC) ;

    Node* root = CreateHuffmanTree(chars, freqs, uniqueC) ;

    cout << endl << "Huffman Codes-" << endl;
    PrintCodes(root, "");

    delete[] chars;
    delete[] freqs;

    cout << endl << "\t* Program returned!" << endl;
    cout << endl << "Press any key to exit...";

    getch();

    return 0;
}