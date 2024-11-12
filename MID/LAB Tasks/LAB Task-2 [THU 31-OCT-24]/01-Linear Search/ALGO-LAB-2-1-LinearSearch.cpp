//ALGO-LAB-2-1: Linear Search

#include <iostream>
#include <conio.h>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    int index=-1;

    for(int i=0; i<size; i++) {
        if(arr[i] == target) {
            index = i;
            break;
        }
    }

    return index;
}

int main() {
    int size, value, foundIndex;

    cout << endl << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements of the array: ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    cout << endl << "Enter the value you want to search: ";
    cin >> value;

    foundIndex = linearSearch(arr, size, value);

    if(foundIndex != -1) {
        cout << endl << value << " found at " << foundIndex << " no index." << endl;
    }
    else {
        cout << endl << value << " not found! " << endl;
    }

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}