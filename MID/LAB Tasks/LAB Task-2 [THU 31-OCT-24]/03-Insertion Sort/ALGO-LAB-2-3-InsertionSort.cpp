//ALGO-LAB-2-3: Insertion Sort

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

    cout << endl << "Sorted values: " << endl;
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }

    cout << endl << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}