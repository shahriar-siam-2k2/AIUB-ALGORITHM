//ALGO-MID-LT-4-6-ArrayFunctions2

#include <iostream>
#include <conio.h>
using namespace std;

void SwapVal(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void combineArray(int arr1[], int size1, int arr2[], int size2, int result[]) {

    for(int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    for(int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }
}

void insertElement(int arr[], int &size, int element) {

    arr[size] = element;
    size++;

}

void findMinMax(int arr[], int size, int &min, int &max) {

    min = arr[0];
    max = arr[0];
    for (int i = 1; i < size; i++) {

        if (arr[i] < min) {
            min = arr[i];
        }
        if (arr[i] > max) {
            max = arr[i];
        }

    }

}

int Partition(int arr[], int firstIndex, int lastIndex) {

    int pivotVal = arr[lastIndex], pivotIndex = firstIndex;

    for(int j=firstIndex; j<lastIndex; j++) {

        if(arr[j] <= pivotVal) {

            SwapVal(&arr[pivotIndex], &arr[j]);
            pivotIndex++;

        }

    }

    SwapVal(&arr[pivotIndex], &arr[lastIndex]);

    return pivotIndex;

}
void QuickSort(int arr[], int firstIndex, int lastIndex) {

    if(firstIndex >= lastIndex) {
        return;
    }

    int pivotIndex = Partition(arr, firstIndex, lastIndex);
    QuickSort(arr, firstIndex, pivotIndex-1);
    QuickSort(arr, pivotIndex+1, lastIndex);

}

void ShowData(int arr[], int size) {

    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

int main() {
    int size1, size2, combinedSize, value, min, max;

    cout << endl << "Enter the size of the array-1: ";
    cin >> size1;

    if(size1 <= 0) {
        cout << endl << "Value of size should be greater than or equal 1.";

        cout << endl << "Press any key to close...";
        getch();

        cout << endl;

        return 0;
    }

    int *arr1 = new int[size1];

    cout << "Enter " << size1 << " elements of the array-1: ";
    for(int i=0; i<size1; i++) {
        cin >> arr1[i];
    }

    cout << endl << "Enter the size of the array-2: ";
    cin >> size2;

    if(size2 <= 0) {
        cout << endl << "Value of size should be greater than or equal 1.";

        cout << endl << "Press any key to close...";
        getch();

        cout << endl;

        return 0;
    }

    int *arr2 = new int[size2];
    
    cout << "Enter " << size2 << " elements of the array-2: ";
    for(int i=0; i<size2; i++) {
        cin >> arr2[i];
    }

    combinedSize = size1 + size2;
    int *combinedArr = new int[combinedSize+1];

    combineArray(arr1, size1, arr2, size2, combinedArr);

    cout << endl << "Combined array: ";
    ShowData(combinedArr, combinedSize);

    cout << endl << "Enter new element to insert at the last of combined array: ";
    cin >> value;

    insertElement(combinedArr, combinedSize, value);

    cout << endl << "Array after insertion: ";
    ShowData(combinedArr, combinedSize);

    findMinMax(combinedArr, combinedSize, min, max);

    QuickSort(combinedArr, 0, combinedSize-1);

    cout << endl << "Sorted array: ";
    ShowData(combinedArr, combinedSize);

    cout << endl << "Smallest element: " << min;
    cout << endl << "Largest element: " << max;

    cout << endl << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}
