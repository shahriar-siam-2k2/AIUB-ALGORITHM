//ALGO-FINAL-LT-7-3-FindCommonCharsNoLCS

#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    string word1, word2;
    char common[26];
    int c=0;

    cout << endl << "Enter word-1: ";
    cin >> word1;

    cout << endl << "Enter word-2: ";
    cin >> word2;

    int i=0;
    while(word1[i] != '\0') {
        int j=0;
        while(word2[j] != '\0') {
            if(word1[i] == word2[j]) {
                common[c] = word1[i];
                c++;
                break;
            }
            j++;
        }
        i++;
    }

    if(c == 0) {
        cout << endl << "No common characters found!" << endl;
    }
    else {
        cout << endl << "Common characters: ";
        for(int i=0; i < c; i++) {
            cout << common[i];
            if(c == (i+1)) {
                cout << "." << endl;
            }
            else {
                cout << ", ";
            }
        }
    }

    cout << endl << endl << "\t* Program returned!" << endl;
    cout << endl << "Press any key to exit...";

    getch();
}