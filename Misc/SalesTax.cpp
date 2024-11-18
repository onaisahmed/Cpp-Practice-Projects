#include <iostream>
using namespace std;

int main() {
    double retailPrice, taxRate, salesTax, totalSale;

    cout << "Enter the retail price of the item: $";
    cin >> retailPrice;

    cout << "Enter the sales tax rate (in percentage): ";
    cin >> taxRate;

    salesTax = retailPrice * (taxRate / 100);
    totalSale = retailPrice + salesTax;

    cout << "Sales Tax: $" << salesTax << endl;
    cout << "Total Sale: $" << totalSale << endl;

    return 0;
}
