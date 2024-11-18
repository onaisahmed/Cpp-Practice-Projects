#include <iostream>
using namespace std;

int main() {
    int rows = 5;

    // Upper half of the diamond
    for (int i = 1; i <= rows; i++) {
        // Print spaces
        for (int j = i; j < rows; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    // Lower half of the diamond
    for (int i = rows - 1; i >= 1; i--) {
        // Print spaces
        for (int j = rows; j > i; j--) {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= (2 * i - 1); k++) {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}
