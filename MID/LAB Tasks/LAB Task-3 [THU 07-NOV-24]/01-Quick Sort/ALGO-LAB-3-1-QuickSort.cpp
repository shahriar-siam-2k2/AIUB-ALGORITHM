//ALGO-LAB-3-1-Quick Sort

#include <iostream>
#include <conio.h>
using namespace std;

void SwapVal(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
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

int main() {
    int n;

    cout << endl << "Enter the size of the array: ";
    cin >> n;

    if(n <= 0) {
        cout << endl << "Size should be greater than or equal 1.";
        
        cout << endl << endl << "Press any key to close...";

        getch();

        cout << endl;

        return 0;
    }

    int *arr = new int[n];
    int firstIndex = 0, lastIndex = n-1;

    cout << endl << "Enter " << n << " integers: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    QuickSort(arr, firstIndex, lastIndex);

    cout << endl << "Quick sorted elements: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    }

    delete[] arr;
    
    cout << endl << endl << "Press any key to close...";

    getch();

    cout << endl;

    return 0;
}