#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int number, sum = 0, numOfDigits = 0;

    cout << "Enter a number: ";
    cin >> number;

    int temp = number;
    
    while (temp != 0) {
        numOfDigits++;
        temp /= 10;
    }

    temp = number;
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, numOfDigits);
        temp /= 10;
    }

    if (sum == number) {
        cout << number << " is an Armstrong number." << endl;
    } else {
        cout << number << " is not an Armstrong number." << endl;
    }

    return 0;
}
