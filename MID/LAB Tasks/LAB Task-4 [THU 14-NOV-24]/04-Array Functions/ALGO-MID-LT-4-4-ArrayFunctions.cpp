//ALGO-MID-LT-4-3-FiveSorts

#include <iostream>
#include <conio.h>
using namespace std;

void ResizeArray(int*& arr, int& maxSize) {

    int newMaxSize = maxSize * 2;
    int* newArr = new int[newMaxSize];

    for(int i = 0; i < maxSize; i++) {
        newArr[i] = arr[i];
    }

    cout << endl << "Array size increased!";
    cout << endl << "Before size: " << maxSize;
    cout << endl << "After size: " << newMaxSize << endl;

    delete[] arr;
    arr = newArr;
    maxSize = newMaxSize;

}

void InsertAtFirst(int*& arr, int size, int maxSize, int value) {

    if(size >= maxSize) {
        ResizeArray(arr, maxSize);
    }

    for (int i = size; i > 0; i--) {
        arr[i] = arr[i - 1];
    }

    arr[0] = value;
    size++;

}

void InsertAtMiddle(int*& arr, int size, int maxSize, int value) {

    if (size >= maxSize) {
        ResizeArray(arr, maxSize);
    }

    int mid = size / 2;

    for (int i = size; i > mid; i--) {
        arr[i] = arr[i - 1];
    }

    arr[mid] = value;
    size++;

}

int LinearSearch(int*& arr, int size, int target) {

    for(int i=0; i<size; i++) {

        if(arr[i] == target) {
            return i;
        }

    }
    return -1;
    
}

void ShowData(int arr[], int size) {

    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {
    int size, value;

    cout << endl << "Enter the size of the array: ";
    cin >> size;

    if(size <= 0) {
        cout << endl << "Value of size should be greater than or equal 1.";

        cout << endl << "Press any key to close...";
        getch();

        cout << endl;

        return 0;
    }

    int maxSize = size;
    int *arr = new int[size];

    cout << "Enter " << size << " elements of the array: ";
    for(int i=0; i<size; i++) {
        cin >> arr[i];
    }

    cout << endl << "Original array: ";
    ShowData(arr, size);

    cout << endl << "Enter new value to insert at first position: ";
    cin >> value;

    InsertAtFirst(arr, size, maxSize, value);
    cout << endl << "After inserting at first position: ";
    ShowData(arr, size);

    cout << endl << "Enter new value to insert at middle position: ";
    cin >> value;

    InsertAtMiddle(arr, size, maxSize, value);
    cout << endl << "After inserting at middle position: ";
    ShowData(arr, size);

    cout << endl << "Enter the value you want to search : ";
    cin >> value;

    int index = LinearSearch(arr, size, value);

    if(index != -1) {
        cout << endl << value << " found at index: " << index << endl;
    }
    else {
        cout << endl << value << " not found in the array." << endl;
    }

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    delete[] arr;

    return 0;
}