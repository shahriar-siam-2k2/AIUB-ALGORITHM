//ALGO-LAB-2-2: Binary Search

#include <iostream>
#include <conio.h>
using namespace std;

void insertionSort(int arr[], int size) {
    int key, j;

    for (int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }

        arr[j + 1] = key;
    }
}

bool BinarySearch(int arr[], int size, int value) {
    int midIndex, left = 0, right = size;
    
    while(left <= right) {
        midIndex = (left + right) / 2;
        if(arr[midIndex] == value) {
            return true;
        }
        else if(arr[midIndex] < value) {
            left = midIndex + 1;
        }
        else {
            right = midIndex - 1;
        }
    }

    return false;
}

int main() {
    int size, value;

    cout << endl << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter " << size << " elements of the array: ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    insertionSort(arr, size);

    cout << endl << "Enter the value you want to search: ";
    cin >> value;

    if(BinarySearch(arr, size, value)) {
        cout << endl << value << " found!" << endl;
    }
    else {
        cout << endl << value << " not found!" << endl;
    }

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}