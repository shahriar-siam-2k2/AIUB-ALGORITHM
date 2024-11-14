//  

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

void BubbleSort(int arr[], int size) {

    for(int i=0 ; i < size-1 ; i++) {
        for(int j=0 ; j < size-1 ; j++) {
            if(arr[j] > arr[j+1]) {
                SwapVal(&arr[j], &arr[j+1]);
            }
        }
    }

}

void CountingSort(int arr[], int n) {

    int max = arr[0];
    int min = arr[0];

    for(int i = 1; i < n; i++) {

        if (arr[i] > max) {
            max = arr[i];
        }

        if (arr[i] < min) {
            min = arr[i];
        }

    }

    int range = max - min + 1;
    int countArr[range] = {0};

    for(int i = 0; i < n; i++) {
        countArr[arr[i] - min]++;
    }

    for(int i = 1; i < range; i++) {
        countArr[i] += countArr[i - 1];
    }

    int sortArr[n];

    for(int i = n - 1; i >= 0; i--) {
        sortArr[countArr[arr[i] - min] - 1] = arr[i];
        countArr[arr[i] - min]--;
    }

    for(int i = 0; i < n; i++) {
        arr[i] = sortArr[i];
    }
    
}

void ShowData(int arr[], int size) {

    cout << endl << "Data stored in the array: " << endl;
    for(int i=0; i<size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

}

void SortMenu(int arr[], int size) {
    char op;
    
    while(true) {
        cout << endl << "1. Insertion Sort" << endl
                << "2. Merge Sort" << endl
                << "3. Quick Sort" << endl
                << "4. Bubble Sort" << endl
                << "5. Counting Sort" << endl
                << "6. Back" << endl;
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
            cout << endl << "Bubble Sort applied." << endl;
            BubbleSort(arr, size);
            ShowData(arr, size);
        }
        else if(op == '5') {
            cout << endl << "Counting Sort applied." << endl;
            CountingSort(arr, size);
            ShowData(arr, size);
        }
        else if(op == '6') {
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
                     << "2. Sort Data" << endl
                     << "3. Show Data" << endl
                     << "4. Exit" << endl;
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
                SortMenu(arr, size);
            }
            else {
                cout << endl << "Empty Array!" << endl;
            }
        }
        else if(op == '3') {
            if(size > 0) {
                ShowData(arr, size);
            }
            else {
                cout << endl << "Empty Array!" << endl;
            }
        }
        else if(op == '4') {
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