#include <iostream>
using namespace std;

int main() {
    int numberOfBars;
    double earningsPerBar, totalEarnings;

    cout << "Enter the number of candy bars sold: ";
    cin >> numberOfBars;

    cout << "Enter the earnings per candy bar: $";
    cin >> earningsPerBar;

    // Calculating total earnings by taking product of number of bars sold and earnings per bar
    totalEarnings = numberOfBars * earningsPerBar; 

    cout << "Total earnings from candy sale: $" << totalEarnings << endl;

    return 0;
}
