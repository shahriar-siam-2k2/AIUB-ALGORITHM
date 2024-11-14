//ALGO-MID-LT-4-2-CountingSort

#include <iostream>
#include <conio.h>
using namespace std;

void ShowData(int arr[], int size) {
    cout << "Array Elements: ";
    for(int i=0 ; i<size ; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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

    cout << endl << "Setting Count Array:" << endl;
    ShowData(countArr, range);

    cout << endl << "Count Array Operation-1:" << endl;
    for(int i = 0; i < n; i++) {
        countArr[arr[i] - min]++;
        ShowData(countArr, range);
    }

    cout << endl << "Count Array Operation-2:" << endl;
    for(int i = 1; i < range; i++) {
        countArr[i] += countArr[i - 1];
        ShowData(countArr, range);
    }

    int sortArr[n] = {0};

    cout << endl << "Setting Sort Array:" << endl;
    ShowData(sortArr, n);
    for(int i = n - 1; i >= 0; i--) {
        sortArr[countArr[arr[i] - min] - 1] = arr[i];
        countArr[arr[i] - min]--;
        ShowData(sortArr, n);
    }

    cout << endl << "Copying Sort Array to Main Array:" << endl;
    ShowData(arr, n);
    for(int i = 0; i < n; i++) {
        arr[i] = sortArr[i];
        ShowData(arr, n);
    }
    
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

    cout << "Enter " << n << " integers: ";
    for(int i=0; i<n; i++) {
        cin >> arr[i];
    }

    CountingSort(arr, n);

    cout << endl << "Sorted array:" << endl;
    ShowData(arr, n);

    cout << endl << "Press any key to close...";
    getch();
    cout << endl;

    delete[] arr;

    return 0;
}
