//ALGO-LAB-3-4-Sales

#include <iostream>
#include <conio.h>
using namespace std;

int main() {
    const int items = 10;
    const int days = 10;
    const int maxPairs = 100;
    int totalQuantity = 0;
    int count = 0;
    int quantityArr[items][days];
    int quantity;

    double totalSales = 0;
    double unitPriceArr[items][days];
    double price;

    for(int i = 0; (i < items) && (count < maxPairs); i++) {

        for(int j = 0; (j < days) && (count < maxPairs); j++) {

            while(true) {
                cout << endl << "Enter unit price for item-" << i + 1 << " of day-" << j + 1 << " (0 to 1000): ";
                cin >> price;

                if(price >= 0 && price <= 1000) {
                    unitPriceArr[i][j] = price;
                    break;
                }
                else {
                    cout << "Invalid input! Please enter a value between 0 and 1000!" << endl;
                }
            }

            while(true) {
                cout << "Enter quantity for item-" << i + 1 << " of day-" << j + 1 << " (0 to 1000): ";
                cin >> quantity;

                if(quantity >= 0 && quantity <= 1000) {
                    quantityArr[i][j] = quantity;
                    break;
                }
                else {
                    cout << "Invalid input! Please enter a value between 0 and 1000!" << endl;
                }
            }

            totalSales += unitPriceArr[i][j] * quantityArr[i][j];
            totalQuantity += quantityArr[i][j];
            count++;

            if (count >= maxPairs) {
                break;
            }

        }

        if (count >= maxPairs) {
            break;
        }

    }

    double averageQuantity = (double)totalQuantity / count;

    cout << endl << "Total sales for up to " << count << " pairs: " << totalSales << " Tk" << endl;
    cout << "Average sales quantity: " << averageQuantity << endl;

    cout << endl << "Press any key to close...";
    getch();
    cout << endl;

    return 0;
}