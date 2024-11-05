#include <iostream>
using namespace std;

int main() {
    // Variables to store maximum credit, credit used, and available credit
    double maxCredit, creditUsed, availableCredit;

    // Prompt user for the customer's maximum credit
    cout << "Enter the customers maximum credit: ";
    cin >> maxCredit;

    // Prompt user for the amount of credit used
    cout << "Enter the amount of credit used by the customer: ";
    cin >> creditUsed;

    // Calculate available credit
    availableCredit = maxCredit - creditUsed;

    // Display the available credit
    cout << "Customers available credit: $" << availableCredit << endl;

    return 0;
}
