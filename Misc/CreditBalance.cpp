#include <iostream>
using namespace std;

int main() {
    double maxCredit, creditUsed, availableCredit;

    cout << "Enter the customers maximum credit: $";
    cin >> maxCredit;

    cout << "Enter the amount of credit used by the customer: $";
    cin >> creditUsed;

    // Calculating available credit here
    availableCredit = maxCredit - creditUsed;

    cout << "Customers available credit: $" << availableCredit << endl;

    return 0;
}
