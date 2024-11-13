//ALGO-LAB-3-3-MultipleSearch-Sort

#include <iostream>
#include <conio.h>
using namespace std;

void SwapVal(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void InsertionSort(int arr[], int size) {
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

void Merge(int arr[], int firstIndex, int midIndex, int lastIndex) {

    int leftArrSize = midIndex - firstIndex + 1;
    int rightArrSize = lastIndex - midIndex;

    int *leftArr = new int[leftArrSize];
    int *rightArr = new int[rightArrSize];

    for(int i=0; i < leftArrSize; i++) {
        leftArr[i] = arr[firstIndex + i];
    }

    for(int i=0; i < rightArrSize; i++) {
        rightArr[i] = arr[midIndex + 1 + i];
    }

    int i = 0, j = 0, k = firstIndex;

    while(i < leftArrSize && j < rightArrSize) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while(i < leftArrSize) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while(j < rightArrSize) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }

    delete[] leftArr;
    delete[] rightArr;

}
void MergeSort(int arr[], int firstIndex, int lastIndex) {
    
    if(firstIndex < lastIndex) {

        int midIndex = (firstIndex + lastIndex) / 2;
        MergeSort(arr, firstIndex, midIndex);
        MergeSort(arr, midIndex + 1, lastIndex);
        Merge(arr, firstIndex, midIndex, lastIndex);

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

bool LinearSearch(int arr[], int size, int target) {
    for(int i=0; i<size; i++) {
        if(arr[i] == target) {
            return true;
        }
    }
    return false;
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

void SearchMessage(bool found, int value) {
    if(found) {
        cout << endl << value << " found!" << endl;
    }
    else {
        cout << endl << value << " not found!" << endl;
    }
}
void ShowData(int arr[], int size) {

    cout << endl << "Data stored in the array: " << endl;
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void SearchMenu(int arr[], int size) {
    char op;
    int value;
    
    while(true) {
        cout << endl << "1. Linear Search" << endl
                << "2. Binary Search" << endl
                << "3. Back" << endl;
        cout << "Choose your option: ";
        cin >> op;

        if(op == '1') {
            cout << endl << "Enter the value you want to search: ";
            cin >> value;

            cout << endl << "Linear Search applied." << endl;
            SearchMessage(LinearSearch(arr, size, value), value);
        }
        else if(op == '2') {
            cout << endl << "Enter the value you want to search: ";
            cin >> value;

            cout << endl << "Binary Search applied." << endl;
            cout << endl << "Sorted data using Quick Sort." << endl;

            QuickSort(arr, 0, size-1);
            SearchMessage(BinarySearch(arr, size, value), value);
        }
        else if(op == '3') {
            cout << endl << "Returned to main menu." << endl;
            return;
        }
        else {
            cout << endl << "INVALID INPUT!" << endl;
        }
    }
}
void SortMenu(int arr[], int size) {
    char op;
    
    while(true) {
        cout << endl << "1. Insertion Sort" << endl
                << "2. Merge Sort" << endl
                << "3. Quick Sort" << endl
                << "4. Back" << endl;
        cout << "Choose your option: ";
        cin >> op;

        if(op == '1') {
            cout << endl << "Insertion Sort applied." << endl;
            InsertionSort(arr, size);
            ShowData(arr, size);
        }
        else if(op == '2') {
            cout << endl << "Merge Sort applied." << endl;
            MergeSort(arr, 0, size-1);
            ShowData(arr, size);
        }
        else if(op == '3') {
            cout << endl << "Quick Sort applied." << endl;
            QuickSort(arr, 0, size-1);
            ShowData(arr, size);
        }
        else if(op == '4') {
            cout << endl << "Returned to main menu." << endl;
            return;
        }
        else {
            cout << endl << "INVALID INPUT!" << endl;
        }
    }
}

int main() {
    int size=0;
    int *arr = new int[size];
    char op;

    while(true) {
        cout << endl << "1. Enter New Data" << endl
                     << "2. Search Data" << endl
                     << "3. Sort Data" << endl
                     << "4. Show Data" << endl
                     << "5. Exit" << endl;
        cout << "Choose your option: ";
        cin >> op;

        if(op == '1') {
            delete[] arr;

            cout << endl << "Enter the size of the array: ";
            cin >> size;

            if(size <= 0) {
                cout << endl << "Value of size should be greater than or equal 1.";
                continue;
            }

            int *arr = new int[size];

            cout << "Enter " << size << " elements of the array: ";
            for(int i=0; i<size; i++) {
                cin >> arr[i];
            }

            cout << endl << "Successfully saved all data to array!" << endl;

            ShowData(arr, size);
        }
        else if(op == '2') {
            if(size > 0) {
                SearchMenu(arr, size);
            }
            else {
                cout << endl << "Empty Array!" << endl;
            }
        }
        else if(op == '3') {
            if(size > 0) {
                SortMenu(arr, size);
            }
            else {
                cout << endl << "Empty Array!" << endl;
            }
        }
        else if(op == '4') {
            if(size > 0) {
                ShowData(arr, size);
            }
            else {
                cout << endl << "Empty Array!" << endl;
            }
        }
        else if(op == '5') {
            cout << endl << "Exited." << endl;
            break;
        }
        else {
            cout << endl << "INVALID INPUT!" << endl;
        }
    }

    cout << endl << "Press any key to close...";

    getch();

    cout << endl;

    delete[] arr;

    return 0;
}