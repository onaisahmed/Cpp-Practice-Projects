#include <iostream>
using namespace std;

int main() {
    int numberOfBaseballs;
    double costPerBaseball, totalCost;

    cout << "Enter the number of baseballs purchased: ";
    cin >> numberOfBaseballs;

    cout << "Enter the cost of each baseball: $";
    cin >> costPerBaseball;

    // Calculating the total cost here
    totalCost = numberOfBaseballs * costPerBaseball;

    cout << "Total amount spent on baseballs: $" << totalCost << endl;

    return 0;
}
