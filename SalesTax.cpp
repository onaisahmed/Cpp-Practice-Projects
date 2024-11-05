#include <iostream>
using namespace std;

int main() {
    double retailPrice, taxRate, salesTax, totalSale;

    // Prompt user for retail price
    cout << "Enter the retail price of the item: ";
    cin >> retailPrice;

    // Prompt user for sales tax rate
    cout << "Enter the sales tax rate (in percentage): ";
    cin >> taxRate;

    // Calculate sales tax and total sale
    salesTax = retailPrice * (taxRate / 100);
    totalSale = retailPrice + salesTax;

    // Display results
    cout << "Sales Tax: $" << salesTax << endl;
    cout << "Total Sale: $" << totalSale << endl;

    return 0;
}
